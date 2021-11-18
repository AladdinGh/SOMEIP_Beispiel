#include "server.h"

//global declaration of the app
// TODO : transform it to a class member 
std::shared_ptr<vsomeip::application> app ;
std::mutex mutex;
std::condition_variable condition;



c_server::c_server(): o_vehicles(new std::vector<s_vehicle>){};
c_server::c_server(std::vector<s_vehicle>* v_tmp): o_vehicles(v_tmp){};
c_server::~c_server(){}; 

void c_server::display_all_vehicles()
{
for (unsigned int i = 0 ; i < this->o_vehicles->size() ; i ++)
{

std::cout << "ID : " << this->o_vehicles->at(i)._Id << " ; VIN " << this->o_vehicles->at(i)._Vin 
	  << " ; IP " << this->o_vehicles->at(i)._IP << " ; Status " << this->o_vehicles->at(i)._Status << std::endl ; 
}

}

void c_server::add_vehicle(s_vehicle* v_tmp)
{
this->o_vehicles->push_back(*v_tmp); 

}

void on_message(const std::shared_ptr<vsomeip::message> &_request)
{

   // get the payload
   std::shared_ptr<vsomeip::payload> _payload = _request->get_payload(); 

   
   std::stringstream ss ; 
   ss << _payload->get_data() << std::endl; 

   std::cout << "[Server] : Data received from client " << ss.str();  
   // so we got the wakeup call with car infos , now we send notifications
   // this needs to be done wile the message processing loop is active
   condition.notify_one();
  

}

void send_notification ()
{
    std::unique_lock<std::mutex> _lock(mutex);
    std::vector<vsomeip::byte_t> _payload_data;

    condition.wait(_lock); 
    
    std::shared_ptr< vsomeip::payload > _payload = vsomeip::runtime::get()->create_payload(); 

    std::string str(" ");
    str.append("a software update is due"); str.append("  "); 
    str.append("park aside and update your car"); str.append("  "); 
    
    std::cout << "[Server] : data in the server side  : " << str << std::endl ; 
    // we got the entire string , now convert it to something we can put in payload
    std::stringstream ss (str);
    char _char; 
    while(ss >> _char)
    {
        _payload_data.push_back(_char); 
    }
    _payload->set_data(_payload_data);
    

    for (int j = 0 ; j < 100 ;  j ++)
    {
        std::cout << j << "  server sending notifs" << std::endl ; 

        app->notify(_SERVICE_ID, _INSTANCE_ID, _EVENT_ID, _payload, true );

        // if no sleep time is introduced then the client will receive only the 
        // last message 
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        } 


}

void communicate()
{
    app = vsomeip::runtime::get()->create_application("Server"); 
    app->init(); 
    // Registers a handler for the specified method or event
    app->register_message_handler(_SERVICE_ID, _INSTANCE_ID, _METHOD_ID, on_message); 
    // is this the fct responsible for sending the message of availability ? yes
    // Offers a SOME/IP service instance.
    app->offer_service(_SERVICE_ID, _INSTANCE_ID);

    std::set <vsomeip::eventgroup_t> _event_group; 
    _event_group.insert(_EVENTGROUP_ID); 
    // Offers a SOME/IP event or field
    app->offer_event(_SERVICE_ID,_INSTANCE_ID,_EVENT_ID,_event_group,true); 

;
    std::thread event_sender(send_notification); 

    // start processing the messages 
    app->start();
}

int main()
{
c_server* _oserver = new c_server(); 
communicate(); 
//delete(_oserver); 
return(0); 
}
