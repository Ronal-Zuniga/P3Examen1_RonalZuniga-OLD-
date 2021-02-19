#ifndef PUNTOSEQUIPO_HPP
#define PUNTOSEQUIPO_HPP
#include <iostream>
#include "Equipo.hpp"
using namespace std;

class PuntosEquipo{
	private:
		Equipo equipo;
		int gFavor, gContra, pGanados, pPerdidos, pEmpatados;
	public:
		PuntosEquipo();
		PuntosEquipo(Equipo, int, int, int, int, int);
		Equipo getEq();
		void setEq(Equipo);
		int getGolesF();
		void setGolesF(int);
		int getGolesC();
		void setGolesC(int);
		int getPartidosG();
		void setPartidosG(int);
		int getPartidosE();
		void setPartidosE(int);
		int getPartidosP();
		void setPartidosP(int);
};
#endif