#ifndef LIGA_HPP
#define LIGA_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Equipo.hpp"
#include "Partido.hpp"
#include "Tabla.hpp"
using namespace std;

class Liga{
	private:
		string nombre;
		vector<Equipo*> equipos;
		vector<Partido*> jornada;
		Tabla posiciones;
	public:
		Liga();
		Liga(string);
		Liga(string, vector<Equipo*>, vector<Partido*>, Tabla);
		~Liga();
		string getNombre();
		void setNombre(string);
		void agregarEquipo(Equipo*);
		void modificarEquipo(string, string);
		void eliminarEquipo(string);
		void listarEquipos();
		void generarJornada();
		void simularPartidos();
		void imprimirTabla();		
};
#endif

