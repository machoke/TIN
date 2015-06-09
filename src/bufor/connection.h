#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>

class Connection {
	struct sockaddr_in serwer;
    int gniazdo;
	int gniazdo_clienta;
	
public:
	Connection(int SERWER_PORT, std::string SERWER_IP);
	~Connection() {};
		
	void write(std::string temp);
	std::string read();
	void writeC(std::string temp);
	std::string readC();		
	void acceptS();
	void listenS();
	void bindS();
	void connectC();
	void close();
	std::string getIP();
	int getPort();
	
};