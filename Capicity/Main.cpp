#include "CapicitySim.h"
#include <cstdlib>
using namespace std;
using namespace Sim;

int main(int argc, char* argv[]) {
	int bbreite = strtol(argv[1], nullptr, 10);
	int bhoehe = strtol(argv[2], nullptr, 10);
	//für Debugger verwenden:
	//int bbreite = 10;
	//int bhoehe = 10;

	CapicitySim* simulation = new CapicitySim(bbreite, bhoehe);
}