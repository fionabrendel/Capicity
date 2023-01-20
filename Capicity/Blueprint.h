#pragma once
#include "Building.h"

class Blueprint
{
public:
	//Variablen:
	int bbreite;
	int bhoehe;
	int posx;
	int posy;
	int breite;
	int hoehe;
	int gesamtpreis;
	int input;

	//Konstruktor:
	Blueprint();
	Blueprint(int bbreite, int bhoehe);

	//Methoden:
	bool checkKollision(int posx, int posy, int breite, int hoehe);
	void placeBuilding();
	void deleteArea();
	void printPlan();

private:
	Building*** bereich;
	int calcGesamtpreis();
};

