#include <iostream>
#include <string>
#include "etc/statement.h"
#include "Connection/connectionSettings.h"
#include <fstream>
#include "Connection/connection.h"
#include <ctime>
#include "Parser/Parser.h"
#include <signal.h>
#include <unistd.h>
//#include <pthread.h>
//#include <unistd.h>

#define SERWER_PORT 8888
#define SERWER_IP "127.0.0.1"


pthread_mutex_t bufferMutex = PTHREAD_MUTEX_INITIALIZER;
ConnectionSettings conn = ConnectionSettings();
Statement obiekt = Statement();

//void* watekPierwszy( void *_argum);
//void* watekDrugi( void *_argum);

Connection* PolaczenieDoWysylki;
Parser *parser;
int CyklicznyCzas;

void wyslij(string wiadomosc){
	std::cout << "WYSLANO: " << wiadomosc << endl;
	PolaczenieDoWysylki->writeC(wiadomosc);
}

void Zegar(int a){
	parser->Cyclic();
	alarm(CyklicznyCzas);
}

int main(int argc, char **argv)
{
	std::cout << "hello\n";
	
	Connection polaczenie = Connection(SERWER_PORT, SERWER_IP);
	polaczenie.connectC();

	std::fstream fileLog;	// plik z komendami do wysylania
	fileLog.open( "log.txt", std::ios::out );
	if( !fileLog.good() ) {
		std::cout << "Nie utworzono pliku do zapisu" << std::endl;
		exit(1);
	}

	parser = new Parser("rulesclient.txt");
	PolaczenieDoWysylki = &polaczenie;
	parser->OutsideRespond = wyslij;
	CyklicznyCzas = parser->getCyclicTime();

	signal(SIGALRM, Zegar);
	alarm(CyklicznyCzas);

	std::string odczyt;
	while( 1 )
    {
		odczyt = polaczenie.readC();
		if(!odczyt.empty()){
			cout << "ODCZYT: " << odczyt << endl;
			parser->Ask(odczyt);
		}
    }
    
    polaczenie.close();
	
//	fileSt.close();
	fileLog.close();
	
	//-------------------------------------------------------------------------------
	
	
	return 0;
}


