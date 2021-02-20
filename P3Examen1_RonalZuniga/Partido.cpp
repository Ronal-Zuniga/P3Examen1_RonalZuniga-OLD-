#include "Partido.hpp"

Partido::Partido(){
}

Partido::Partido(Equipo* eq1, Equipo* eq2, int golesE1, int golesE2, bool _jugado){
	this->equipo1 = eq1;
	this->equipo2 = eq2;
	this->goles_eq1 = golesE1;
	this->goles_eq2 = golesE2;
	this->jugado = _jugado;
}

Equipo* Partido::getEq1(){
	return this->equipo1;
}

void Partido::setEq1(Equipo* eq1){
	this->equipo1 = eq1;
}

Equipo* Partido::getEq2(){
	return this->equipo2;
}

void Partido::setEq2(Equipo* eq2){
	this->equipo2 = eq2;
}

int Partido::getGolesEq1(){
	return this->goles_eq1;
}

void Partido::setGolesEq1(int goles){
	this->goles_eq1 = goles;
}

int Partido::getGolesEq2(){
	return this->goles_eq2;
}

void Partido::setGolesEq2(int goles){
	this->goles_eq2 = goles;
}

bool Partido::getJugado(){
	return this->jugado;
}

void Partido::setJugado(bool _jugado){
	this->jugado = _jugado;
}

