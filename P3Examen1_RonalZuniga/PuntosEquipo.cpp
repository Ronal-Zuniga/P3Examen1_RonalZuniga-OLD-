#include "PuntosEquipo.hpp"

PuntosEquipo::PuntosEquipo(){
}

PuntosEquipo::PuntosEquipo(Equipo eq, int _gf, int _gc, int _pg, int _pe, int _pp){
	this->equipo = eq;
	this->gFavor = _gf;
	this->gContra = _gc;
	this->pGanados = _pg;
	this->pEmpatados = _pe;
	this->pPerdidos = _pp;
}

Equipo PuntosEquipo::getEq(){
	return this->equipo;
}

void PuntosEquipo::setEq(Equipo eq){
	this->equipo = eq;
}

int PuntosEquipo::getGolesF(){
	return this->gFavor;
}

void PuntosEquipo::setGolesF(int goles){
	this->gFavor = goles;
}

int PuntosEquipo::getGolesC(){
	return this->gContra;
}

void PuntosEquipo::setGolesC(int goles){
	this->gContra = goles;
}

int PuntosEquipo::getPartidosG(){
	return this->pGanados;
}

void PuntosEquipo::setPartidosG(int partidos){
	this->pGanados = partidos;
}

int PuntosEquipo::getPartidosE(){
	return this->pEmpatados;
}

void PuntosEquipo::setPartidosE(int partidos){
	this->pEmpatados = partidos;
}

int PuntosEquipo::getPartidosP(){
	return this->pPerdidos;
}

void PuntosEquipo::setPartidosP(int partidos){
	this->pPerdidos = partidos;
}
