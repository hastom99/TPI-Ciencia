#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"
//Auxiliares
int cantHabitantes(hogar h, eph_i ti);
//Ejercicio 1
bool esValida ( eph_h th, eph_i ti );
//Ejercicio 2
int obtenerMaximoNumeroDeHabitacionesPorRegion(eph_i listaDeHogares,int region);
//Ejercicio 3
bool esUnHogarEnUnaCiudadMenor500 ( hogar datoHogar );
bool esUnHogarHC(hogar datoHogar, eph_h listaDepersonas);
int obtenerIndexEnBaseALaRegion(int region,  vector<pair<int,float>> data);
//Ejercicio 4
float proporcionTeleworking(eph_h th, eph_i ti);
//Ejercicio 7
void insertRegion(eph_h& th, int i);
void insertHogCodUsu(eph_h& th, int i);
void insertIndCodUsu(eph_i& ti,eph_h th, int i);
void insertIndCodUsu(eph_i& ti,eph_h th, int i);
void insertComponente(eph_h& ti, int i);
//Ejercicio 8
vector <hogar> ordenadaPorIngresos(eph_h &th, eph_i ti);
int ingresos (hogar h, eph_i ti);
vector<hogar> eliminarIngresosRepetidos(eph_h $th,eph_i ti);
//Ejercicio 10
float distanciaEuclideana(int latitud, int longitud, pair < int, int > centro);
int obtenerIndexAQueDistanciaPertenece(float distancia, vector<int> rangosDeDistancias);
//Ejercicio 11
int ordenHogar(int indCodUsu, eph_h th);
bool coincideTerminosDeBusqueda(vector<dato> individuo, vector < pair < int, dato > >  busqueda);
bool yaExisteUnHogar(vector<dato> hogar, eph_h tablaHogares);
#endif //SOLUCION_AUXILIARES_H

int obtenerCantidadDePersonasPorCasa ( eph_h listaDePersonas, int hogcodusu );
