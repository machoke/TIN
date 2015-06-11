#include <iostream>
#include <string>
#include "etc/statement.h"
#include "Connection/connectionSettings.h"
#include <fstream>
#include "Connection/connection.h"
#include <ctime>
//#include <pthread.h>
//#include <unistd.h>

#define SERWER_PORT 8888
#define SERWER_IP "127.0.0.1"


pthread_mutex_t bufferMutex = PTHREAD_MUTEX_INITIALIZER;
ConnectionSettings conn = ConnectionSettings();
Statement obiekt = Statement();

//void* watekPierwszy( void *_argum);
//void* watekDrugi( void *_argum);



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

	while( 1 )
    {
		std::string tTemp;

		tTemp = polaczenie.readC();
		std::cout << tTemp << std::endl;
		fileLog << tTemp;

		getline(std::cin, tTemp);
		polaczenie.writeC(tTemp);
    }
    
    polaczenie.close();
	
//	fileSt.close();
	fileLog.close();
	
	//-------------------------------------------------------------------------------
	
	
	return 0;
}




/*

void* watekPierwszy( void *_argum) {
	//string odczytanyKomunikat = odczytaniezPliku();
	std::string odczytanyKomunikat = "test";
	
	while (1) {
	
//	pthread_mutex_lock(&bufferMutex);
//	obiekt.setText(odczytanyKomunikat);	// wstawienie do bufora komunikatow z pliku
//	pthread_mutex_unlock(&bufferMutex);
	
	
	
	std::cout << "test nr. : ";
	
	
	// wyslanie zapis do pliku
	//odebranie polaczenia
	//zapis do pliku
	
	}
//pthread_exit(NULL);
 // return 0;
}

/*
/*
void* watekDrugi(void *_argum) {
	// odczyt z klawiatury
	
	// ewentualnhy zapis do kolejki
//	pthread_mutex_lock(&bufferMutex);
//	obiekt.setText(odczytanyKomunikat);	// wstawienie do bufora komunikatow z pliku
//	pthread_mutex_unlock(&bufferMutex);
 * 
 * 
	
pthread_exit(NULL);
 // return 0;
}

*/
