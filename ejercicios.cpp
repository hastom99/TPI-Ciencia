#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1

bool esEncuestaValida ( eph_h th, eph_i ti ) {
    return esValida(th,ti);
}

// Implementacion Problema 2
vector <int> histHabitacional ( eph_h th, eph_i ti, int region ) {
	vector < int > resultado = {-1, -1, -1, -1, -1, -1};
	
	// TODO
	
	return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                        make_pair(40, -1.0),
                                        make_pair(41, -1.0),
                                        make_pair(42,-1.0),
                                        make_pair(43,-1.0),
                                        make_pair(44,-1.0)};
	// TODO
	
  return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
	bool resp = false;
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
	int resp = -1;
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    // Se supone por Pre que esValida(th,ti).
    join_hi resp;
    for (int i=0; i < ti.size(); i++){
        for (int j=0 ; j < th.size(); j++){
            if (ti[i][INDCODUSU] == th[j][HOGCODUSU]) {
                resp.push_back(make_pair(th[j],ti[i]));
            }
        }
    }
    return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h&  th, eph_i& ti) {
    // Ordeno primero la tabla hogares.
    for (int i=0; i < th.size(); i++){
        insertRegion(th,i); // Uso Insertion Sort para ordenar primero por REGION.
    }
    for (int i=0; i < th.size(); i++){ // Ahora ordena por HOGCODUSU en cada bloque REGION.
        insertHogCodUsu(th,i);
    }
    // Ordeno ahora la tabla individuos.
    for (int i=0; i < ti.size(); i++){
        insertIndCodUsu(ti,th,i); // Uso Insertion Sort para ordenar primero por INDCODUSU.
    }
    for (int i=0; i < ti.size(); i++){ // Ahora ordena por COMPONENTE en cada bloque.
        insertComponente(ti,i);
    }
}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    hogar h = {};
    vector < hogar > resp = {h};

    // TODO

    return  resp;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
	
	// TODO
	
	return;
}

// Implementacion Problema 10
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
	vector < int > resp = {};
	
	// TODO
	
	return resp;
}

// Implementacion Problema 11
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    pair < eph_h, eph_i > resp = make_pair(rth, rti);
		
	// TODO
	
	return resp;
}
