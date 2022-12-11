#pragma once
#include "Material.h"
#include <string>
#include <vector>
using namespace std;

class Building{
public:
	//Variablen
	int grundpreis;
	char label; //soll bei Ausdrucken des Plans abgebildet werden
	//Material** zusammensetzung; //zeigt auf Feld mit Materialien
	vector<Material> zusammensetzung;

	//Konstruktoren
	Building();

	//Destruktor
	~Building();
	
	//Methoden
	char getLabel();
	Material getZusammensetzung();
	int getGrundpreis();
	string toString();
};

//abgeleitete Gebäude
class Wasserkraftwerk : public Building {
public:
	Wasserkraftwerk();
	~Wasserkraftwerk();
};

class Windkraftwerk : public Building {
public:
	Windkraftwerk();
	~Windkraftwerk();
};

class Solarpanele : public Building {
public:
	Solarpanele();
	~Solarpanele();
};

