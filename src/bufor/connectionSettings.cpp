#include "connectionSettings.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

ConnectionSettings::ConnectionSettings(std::string nameFile) {
		readSettings(nameFile);
	};

void ConnectionSettings::readSettings(std::string nameFile) {
	
	
	std::fstream fileConf;	// plik z konfiguracją
	fileConf.open( "conf.ini", std::ios::in );
	//otwieram plik z komendami do wyswietlenia
	if( !fileConf.good() ) {
		std::cout << "Nie otwarto pliku z wlasciwosciami" << std::endl;
		exit(1);
	}
	
	std::string tText;
	int pos;
	if (!fileConf.eof()) {		
			getline(fileConf, tText);
			pos = tText.find("=", 0); // szuka '=' od poczatku
			pos++;
			tText = tText.substr(pos, tText.size()-pos);
			pos = tText.find(" ", 0); // po tekscie spacja
			if (pos != std::string::npos ) {
				pos = tText.size() - pos;	// teraz pos to dlugosc spacji 
				tText = tText.substr(0, tText.size()-pos);	// od zerowej pozycji
			}
//	std::cout << tText << ":k\n";		
			port = atoi(tText.c_str());
	}else {
		std::cout << "Koniec pliku konfiguracyjnego!\n";
		exit(1);
	}
	
	if (!fileConf.eof()) {		
			getline(fileConf, tText);
			pos = tText.find("=", 0); // szuka '=' od poczatku
			pos++;
			tText = tText.substr(pos, tText.size()-pos);
			pos = tText.find(" ", 0); // po tekscie spacja
			if (pos != std::string::npos ) {
				pos = tText.size() - pos;	// teraz pos to dlugosc spacji 
				tText = tText.substr(0, tText.size()-pos);	// od zerowej pozycji
			}
//	std::cout << tText << ":k\n";		
			addressIP=tText;
	} else {
		std::cout << "Koniec pliku konfiguracyjnego!\n";
		exit(1);
	}
	
	if (!fileConf.eof()) {		
			getline(fileConf, tText);
			pos = tText.find("=", 0); // szuka '=' od poczatku
			pos++;
			tText = tText.substr(pos, tText.size()-pos);
			pos = tText.find(" ", 0); // po tekscie spacja
			if (pos != std::string::npos ) {
				pos = tText.size() - pos;	// teraz pos to dlugosc spacji 
				tText = tText.substr(0, tText.size()-pos);	// od zerowej pozycji
			}
//	std::cout << tText << ":k\n";		
			logFile=tText;
	}else {
		std::cout << "Koniec pliku konfiguracyjnego!\n";
		exit(1);
	}	
	
	fileConf.close();

}