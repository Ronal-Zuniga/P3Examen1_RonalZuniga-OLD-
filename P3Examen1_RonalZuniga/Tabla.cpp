#include "Tabla.hpp"

Tabla::Tabla() {
}

Tabla::Tabla(vector<PuntosEquipo*> _posiciones) {
	this->puntosEq = _posiciones;
}

vector<PuntosEquipo*> Tabla::getTabla() {
	return this->puntosEq;
}

void Tabla::agregarPuntosEquipo(PuntosEquipo* pe) {
	this->puntosEq.push_back(pe);
}

void Tabla::ordenarPosiciones() {
	for (int i = 0; i < puntosEq.size(); i++) {
		for (int j = 0; j < puntosEq.size() - 1; j++) {
			PuntosEquipo* eq1 = puntosEq[j];
			PuntosEquipo* eq2 = puntosEq[j+1];
			int pEq1 = (eq1->getPartidosG() * 3) + (eq1->getPartidosE() * 1);
			int pEq2 = (eq2->getPartidosG() * 3) + (eq2->getPartidosE() * 1);
			int gfEq1 = eq1->getGolesF();
			int gfEq2 = eq2->getGolesF();
			PuntosEquipo* temp;
			if(pEq1 < pEq2) {
				temp = eq1;
				eq1 = eq2;
				eq2 = temp;
			} else {
				if(pEq1 == pEq2) {
					if(gfEq1 < gfEq2) {
						temp = eq1;
						eq1 = eq2;
						eq2 = temp;
					}
				}
			}
			delete eq1;
			delete eq2;
			delete temp;
		}
	}
}