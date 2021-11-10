#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1

bool esEncuestaValida ( eph_h th, eph_i ti ) {
    return esValida(th,ti);
}

bool esValida ( eph_h th, eph_i ti ){
    bool res = !vacia(th) && !vacia(ti) && esMatriz(th) && esMatriz(ti) &&
               cantidadCorrectaDeColumnasI(ti) && cantidadCorrectaDeColumnasH(th) && (
                       !hayIndividuosSinHogares(th,ti) && !hayHogaresSinIndividuos(th,ti) &&
                       !hayRepetidosI(ti) && !hayRepetidosH(th) && mismoAnioYTrimestre(ti,th) &&
                       menosDe21MiembrosPorHogar(th,ti) && cantidadValidaDormitorios(th) &&
                       valoresEnRangoI(ti) && valoresEnRangoH(th) );
    return res;
}

bool vacia(eph_h th){
    bool res = th.size() == 0;
    return res;
}

bool esMatriz(vector<vector<int> > m){
    bool res = true;
    for(int i=0; i < m.size()-1; i++){
        res = res && (m[i].size() == m[i+1].size());
    }
    return res;
}

bool cantidadCorrectaDeColumnasI(eph_i ti){
    bool res = true;
    for(int i=0; i < ti.size(); i++){
        res = res && (ti[i].size() == 11); // La longitud de cada individuo se corresponde con la cantidad de Items Individuo.
    }
    return res;
}

bool cantidadCorrectaDeColumnasH(eph_h th){
    bool res = true;
    for(int i=0; i < th.size(); i++){
        res = res && (th[i].size() == 12); // La longitud de cada hogar se corresponde con la cantidad de Items Hogar.
    }
    return res;
}

bool hayIndividuosSinHogares(eph_h th, eph_i ti){
    for (int i=0; i < ti.size(); i++){
        bool res = false;
        for (int j=0 ; j < th.size(); j++){
            res = res || ( ti[i][INDCODUSU] == th[j][HOGCODUSU] );
        } if (!res) return !res;
    }
    return false;
}

bool hayHogaresSinIndividuos(eph_h th, eph_i ti){
    for (int i=0; i < th.size(); i++){
        bool res = false;
        for (int j=0 ; j < ti.size(); j++){
            res = res || ( ti[j][INDCODUSU] == th[i][HOGCODUSU] );
        } if (!res) return !res;
    }
    return false;
}

bool hayRepetidosI(eph_i ti){
    bool res = false;
    for (int i=0; i < ti.size()-1 ; i++){
        for (int j = i+1; j < ti.size(); j++){
            if ( mismoCodUsuYComponente(ti[i],ti[j]) ) {
                return !res;
            }
        }
    }
    return res;
}

bool mismoCodUsuYComponente(individuo i1, individuo i2){
    return (i1[INDCODUSU] == i2[INDCODUSU]) && (i1[COMPONENTE] == i2[COMPONENTE]);
}

bool hayRepetidosH(eph_h th){
    bool res = false;
    for (int i=0; i < th.size()-1 ; i++){
        for (int j = i+1; j < th.size(); j++){
            if ( th[i][HOGCODUSU] == th[j][HOGCODUSU] ) {
                return !res;
            }
        }
    }
    return res;
}

bool mismoAnioYTrimestre(eph_i ti, eph_h th){
    int anio = ti[0][INDANIO];
    int trimestre = ti[0][INDTRIMESTRE];
    bool res = true;
    for (int i=1; i < ti.size(); i++){
        if (ti[i][INDANIO] != anio || ti[i][INDTRIMESTRE] != trimestre) return !res;
    }
    for (int i=0; i < th.size(); i++){
        if (th[i][HOGANIO] != anio || th[i][HOGTRIMESTRE] != trimestre) return !res;
    }
    return res;
}

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti){
    bool res = true;
    for (int i=0; i < th.size(); i++){
        res = res && (cantHabitantes(th[i],ti) < 21);
    }
    return res;
}

