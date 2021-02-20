#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Equipo.hpp"
#include "Partido.hpp"
#include "Tabla.hpp"
#include "PuntosEquipo.hpp"
#include "Liga.hpp"
using namespace std;
int menuGeneral();
int menuEquipos();

int main(int argc, char** argv) {
	int opcion;
	Liga* league = new Liga("Liga SalvaVida");
	while((opcion = menuGeneral()) != 3) {
		switch(opcion) {
			case 1: {
				int opcion2;
				while((opcion2 = menuEquipos()) != 5) {
					switch(opcion2) {
						case 1: {
							cout << "Nuevo Equipo" << endl;
							string nombre;
							cout << "Ingrese el nombre del equipo: ";
							cin >> nombre;
							Equipo* equipo = new Equipo(nombre);
							league->agregarEquipo(equipo);
							cout << "Se ha agregado el equipo " << nombre << " con un skill de " << equipo->getSkill();
							cout << endl;
							cout << endl;
							delete[] equipo;
							break;
						}

						case 2: {
							cout << "Modificar Equipo" << endl;
							string nombreInicial, nombreNuevo;
							cout << "Ingrese el nombre del equipo a modificar: ";
							cin >> nombreInicial;
							cout << "Ingrese el nuevo nombre del equipo: ";
							cin >> nombreNuevo;
							league->modificarEquipo(nombreInicial, nombreNuevo);
							cout << endl;
							cout << endl;
							break;
						}

						case 3: {
							if(league->getJornadas().empty()) {
								cout << "La liga ya ha sido iniciada, no se pueden eliminar equipos";
							} else {
								cout << "Eliminar Equipo" << endl;
								string _nombre;
								cout << "Ingrese el nombre del equipo a eliminar: ";
								cin >> _nombre;
								league->eliminarEquipo(_nombre);
								cout << endl;
								cout << endl;
							}
							break;
						}

						case 4: {
							cout << endl;
							league->listarEquipos();
							cout << endl;
							cout << endl;
							break;
						}
					}//fin del switch
				}//fin while
				break;
			}

			case 2: {
				
				break;
			}

			default: {
				league->~Liga();
				break;
			}

		}//fin del switch
	}//fin while
	return 0;
}

int menuGeneral() {
	int opcion;
	cout << "----MENU----" << endl;
	cout << "1. Mantenimiento de Equipos" << endl;
	cout << "2. Desarrollo de la Liga" << endl;
	cout << "3. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}//fin metodo Menu

int menuEquipos() {
	int opcion;
	cout << "1. Agregar Equipo" << endl;
	cout << "2. Modificar Equipo" << endl;
	cout << "3. Eliminar Equipo" << endl;
	cout << "4. Listar Equipos" << endl;
	cout << "5. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}//fin metodo Menu