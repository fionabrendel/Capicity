#pragma once
#include "Building.h"
#include "Blueprint.h"
#include <vector>

namespace Sim {
	class CapicitySim
	{
	public:
		//Variablen
		bool running;
		int input;
		vector<Blueprint*> plans;
		

		//Konstruktor:
		CapicitySim();
		CapicitySim(int bbreite, int bhoehe);


		//Methoden
		void stop();
		void showMenu();
		void createPlan();
		void sortPlans();
		void printAllPlans();
		bool checkEquality();
	};
}

