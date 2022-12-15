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
	vector<Material> zusammensetzung;

	//Konstruktoren
	Building();

	//Destruktor
	~Building();
	
	//Methoden
	char getLabel();
	string getZusammensetzung();
	int getGrundpreis();
	string toString();
};

//abgeleitete Gebäude

class Leer : public Building {
public:
	Leer();
	~Leer();
};

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

