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
		void stop();
		void showMenu();
	};
}

