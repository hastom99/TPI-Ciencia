#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"
//Ejercicio 1
bool esValida ( eph_h th, eph_i ti );
//Ejercicio 7
void insertRegion(eph_h& th, int i);
void insertHogCodUsu(eph_h& th, int i);
void insertIndCodUsu(eph_i& ti,eph_h th, int i);
void insertComponente(eph_h& ti, int i);
#endif //SOLUCION_AUXILIARES_H
