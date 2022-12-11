#pragma once
#include <string>
using namespace std;

class Material
{
	public:
		int preis;
		Material();
		~Material();
		int getPreis();
		string getName();
};

class Leer : public Material {
public:
	Leer();
	~Leer();
};
