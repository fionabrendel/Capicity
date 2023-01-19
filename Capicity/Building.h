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
	//Entscheidung f�r Carlas Idee, weil...
	//...Verwaltung der Materialien zu wenig Aufwand ist, um den Overhead
	//einer neuen Klasse zu rechtfertigen
	//...au�erdem bleibt die von Carla erw�hnte Erweiterbarkeit erhalten


	//Konstruktoren
	Building();
	
	//Methoden
	char getLabel();
	virtual string getZusammensetzung();
	int getGrundpreis();
};

//abgeleitete Geb�ude

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

