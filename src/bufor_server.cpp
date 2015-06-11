#include <iostream>
#include <string>
#include "etc/statement.h"
#include "Connection/connectionSettings.h"
#include <fstream>
#include "Connection/connection.h"
#include <ctime>
#include <vector>
//#include <pthread.h>
//#include <unistd.h>

#define SERWER_PORT 8888
#define SERWER_IP "127.0.0.1"


pthread_mutex_t bufferMutex = PTHREAD_MUTEX_INITIALIZER;

Statement obiekt = Statement();

//void* watekPierwszy( void *_argum);
//void* watekDrugi( void *_argum);
std::vector <std::string> openConf();


int main(int argc, char **argv)
{
	pthread_t id_watku, id_watku_2;                   //identyfikator watku
	

//	pthread_create(&id_watku, NULL, watekPierwszy, &argument);
//	pthread_create(&id_watku_2, NULL, watekDrugi, &argument);
	// .....................
//	pthread_join(id_watku, NULL);
//	pthread_join( id_watku_2, NULL);
	//----------------------------------------------------------------------------
	
	// na sztywno ustawione conf.ini w funkcji readSettings()
	ConnectionSettings conn = ConnectionSettings("conf.ini");
	Connection polaczenie = Connection(SERWER_PORT, SERWER_IP);
	
	polaczenie.bindS();
	polaczenie.listenS();
	polaczenie.acceptS();
	
	
	std::fstream fileSt;	// plik z komendami do wysylania
	fileSt.open( "test.txt", std::ios::in | std::ios::out );
	//otwieram plik z komendami do wyswietlenia
	if( !fileSt.good() ) {
		std::cout << "Nie odczytano pliku z poleceniami!" << std::endl;
		exit(1);
	}
	
	
	std::fstream fileLog;	// plik z komendami do wysylania
	fileLog.open( "log.txt", std::ios::out );
	//otwieram plik z komendami do wyswietlenia
	if( !fileLog.good() ) {
		std::cout << "Nie utworzono pliku do zapisu" << std::endl;
		exit(1);
	}
	
	std::string tTemp, tText;
	time_t czas = 0;   //czas	ctime(& czas)
int kk=0;	
	while( 1 )
    {
		kk++;
		sleep(2);
		// odczyt z pliku
		if (!fileSt.eof()) {		
			getline(fileSt, tText);
			obiekt.insert(tText);	// wstawienie do bufora
		}
		
		if ( obiekt.size() > 0 ) { //&& (obiekt.getText() != "") ) {			// gdy znajduje sie cos w buforze to wysylam
			time( & czas );	// aktualny czas
			
			fileLog << "W[" << ctime( & czas ) << "][" << "adres_ip" << ":" << "port" << "]" << obiekt.getText() << "\n";
			polaczenie.write( obiekt.getText()); // wyslanie
			obiekt.erase();	// usuniecie z bufora			
		}	
	
		if ( kk== 8) {
			std::cout << "kk = 8 ";
			obiekt.insert("dup22");
		}
	//	std::string tTemp = polaczenie.read(); // odebranie komunikatu
		time( & czas );		// aktualny czas
    //  fileLog << "O[" << ctime( & czas ) << "][" << "adres_ip" << ":" << "port" << "]" << obiekt.getText() << "\n";

    }
    
    polaczenie.close();	
	fileSt.close();
	fileLog.close();

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