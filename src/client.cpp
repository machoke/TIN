#include <iostream>
#include <string>
#include "Connection/connectionSettings.h"
#include <fstream>
#include "Connection/connection.h"
#include <ctime>
#include "Parser/Parser.h"
#include <signal.h>
#include <unistd.h>

#define SERWER_PORT 8888
#define SERWER_IP "127.0.0.1"


pthread_mutex_t bufferMutex = PTHREAD_MUTEX_INITIALIZER;
ConnectionSettings conn = ConnectionSettings();

Connection* PolaczenieDoWysylki;
Parser *parser;
int CyklicznyCzas;

fstream plikLogow;

void wyslij(string wiadomosc){
	std::cout << "WYSLANO: " << wiadomosc << endl;
	plikLogow << "W[" << PolaczenieDoWysylki->getIP() << ":" << PolaczenieDoWysylki->getPort() << "] " << wiadomosc << endl;
	PolaczenieDoWysylki->writeC(wiadomosc);
}

void Zegar(int a){
	parser->Cyclic();
	alarm(CyklicznyCzas);
}

int main(int argc, char **argv)
{
	std::cout << "hello\n";

	ConnectionSettings *conn;
		if(argc == 2)
			conn = new ConnectionSettings(argv[1]);
		else
			conn = new ConnectionSettings("conf_client.ini");
	Connection polaczenie = Connection(conn->port, conn->addressIP);
	polaczenie.connectC();

	plikLogow.open(conn->logFile.c_str(), ios::out);

	parser = new Parser(conn->rulesFile.c_str());
	PolaczenieDoWysylki = &polaczenie;
	parser->OutsideRespond = wyslij;
	CyklicznyCzas = parser->getCyclicTime();

	signal(SIGALRM, Zegar);
	alarm(CyklicznyCzas);

	delete conn;
	std::string odczyt;
	while( 1 )
    {
		odczyt = polaczenie.readC();
		if(!odczyt.empty()){
			cout << "ODCZYT: " << odczyt << endl;
			plikLogow << "O[" << PolaczenieDoWysylki->getIP() << ":" << PolaczenieDoWysylki->getPort() << "] " << odczyt << endl;
			parser->Ask(odczyt);
		}
    }
    
    polaczenie.close();
    plikLogow.close();
	
	
	
	return 0;
}


