#include "Liga.hpp"
Liga::Liga() {
}

Liga::Liga(string _nombre) {
	this->nombre = _nombre;
}

Liga::Liga(string _nombre, vector<Equipo*> _equipos, vector<Partido*> _partidos, Tabla _posiciones) {
	this->nombre = _nombre;
	this->equipos = _equipos;
	this->jornada = _partidos;
	this->posiciones = _posiciones;
}

Liga::~Liga() {
	for(int i = 0; i < equipos.size(); i++) {
		delete equipos[i];
	}
	for(int i = 0; i < jornada.size(); i++) {
		delete jornada[i];
	}
}

string Liga::getNombre() {
	return this->nombre;
}

void Liga::setNombre(string _nombre) {
	this->nombre = _nombre;
}

vector<Partido*> Liga::getJornadas() {
	return this->jornada;
}

void Liga::agregarEquipo(Equipo* e) {
	equipos.push_back(e);
	PuntosEquipo* ptsEq = new PuntosEquipo(e, 0, 0, 0, 0, 0);
	this->posiciones.agregarPuntosEquipo(ptsEq);
	cout << "Equipo agregado correctamente";
	cout << endl;
	cout << endl;
}

void Liga::modificarEquipo(string nombreInicial, string nombreNuevo) {
	bool flag;
	int _skill;
	for (int i = 0; i < equipos.size(); i++) {
		Equipo* eq = equipos[i];
		if(eq->getNombre() == nombreInicial && nombreInicial != nombreNuevo) {
			Equipo* equipo = new Equipo(nombreNuevo);
			equipos[i] = equipo;
			_skill = equipo->getSkill();
			flag = true;
			i = equipos.size();
			delete equipo;
		} else {
			flag = false;
		}
		delete eq;
	}
	if(flag) {
		cout << "Equipo modificado correctamente";
		cout << "El equipo quedó con un skill de " << _skill;
	} else {
		cout << "No se ha encontrado el equipo a modificar o quiere colocar mismo nombre";
	}
	cout << endl;
	cout << endl;
}

void Liga::eliminarEquipo(string _nombre) {
	bool flag;
	for (int i = 0; i < equipos.size(); i++) {
		Equipo* eq = equipos[i];
		if(eq->getNombre() == _nombre) {
			equipos.erase(equipos.begin() + i);
			flag = true;
			i = equipos.size();
		} else {
			flag = false;
		}
		delete eq;
	}
	if(flag) {
		cout << "Equipo eliminado correctamente";
	} else {
		cout << "No se ha encontrado el equipo a eliminar";
	}
	cout << endl;
	cout << endl;
}

void Liga::listarEquipos() {
	cout << "Equipos registrados en la Liga: " << endl;
	for (int i = 0; i < equipos.size(); i++) {
		Equipo* eq = equipos[i];
		cout << i + 1 << ". " + eq->getNombre() << endl;
		delete eq;
	}
	cout << endl;
	cout << endl;
}

void Liga::imprimirTabla() {
	cout << "Tabla de Posiciones de " << this->nombre << endl;
	cout << setw(3);
	cout << "Equipo" << setw(10) << "PJ" << setw(3) << "PG" << setw(3) << "PE"
	     << setw(3) << "PP" << setw(3) << "GF" << setw(3) << "GC" << setw(3) << "PTS" << endl;
	posiciones.ordenarPosiciones();
	for (int i = 0; i < posiciones.getTabla().size(); i++) {
		PuntosEquipo* pe = posiciones.getTabla()[i];
		cout << setw(3);
		cout << (pe->getEq()->getNombre()) << setw(10) << ((pe->getPartidosE()) + (pe->getPartidosG()) + (pe->getPartidosP())) << setw(3) << (pe->getPartidosG()) << setw(3) << (pe->getPartidosE())
		     << setw(3) << (pe->getPartidosP())<< setw(3) << (pe->getGolesF())<< setw(3) << pe->getGolesC() << setw(3) << ((pe->getPartidosG() * 3) + pe->getPartidosE()) << endl;
		
	}
	cout << endl;
	cout << endl;
}

vector<Partido*> Liga::simularPartidos(vector<Partido*> temp) {
	srand ((unsigned)time(0));
	int _valor1 = valor(-15, 15);
	int _valor2 = valor(-15, 15);
	for (int i = 0; i < temp.size(); i++){
		Partido* match = temp[i];
		Equipo* eq1 = match->getEq1();
		Equipo* eq2 = match->getEq2();
		int skillEq1 = eq1->getSkill() + _valor1;
		int skillEq2 = eq2->getSkill() + _valor2;
		int gEq1 = goles(skillEq1);
		int gEq2 = goles(skillEq2);
		Partido* p;
		if(skillEq1 == skillEq2){
			gEq1 = gEq2;
			p = new Partido(eq1, eq2, gEq1, gEq2, true);
		} else{
			p = new Partido(eq1, eq2, gEq1, gEq2, true);
		}
		delete match;
		delete eq1;
		delete eq2;
		delete[] p;
	}
	return temp;
}

int Liga::valor(int min, int max) {
	int v = min + (rand() % (max - min));
	return v;
}
 
int Liga::goles(int skill){
	double div = skill / 10;
	int goal = (int)div;
	return goal;
}

void Liga::generarJornada(){
	
}






