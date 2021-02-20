#ifndef TABLA_HPP
#define TABLA_HPP
#include <iostream>
#include <vector>
#include "PuntosEquipo.hpp"
#include "Partido.hpp"
using namespace std;

class Tabla{
	private:
		vector<PuntosEquipo*> puntosEq;
	public:
		Tabla();
		Tabla(vector<PuntosEquipo*>);
		void agregarPuntosEquipo(PuntosEquipo*);
		vector<PuntosEquipo*> getTabla();
		void ordenarPosiciones();
		void actualizarTabla(vector<Partido*>);
};
#endif