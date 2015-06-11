#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include "connection.h"
#include <fcntl.h>
#include <unistd.h>

#define MAX_CONNECTION 1
#define MAX_MSG_LEN 4096

Connection::Connection(int SERWER_PORT, std::string SERWER_IP) {
	bzero( & serwer, sizeof( serwer ) );
    
    serwer.sin_family = AF_INET;
    serwer.sin_port = htons( SERWER_PORT );
	
	// adres zapisany jako string na numeryczny
    if( inet_pton( AF_INET, SERWER_IP.c_str(), & serwer.sin_addr ) <= 0 )
    {
        perror( "inet_pton() ERROR" );
        exit( - 1 );
    }
    
    if(( gniazdo = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 )
    {
        perror( "blad socket" );
        exit(-1);
    }
/// - - -	
//	fcntl(gniazdo, F_SETFL, O_NONBLOCK);	
	
	gniazdo_clienta=0;
}
//s
void Connection::bindS() {
	socklen_t len = sizeof( serwer );
    if( bind( gniazdo,( struct sockaddr * ) & serwer, len ) < 0 )
    {
        perror( "bind() ERROR" );
        exit(-1);
    }
}
//s
void Connection::listenS() {
	if( listen( gniazdo, MAX_CONNECTION ) < 0 )
    {
        perror( "listen() ERROR" );
        exit( - 1 );
    }
} 

//s
void Connection::acceptS() {
	    struct sockaddr_in from;
		socklen_t len = sizeof( serwer );
        //int gniazdo_clienta = 0;
        bzero( & from, sizeof( from ) );
        printf( "Waiting for connection...\n" );
        if(( gniazdo_clienta = accept( gniazdo,( struct sockaddr * ) & from, & len ) ) < 0 )
        {
			
            perror( "accept() ERROR" );
       //     continue;
        }
}

//s
std::string Connection::read() {
		char bufor[ MAX_MSG_LEN ];
	    bzero( bufor, sizeof( bufor ) );
        std::string temp;
		
		if(( recv( gniazdo_clienta, bufor, sizeof( bufor ), MSG_DONTWAIT ) ) <= 0 )
        {
			if(!(errno == EAGAIN || errno == EWOULDBLOCK)){
				perror( "recv() ERROR" );
				exit( - 1 );
        	}
        }
		temp=bufor;

		return temp;
}
//s
void Connection::write(std::string temp) {
		char bufor[ MAX_MSG_LEN ];
		bzero( bufor, sizeof( bufor ) );
		
        strcpy( bufor, temp.c_str() );
	
        if(( send( gniazdo_clienta, bufor, strlen( bufor ), 0 ) ) <= 0 )
        {
            perror( "send() ERROR" );
            exit( - 1 );
        }
}

//c
std::string Connection::readC() {
		char bufor[ MAX_MSG_LEN ];
	    bzero( bufor, sizeof( bufor ) );
        std::string temp;
		
		if(( recv( gniazdo, bufor, sizeof( bufor ), /*MSG_DONTWAIT*/0 ) ) <= 0 )
        {
			if(!(errno == EAGAIN || errno == EWOULDBLOCK)){
				perror( "recv() ERROR" );
				close();
				exit( - 1 );
			}
        }
		temp=bufor;

		return temp;
}
//c
void Connection::writeC(std::string temp) {
		char bufor[ MAX_MSG_LEN ];
		bzero( bufor, sizeof( bufor ) );

        strcpy( bufor, temp.c_str() );

        if(( send( gniazdo, bufor, strlen( bufor ), 0 ) ) <= 0 )
        {
            perror( "send() ERROR" );
            exit( - 1 );
        }
}

//c
void Connection::connectC() {
	
    socklen_t len = sizeof( serwer );
    if( connect( gniazdo,( struct sockaddr * ) & serwer, len ) < 0 )
    {
        perror( "connect() ERROR" );
        exit(-1);
    }
	
}

void Connection::close() {
	shutdown( gniazdo, SHUT_RDWR );
	//close(gniazdo);
}

std::string Connection::getIP() {
		;
}
int Connection::getPort() {
		;
}
