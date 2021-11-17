#ifndef _vehicle_header
#define _vehicle_header

#include <iomanip>
#include "vsomeip/vsomeip.hpp"
#include <iostream>
#include <string>
#include <condition_variable>
#include <thread>
#include <sstream>


#define __SERVICE_ID 0x1776
#define __INSTANCE_ID 0x5676
#define _METHOD_ID 0x0421
#define _EVENT_ID  0x8778
#define _EVENTGROUP_ID    0x4465


class c_vehicle
{
private :

public : 

	// need these attributes to be sent to the server 
	std::string  _Id; 
	std::string _Vin; 
	std::string _IP; 	
	c_vehicle(); 
	c_vehicle(std::string, std::string,std::string); 
	~c_vehicle();
	void send_msg();  
	void run(c_vehicle* ); 
	void display_car();                         

};  

#endif
