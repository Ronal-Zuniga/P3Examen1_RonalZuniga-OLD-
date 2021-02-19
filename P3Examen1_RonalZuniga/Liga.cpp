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

string Liga::getNombre() {
	return this->nombre;
}

void Liga::setNombre(string _nombre) {
	this->nombre = _nombre;
}

void Liga::agregarEquipo(Equipo* e) {
	equipos.push_back(e);
	cout << "Equipo agregado correctamente";
	cout << endl;
	cout << endl;
}

void Liga::modificarEquipo(string nombreInicial, string nombreNuevo) {
	bool flag;
	for (int i = 0; i < equipos.size(); i++) {
		Equipo* eq = equipos[i];
		if(eq->getNombre() == nombreInicial && nombreInicial != nombreNuevo) {
			Equipo* equipo = new Equipo(nombreNuevo);
			equipos[i] = equipo;
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