int cantHabitantes(hogar h, eph_i ti){
    int cont=0;
    for (int i=0; i < ti.size(); i++){
        if ( esSuHogar(h,ti[i]) ) cont++;
    }
    return cont;
}

bool esSuHogar(hogar h, individuo i){
    return h[HOGCODUSU] == i[INDCODUSU];
}

bool valoresEnRangoI(eph_i ti){
    bool res = true;
    for (int i=0; i < ti.size(); i++){
        res = res && individuoValido(ti[i]);
    }
    return res;
}

bool individuoValido(individuo i){
    return (i[INDCODUSU] > 0) && (i[COMPONENTE] > 0) &&
           (0 < i[INDTRIMESTRE] && i[INDTRIMESTRE] <= 4) &&
           (0 < i[CH4] && i[CH4] <= 2) && // CH4 = Genero.
           (i[CH6] >= 0) && // CH6 = Edad.
           (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1) &&
           (-1 <= i[ESTADO] && i[ESTADO] <= 1) &&
           (0 <= i[CAT_OCUP] && i[CAT_OCUP] <= 4) &&
           (i[p47T] >= 0 || i[p47T] == -1) && // p47T = Ingreso total.
           (0 <= i[PP04G] && i[PP04G] <= 10); // PP04G = Ubicacion laboral.
}
bool valoresEnRangoH(eph_h th){
    bool res = true;
    for (int i=0; i < th.size(); i++){
        res = res && hogarValido(th[i]);
    }
    return res;
}

bool hogarValido(hogar h){
    return (h[HOGCODUSU] > 0) &&
           (0 < h[HOGTRIMESTRE] && h[HOGTRIMESTRE] <= 4) &&
           (0 < h[II7] && h[II7] <= 3) && // II7 = Regimen de tenencia.
           valorRegionValido(h[REGION]) &&
           (h[MAS_500] == 0 || h[MAS_500] == 1) &&
           (0 < h[IV1] && h[IV1] <= 5) && // IV1 = Tipo de hogar.
           (h[IV2] > 0) && // IV2 = Cantidad de habitaciones.
           (h[II2] >= 1) && // II2 = Cantidad de dormitorios.
           (h[II3] == 1 || h[II3] == 2); // Si alguna de las habitaciones se usa para trabajar.
}

bool valorRegionValido(int r){
    return ( r == 1 ) || (40 <= r && r <= 44);
}

bool cantidadValidaDormitorios(eph_h th){
    bool res = true;
    for (int i=0; i < th.size(); i++){
        res = res && (th[i][IV2] >= th[i][II2]); // Cantidad de habitaciones mayor igual a la cantidad de dormitorios.
    }
    return res;
}
// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
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

void insertRegion(eph_h& th, int i){
    for (int j = i; j > 0 && th[j][REGION] < th[j-1][REGION]; j--){
        swap(th,j,j-1);
    }
}

void insertHogCodUsu(eph_h& th, int i){
    for (int j = i; j > 0 && th[j][REGION] == th[j-1][REGION] && th[j][HOGCODUSU] < th[j-1][HOGCODUSU]; j--){
        swap(th,j,j-1);
    }
}

void insertIndCodUsu(eph_i& ti,eph_h th, int i){
    for (int j = i; j > 0 && ordenHogar(ti[j][INDCODUSU],th) < ordenHogar(ti[j-1][INDCODUSU],th); j--){
        swap(ti,j,j-1);
    }
}

int ordenHogar(int indCodUsu, eph_h th){ // Se fija el orden del hogar en th.
    for(int i=0; i < th.size(); i++){
        if ( indCodUsu == th[i][HOGCODUSU]){
            return i;
        }
    }
}

void insertComponente(eph_h& ti, int i){
    for (int j = i; j > 0 && ti[j][INDCODUSU] == ti[j-1][INDCODUSU] && ti[j][COMPONENTE] < ti[j-1][COMPONENTE]; j--){
        swap(ti,j,j-1);
    }
}

void swap(eph_h& th, int i, int j){
    hogar a = th[i];
    hogar b = th[j];
    th[i] = b;
    th[j] = a;
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
