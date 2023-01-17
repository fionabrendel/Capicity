#pragma once
#include "Material.h"
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

class Building{
public:
	//Variablen
	int grundpreis;
	char label; //soll bei Ausdrucken des Plans abgebildet werden
	//vector<Material> zusammensetzung;
	map <Material, int> zusammensetzung;


	//Konstruktoren
	Building();
	
	//Methoden
	char getLabel();
	virtual string getZusammensetzung();
	int getGrundpreis();
	string toString();
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

