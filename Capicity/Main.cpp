#include "CapicitySim.h"
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
	int bbreite = strtol(argv[1], nullptr, 10);
	int bhoehe = strtol(argv[2], nullptr, 10);

	CapicitySim* simulation = new CapicitySim(bbreite, bhoehe);
	//TO DO: danach noch deleten
}