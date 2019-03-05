#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	// Server details
  char server_hostname[]="www.google.com";
  short server_port=80;

	// Client Socket FD
  int sockFdClient;

  // << DNS >>
	// Convert HostName to GenericIpAddress
	int dns_err;
  struct addrinfo *server_ipaddr;
  struct addrinfo server_ipaddr_info;	// prepare a ipaddr with required information tags
  memset(&server_ipaddr_info,0,sizeof(struct addrinfo));
  server_ipaddr_info.ai_family = AF_INET; // (for now just want ipv4Addr)
  if( (dns_err = getaddrinfo(server_hostname, NULL, &server_ipaddr_info, &server_ipaddr)) != 0){
    fprintf(stderr, "getaddrinfo: %s\n",gai_strerror(dns_err));
    exit(1);
  }
	// Convert GenericIpAddr to InetIpAddr
  struct sockaddr_in *server_ipaddr_inet;
  server_ipaddr_inet = (struct sockaddr_in *) server_ipaddr->ai_addr;
  server_ipaddr_inet->sin_port = htons(server_port);

  // << SOCKET >>
	// Open a sockFdClientet 
  if( (sockFdClient = socket(AF_INET, SOCK_STREAM, 0))  < 0){
    perror("sockFdClientet");
    exit(1);
  }
	printf("\nsockFdClient = %d", sockFdClient);

  // << CONNECT >>
	// Connect the opened sockFdClientet to server
  if (connect(sockFdClient, (struct sockaddr *) server_ipaddr_inet, sizeof(*server_ipaddr_inet)) < 0) {
    perror("connect");
    exit(1);
  }

  // Send request to server
	char server_ipaddr_str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &(server_ipaddr_inet->sin_addr), server_ipaddr_str, INET_ADDRSTRLEN);
  char server_req[128];
	sprintf(server_req, "GET /index.html HTTP/1.1\r\nHost: %s\r\n\r\n", server_ipaddr_str);
  if (send(sockFdClient, server_req, strlen(server_req), 0) <= 0) {
    perror("send");
  }

  // Receive/Process the response
  char server_rsp[4096];           //read in 4096 byte chunks
	int read_len;
	int write_len;
  while((read_len = read(sockFdClient, server_rsp, 32)) > 0) {
		printf("\n read_len = %d", read_len);
    //write response to stdout
    if((write_len = write(1, server_rsp, read_len)) < 0) {
      perror("write");
      exit(1);
    }
  }
  if (read_len < 0){
    perror("read");
  }

  // Close the client socket
  close(sockFdClient);

  return 0;
}
