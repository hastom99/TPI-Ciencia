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

    vector<pair<int,float>> resp = {make_pair(1,0),
                                        make_pair(40, 0),
                                        make_pair(41, 0),
                                        make_pair(42,0),
                                        make_pair(43,0),
                                        make_pair(44,0)};
    vector<pair<float,float>> parHogaresValidosYCriticos = {make_pair(0,0),
                                    make_pair(0, 0),
                                    make_pair(0, 0),
                                    make_pair(0,0),
                                    make_pair(0,0),
                                    make_pair(0,0)};
	// TODO
    int regionAnterior= -1;
    int regionActual = 0;
    int index = 0;
    float hogaresValidos = 0;
    float hogaresHC = 0;

    for(int i = 0; i < th.size(); i++ ){
        if (esUnHogarEnUnaCiudadMenor500(th[i])){
            regionActual = th[i][REGION];
            if (regionAnterior != regionActual){
                index = obtenerIndexEnBaseALaRegion(regionActual,resp);
                regionAnterior = regionActual;
            }
            parHogaresValidosYCriticos[index].first++;
            if (esUnHogarHC(th[i],ti)){
                parHogaresValidosYCriticos[index].second++;
            }
        }
      }
    for(int i = 0; i < resp.size(); i++){
        hogaresValidos = parHogaresValidosYCriticos[i].first;
        hogaresHC = parHogaresValidosYCriticos[i].second;
        resp[i].second = hogaresHC/hogaresValidos;
    }

  return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
    bool resp = proporcionTeleworking(t2h,t2i) > proporcionTeleworking(t1h,t1i);
    return  resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
    int resp = 0;
    int h = 0;
    while (h < th.size()){
        if (th[h][II7] == 1 && th[h][II2]<cantHabitantes(th[h],ti)-2){
            resp = resp + monto;
            h++;
        } else {
            h++;
        }
    }
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
    th = ordenadaPorIngresos(th,ti);
    th = eliminarIngresosRepetidos(th,ti);
    vector<hogar> muestraMaslarga = {};
    int i = 0;
    while (i<th.size()-1){
        int j = i+1;
        int diferenciaDeIngresos = 0;
        while (j<th.size()){
            diferenciaDeIngresos = ingresos(th[j],ti) - ingresos(th[i],ti);
            vector<hogar> muestra = {th[i],th[j]};
            int h = j+1;
            while (h<th.size()){
                if(ingresos(th[h],ti) - ingresos(muestra[muestra.size()-1],ti) == diferenciaDeIngresos){
                    muestra.push_back(th[h]);
                    h++;
                } else {
                    h++;
                }
            }
            if (muestra.size()>muestraMaslarga.size()){
                muestraMaslarga = muestra;
            }
            j++;
        }
        i++;
    }
    if (muestraMaslarga.size()<3){
        muestraMaslarga = {};
    }
    return  muestraMaslarga;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
    int h = 0;
    while (h < th.size()){
        if (th[h][REGION] == GBA){
            th[h][REGION] = PAMPEANA;
            h++;
        } else {
            h++;
        }
    }
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
