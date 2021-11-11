#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"
//Auxiliares
int cantHabitantes(hogar h, eph_i ti);
//Ejercicio 1
bool esValida ( eph_h th, eph_i ti );
//Ejercicio 4
float proporcionTeleworking(eph_h th, eph_i ti);
//Ejercicio 7
void insertRegion(eph_h& th, int i);
void insertHogCodUsu(eph_h& th, int i);
void insertIndCodUsu(eph_i& ti,eph_h th, int i);
void insertComponente(eph_h& ti, int i);
//Ejercicio 8
vector <hogar> ordenadaPorIngresos(eph_h &th, eph_i ti);
int ingresos (hogar h, eph_i ti);
vector<hogar> eliminarIngresosRepetidos(eph_h $th,eph_i ti);
#endif //SOLUCION_AUXILIARES_H
