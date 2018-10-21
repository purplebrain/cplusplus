#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

using namespace std;

string 
getIPAddress (void)
{
	string ipAddress="Unable to get IP Address";
	struct ifaddrs *interfaces = NULL;
	struct ifaddrs *temp_addr = NULL;
	int success = 0;
	// retrieve the current interfaces - returns 0 on success
	success = getifaddrs(&interfaces);
	if (success == 0) {
	    // Loop through linked list of interfaces
	    temp_addr = interfaces;
	    while(temp_addr != NULL) {
	        if(temp_addr->ifa_addr->sa_family == AF_INET) {
	            // Check if interface is en0 which is the wifi connection on the iPhone
	            if(!strcmp(temp_addr->ifa_name, "en0")){
	                ipAddress=inet_ntoa(((struct sockaddr_in*)temp_addr->ifa_addr)->sin_addr);
	            }
	        }
	        temp_addr = temp_addr->ifa_next;
	    }
	}
	
	// Free memory
	freeifaddrs(interfaces);

	return ipAddress;
}

int
main (int argc, char *argv[])
{
	cout << "Wifi interface is : " << getIPAddress() << endl;

	return (0);
}
