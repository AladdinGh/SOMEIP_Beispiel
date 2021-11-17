#ifndef server_header
#define _server_header

#include <string>
#include "vehicle.h"
#include <vector>
#include "vsomeip/vsomeip.hpp"
#include <sstream>
#include <iomanip>
#include <pthread.h>
#include <thread>
#include <string>
#include <chrono>


// device id and message id construct the message id inthe someip packet
#define _SERVICE_ID 0x1776
#define _INSTANCE_ID 0x5676
#define _METHOD_ID 0x0421
#define _EVENT_ID  0x8778
#define _EVENTGROUP_ID  0x4465



// the represenation of the vehicle on the server side 
// no need to a class ?
typedef struct _vehicle_t 
{	
	int _Id; 
	std::string _Vin; 
	std::string _IP; 	
	std::string _Status; 
} s_vehicle ; 

class c_server
{
private : 

std::vector<s_vehicle>* o_vehicles ; 


public : 
c_server(); 
c_server(std::vector<s_vehicle>*); 
~c_server(); 
void display_all_vehicles(); 
void add_vehicle (s_vehicle *); 
void connect(); 
}; 

#endif
