#pragma once
#include "Building.h"

namespace Sim {
	class CapicitySim
	{
	public:
		//Variablen
		bool running;
		int input;
		

		//Konstruktor:
		CapicitySim();
		CapicitySim(int bbreite, int bhoehe);


		//Methoden
		bool checkKollision(int posx, int posy, int breite, int hoehe);
		void placeBuilding();
		void deleteArea();
		void printPlan();
		void stop();
		void showMenu();

	private:
		Building ***bereich;
		int calcGesamtpreis();
	};
}

