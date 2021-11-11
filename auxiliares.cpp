#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

int obtenerCantidadDePersonasPorCasa ( eph_h listaDePersonas, int hogcodusu ) {
    int personasEnEsaCasa = 0;
    for (int j = 0; j < listaDePersonas.size(); j++){
        if (listaDePersonas[j][INDCODUSU] == hogcodusu){
            personasEnEsaCasa++;
        }
    }
    return personasEnEsaCasa;
}


bool esUnHogarEnUnaCiudadMenor500 ( hogar datoHogar ) {
    return datoHogar[MAS_500] == 0 && datoHogar[IV1] == 1;
}

bool esUnHogarHC(hogar datoHogar, eph_h listaDepersonas){
    int cantidadDeHabitaciones = datoHogar[II2];
    int personasEnEsaCasa = obtenerCantidadDePersonasPorCasa(listaDepersonas,datoHogar[HOGCODUSU]);
    int ratio = (cantidadDeHabitaciones * 3) / personasEnEsaCasa;
    return ratio < 1;
}

int obtenerIndexEnBaseALaRegion(int region,  vector<pair<int,float>> data){
    int index = 0;
    for (;index < data.size(); index++){
        if (region == data[index].first){
            return index;
        }
    }
    return 0;
}
