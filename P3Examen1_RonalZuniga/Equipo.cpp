#include "Equipo.hpp"

Equipo::Equipo(){
}

Equipo::Equipo(string _nombre){
	this->nombre = _nombre;
	srand ((unsigned)time(0));
	setSkill(0,100);
}

string Equipo::getNombre(){
	return this->nombre;
}

void Equipo::setNombre(string _nombre){
	this->nombre = _nombre;
}

void Equipo::setSkill(int min, int max){
	this->skill = min + (rand() % (max - min));
}

int Equipo::getSkill(){
	return this->skill;
}
