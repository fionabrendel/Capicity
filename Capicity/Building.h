#pragma once
#include "Material.h"

class Building
{
	//Variablen
	int grundpreis;
	char label; //soll bei Ausdrucken des Plans abgebildet werden
	Material* zusammensetzung; //soll ein Feld f�r Materialien werden

	//Konstruktoren
	Building();
};

