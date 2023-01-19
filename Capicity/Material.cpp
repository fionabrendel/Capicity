#include "Material.h"

Material::Material() {
	preis = 10;
}

int Material::getPreis() {
	return preis;
}

string Material::toString() {
	return "Material";
}