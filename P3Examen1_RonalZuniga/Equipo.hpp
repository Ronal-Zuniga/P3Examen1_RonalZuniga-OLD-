#ifndef EQUIPO_HPP
#define EQUIPO_HPP
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Equipo{
	private:
		string nombre;
		int skill;
	public:
		Equipo();
		Equipo(string);
		string getNombre();
		void setNombre(string);
		int getSkill();
		void setSkill(int, int);
};
#endif

