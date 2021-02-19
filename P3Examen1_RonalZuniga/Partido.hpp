#ifndef PARTIDO_HPP
#define PARTIDO_HPP
#include <iostream>
#include "Equipo.hpp"
using namespace std;

class Partido{
	private: 
		Equipo equipo1;
		Equipo equipo2;
		int goles_eq1;
		int goles_eq2;
		bool jugado;
	public:
		Partido();
		Partido(Equipo, Equipo, int, int, bool);
		Equipo getEq1();
		void setEq1(Equipo);
		Equipo getEq2();
		void setEq2(Equipo);
		int getGolesEq1();
		void setGolesEq1(int);
		int getGolesEq2();
		void setGolesEq2(int);
		bool getJugado();
		void setJugado(bool);
};
#endif