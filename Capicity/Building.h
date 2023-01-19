#pragma once
#include "Material.h"
#include <string>
#include <map>
using namespace std;

class Building{
public:
	//Variablen
	int leistung;
	int grundpreis;
	char label;			//soll bei Ausdrucken des Plans abgebildet werden
	map<Material*, int> zusammensetzung;
	//Kapitel 3:
	//Entscheidung für Carlas Idee, weil...
	//...Verwaltung der Materialien zu wenig Aufwand ist, um den Overhead
	//einer neuen Klasse zu rechtfertigen
	//...außerdem bleibt die von Carla erwähnte Erweiterbarkeit erhalten


	//Konstruktoren
	Building();
	
	//Methoden
	char getLabel();
	virtual string getZusammensetzung();
	int getGrundpreis();
};

//abgeleitete Gebäude

class Leer : public Building {
public:
	Leer();
};

class Wasserkraftwerk : public Building {
public:
	Wasserkraftwerk();
};

class Windkraftwerk : public Building {
public:
	Windkraftwerk();
};

class Solarpanele : public Building {
public:
	Solarpanele();
};

