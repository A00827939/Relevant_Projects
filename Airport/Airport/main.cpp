//
//  main.cpp
//  PROYECTO INTEGRADOR
//
//  Created by Roby Saldana on 11/30/19.
//  Copyright © 2019 Roby Saldana. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Vuelo.h"
#include "Pasajero.h"

//función muestraVuelos muestra la lista de vuelos
void muestraVuelos(Vuelo listaVuelos[], int cantVuelos){
    cout << "|Número Vuelo|  |Hora de Salida|  |Duración de vuelo|" << endl;
    for (int i = 0; i < cantVuelos; i++){
        cout << "     " << listaVuelos[i].getNumVuelo() << "     ";
        cout << "         " << listaVuelos[i].getHrSalida().getHora() << ":" << listaVuelos[i].getHrSalida().getMin() << "        ";
        cout << "        " << listaVuelos[i].getDuracion() << endl;
    }
    cout << endl;
}

//función muestraPasajeros muestra la lista de pasajeros
void muestraPasajeros(Pasajero listaPasaj[], int cantPasajeros){
    for (int i = 0; i < cantPasajeros; i++){
        cout << "Nombre: " << listaPasaj[i].getNomPasajero() << " Vuelo: " << listaPasaj[i].getNumVueloPasj() << endl;
    }
    cout << endl;
}

//función registraVuelos toma datos del usuario y los agrega a el arreglo de Vuelos
void registraVuelos(Vuelo listaVuelos[], int &cantVuelos){

    int numVuelo, hora, min, duracion;
    
    //Pedir datos de vuelo
    cout << "Ingrese el número de vuelo: ";
    cin >> numVuelo;

    cout <<"Ingrese la hora de salida: (hr y min separados por espacio): ";
    cin >> hora >> min;

    cout <<"Ingrese la duración del vuelo en minutos: ";
    cin >> duracion;

    cout << endl;
    //Set datos en arreglo
    listaVuelos[cantVuelos].setNumVuelo(numVuelo);
    listaVuelos[cantVuelos].setHrSalida(hora, min);
    listaVuelos[cantVuelos].setDuracion(duracion);
    
    cantVuelos++; //contador de cantidad de vuelos
}

//función cargaDatosPasajero carga los datos de los pasajeros del archivo Pasajeros.txt
void cargaDatosPasajero(Pasajero listaPasj[], int &cantPasajeros){
    ifstream archPasajeros;
    archPasajeros.open("Pasajeros.txt");

    string nom;
    int numV;
    cantPasajeros = 0;

    while(archPasajeros >> nom >> numV){
        listaPasj[cantPasajeros].setNomPasajero(nom);
        listaPasj[cantPasajeros].setNumVueloPasj(numV);
        cantPasajeros++;
    }
    archPasajeros.close();
}

//la función cargaDatosVuelos carga los datos del vuelo del archivo Vuelos.txt
void cargaDatosVuelos(Vuelo listaVuelos[], int &cantVuelos){
    ifstream archVuelos;
    string nom;
    archVuelos.open("Vuelos.txt");

    cantVuelos = 0;
    int numVuelo, hrSalida, minSalida, duracion;
    while(archVuelos >> numVuelo >> hrSalida >> minSalida >> duracion){
        listaVuelos[cantVuelos].setNumVuelo(numVuelo);
        listaVuelos[cantVuelos].setHrSalida(hrSalida, minSalida);
        listaVuelos[cantVuelos].setDuracion(duracion);
        cantVuelos++;
    }
    archVuelos.close();
}

void muestraPasajVuelo(Pasajero listaPasaj[], int numVuelo, int cantPasajeros){
    for (int i=0; i < cantPasajeros; i++){
        if (listaPasaj[i].getNumVueloPasj() == numVuelo){
            cout << "Nombre: " << listaPasaj[i].getNomPasajero() << endl;
            //cout << " Vuelo: " << listaPasaj[i].getNumVueloPasj() << endl;
        }
    }
    cout << endl;
}

int main() {
    Vuelo listaVuelos[10];
    int cantVuelos;

    Pasajero listaPasaj[10];
    int cantPasajeros;

    char opcion;

    cargaDatosVuelos(listaVuelos, cantVuelos);
    cargaDatosPasajero(listaPasaj, cantPasajeros);

    do{
        cout << "a) consultar lista de vuelos\n";
        cout << "b) consultar lista de pasajeros\n";
        cout << "c) dar de alta un vuelo\n";
        cout << "d) muestra pasajeros en vuelo especifico\n";
        cout << "e) terminar\n";
        cin >> opcion;

        switch(opcion){
            case 'a':{
                muestraVuelos(listaVuelos, cantVuelos);
                break;
            }
            case 'b':{
                muestraPasajeros(listaPasaj, cantPasajeros);
                break;
            }
            case 'c':{
                registraVuelos(listaVuelos, cantVuelos);
                break;
            }
            case 'd':{
                int numVuelo;
                cout << "¿Qué vuelo desea ver? ";
                cin >> numVuelo;
                muestraPasajVuelo(listaPasaj, numVuelo, cantPasajeros);
                break;
            }
        }
    }while(opcion != 'e');
}
