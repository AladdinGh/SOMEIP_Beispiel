#include "vehicle.h"
#include <string>



std::shared_ptr<vsomeip::application> app; 
std::mutex mutex;
std::condition_variable _condition;



c_vehicle::c_vehicle():  _Id("1") , _Vin("PF_AG_690"), _IP("192.168.10.1")
{
}
c_vehicle::c_vehicle(std::string a , std::string str, std::string IP):  _Id(a) , _Vin(str), _IP(IP)
{
}
c_vehicle::~c_vehicle(){}


void c_vehicle::display_car()
{
std::cout << "ID : " << _Id << " ; VIN " << _Vin << " ; IP " << _IP << std::endl ; 
}

void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance , bool _is_available)
{
      if (1 == _is_available)
      {
      std::cout << "[Client] : service is " << std::hex << _service << "." << _instance << " available" << std::endl ; 
      }
      else 
      {
      std::cout << "[Client] : service is " << std::hex << _service << "." << _instance << " NOT available" << std::endl ;
      }
      _condition.notify_one();  
}

void c_vehicle::send_msg()
{

}

void sender_thread(c_vehicle& tmp)
{
        std::unique_lock<std::mutex> _lock(mutex);
        _condition.wait(_lock); 
        std::shared_ptr<vsomeip::message> _request; 
        _request = vsomeip::runtime::get()->create_request(); 
        _request->set_service(__SERVICE_ID);
        _request->set_instance(__INSTANCE_ID);
        _request->set_method(_METHOD_ID); 
        std::shared_ptr<vsomeip::payload> _payload; 
        _payload = vsomeip::runtime::get()->create_payload(); 

        std::vector<vsomeip::byte_t> _payload_data;
        std::string str(" ");
        str.append(tmp._Id.c_str()); str.append("  "); 
        str.append( tmp._IP.c_str()); str.append("  "); 
        str.append(tmp._Vin.c_str()); 

        std::cout << "[Client] : data in the client side  " << str << std::endl ; 
        // we got the entire sting , now convert it to something we can put in payload

        std::stringstream ss (str);
        char _char; 
        while(ss >> _char)
        {
          _payload_data.push_back(_char); 
        }
        _payload->set_data(_payload_data); 
        _request->set_payload(_payload);
        // send the request to the server which contains the infos of the car
        app->send(_request,true);  
        std::cout << "[Client] : message sent from client to server " << std::endl; 
}


void on_message(const std::shared_ptr<vsomeip::message> &_response)
{
        std::shared_ptr<vsomeip::payload> _payload = _response->get_payload() ; 
        std::stringstream _ss ; 
        _ss << _payload->get_data() << std::endl ; 
        std::cout << "[CLIENT] : this is invoked by a notification " << _ss.str() << std::endl;
     
}
int main(int argc, char *argv[])
{

      if (argc > 1)
      {
      c_vehicle _ov1(argv[1],argv[2],argv[3]);
      std::string _client_name = "client " + std::string(argv[1]); 
      app = vsomeip::runtime::get()->create_application(_client_name);
      app->init(); 
      app->register_availability_handler(__SERVICE_ID,__INSTANCE_ID,on_availability);
      // Registers the application as client of a service instance
      app->request_service(__SERVICE_ID,__INSTANCE_ID) ; 
      // List of Eventgroup identifiers of the eventgroups
      // that contain the event.
      std::set <vsomeip::eventgroup_t> _event_group; 
      _event_group.insert(_EVENTGROUP_ID); 
      // Registers the application as user of an event or field.
      app->request_event(__SERVICE_ID,__INSTANCE_ID,_EVENT_ID, _event_group,true);
      // Subscribes to an eventgroup                  
      app->subscribe(__SERVICE_ID, __INSTANCE_ID, _EVENTGROUP_ID);
      // when a msg comes , what should we do with it 
      
      app->register_message_handler(__SERVICE_ID, __INSTANCE_ID, vsomeip::ANY_METHOD, on_message); 
      //app->register_message_handler(vsomeip::ANY_SERVICE, vsomeip::ANY_INSTANCE, vsomeip::ANY_METHOD, on_message); 
      // because parameters are copied to the thread and the original reference 
      // has to be passed 
      std::thread sender(sender_thread,std::ref(_ov1)); 
      app->start();
        
      // delete objects
      // delete (_ov1); 
      }
      else
      {
      std::cout << "args please"; 
      }
return(0); 
}

