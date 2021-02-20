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

void Tabla::actualizarTabla(vector<Partido*> jornada){
	for (int i = 0; i < jornada.size(); i++){
		Partido* match = jornada[i];
		Equipo* eq1 = match->getEq1();
		Equipo* eq2 = match->getEq2();
		for (int j = 0; j < puntosEq.size(); j++){
			PuntosEquipo* ptsEq = puntosEq[i];
			Equipo* e = ptsEq->getEq();
			if(e == eq1 || e == eq2){
				if(e == eq1){
					ptsEq->setGolesF(match->getGolesEq1());
					ptsEq->setGolesC(match->getGolesEq2());
					if(match->getGolesEq1() == match->getGolesEq2()){
						ptsEq->setPartidosE(true);
					}else{
						if(match->getGolesEq1() > match->getGolesEq2()){
							ptsEq->setPartidosG(true);
						} else{
							ptsEq->setPartidosP(true);
						}
					}
				} else{
					ptsEq->setGolesF(match->getGolesEq2());
					ptsEq->setGolesC(match->getGolesEq1());
					if(match->getGolesEq1() == match->getGolesEq2()){
						ptsEq->setPartidosE(true);
					}else{
						if(match->getGolesEq2() > match->getGolesEq1()){
							ptsEq->setPartidosG(true);
						} else{
							ptsEq->setPartidosP(true);
						}
					}
				}
			}
			delete e;
			delete ptsEq;
		}
		delete eq1;
		delete eq2;
		delete match;
	}
}