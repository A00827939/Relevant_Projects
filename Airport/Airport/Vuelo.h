//
//  Vuelo.h
//  PROYECTO INTEGRADOR
//
//  Created by Roby Saldana on 11/30/19.
//  Copyright © 2019 Roby Saldana. All rights reserved.
//

//clase vuelos
//registrar
    //numero de vuelo
    //hora de salida y llegada
    //origen y destino?
    //duración
//mostrar
    //lista de vuelos disponibles ese día
    //num vuelo
    //hora de salida
    //clave de ciudad de origen y destino
    //duración

#ifndef Vuelo_h
#define Vuelo_h

using namespace std;

#include "Tiempo.h"

class Vuelo{
public:
    Vuelo();
    Vuelo(int nV, int hr, int min, int dur);
    void setNumVuelo(int nV);
    void setHrSalida(int hr, int m);
    void setDuracion(int dur);
    int getNumVuelo();
    Tiempo getHrSalida();
    int getDuracion();


private:
    Tiempo hrSalida;
    int numVuelo;
    int duracion;
};

Vuelo::Vuelo(){
    numVuelo = 0;
    Tiempo hrSalida(0,0);
    duracion = 0;
}
Vuelo::Vuelo(int nV, int hr, int min, int dur){
    numVuelo = nV;
    Tiempo t;
    t.setHora(hr);
    t.setMin(min);
    hrSalida = t;
    duracion = dur;
}

//set
void Vuelo::setNumVuelo(int nV){
    numVuelo = nV;
}
void Vuelo::setHrSalida(int hr, int min){
    Tiempo t;
    t.setHora(hr);
    t.setMin(min);
    hrSalida = t;
}
void Vuelo::setDuracion(int dur){
    duracion = dur;
}

//get
int Vuelo::getNumVuelo(){
    return numVuelo;
}
Tiempo Vuelo::getHrSalida(){
    return hrSalida;
}
int Vuelo::getDuracion(){
    return duracion;
}

#endif /* Vuelo_h */
