#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

int obtenerCantidadDePersonasPorCasa ( eph_h listaDePersonas, int hogcodusu );
bool esUnHogarEnUnaCiudadMenor500 ( hogar datoHogar );
bool esUnHogarHC(hogar datoHogar, eph_h listaDepersonas);
int obtenerIndexEnBaseALaRegion(int region,  vector<pair<int,float>> data);
#endif //SOLUCION_AUXILIARES_H

