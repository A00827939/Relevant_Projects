//
//  main.cpp
//  Situacion Problema
//
//  Created by Roby Saldana on 6/1/20.
//  Copyright © 2020 Roby Saldana. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <typeinfo>
//#include <typeinfo>
using namespace std;
#include <string>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"

//1. Mostrar la lista de películas
void muestraPeliculas(Video *listaVideos[], int c){
    cout << left << setw(5) << "Id" << setw(35) << "Nombre" << setw(18) << "Genero" << setw(11) << "Duración" << setw(15) << "Calificación" << endl;
    for (int i = 0; i < c; i++){
        if (typeid(*listaVideos[i]) == typeid(Pelicula)) {
            listaVideos[i] -> muestra();
        }
    }
}

//2. Mostrar la lista de series
void muestraSeries(int idSerie[], string nombreSerie[], int cantSeries){
    cout << left << setw(12) << "Id Serie" << setw(15) << "Nombre Serie" << endl;
    for (int i = 0; i < cantSeries; i++){
        cout << setw(12) << idSerie[i] << setw(15) << nombreSerie[i] << endl;
    }
}

//3. Mostrar los videos en general con una cierta calificación
void muestraCalificacion(Video *listaVideos[], int c){
    int calificacion;
    cout << "¿Qué calificación de videos quieres ver? (1-5): ";
    cin >> calificacion;
    cout << left <<setw(5) << "Id" << setw(35) << "Nombre" << setw(18) << "Genero" << setw(11) << "Duración" << setw(17) << "Calificación" << setw(10) << "Serie" << endl;
    for (int i = 0; i < c; i++){
        if (listaVideos[i] -> getCalificacion() == calificacion){
            listaVideos[i] -> muestra();
        }
    }
}

//4. Mostrar los videos en general de un cierto género
void muestraGenero(Video *listaVideos[], int c){
    string genero;
    cout << "¿Qué genero de videos quieres ver?" << endl;
    cout << "Opciones: Drama, Accion, Misterio, Comedia, Ciencia_ficcion, Animacion, Musical" << endl;
    cin >> genero;
    cout << left << setw(5) << "Id" << setw(35) << "Nombre" << setw(18) << "Genero" << setw(11) << "Duración" << setw(17) << "Calificación" << setw(10) << "Serie" << endl;
    for (int i = 0; i < c; i++){
        if (listaVideos[i] -> getGenero() == genero){
            listaVideos[i] -> muestra();
        }
    }
}

//5. Mostrar los episodios de una determinada serie con sus calificaciones
void muestraEpSerieCal(Video *listaVideos[], int c){
    int califiacion;
    Episodio *epserie;
    string test;
    string serie;
    cout << "¿Qué serie quieres ver? ";
    cin >> serie;
    cout << endl;
    cout << "¿Qué calificación de episodios quieres ver? (1-5) ";
    cin >> califiacion;
    
    cout << left << setw(5) << "Id" << setw(35) << "Nombre" << setw(18) << "Genero" << setw(12) << "Duración" << setw(16) << "Calificación" << setw(10) << "Serie" << endl;
    for (int i = 0; i < c; i++){
        if (typeid(*listaVideos[i]) == typeid(Episodio)){
            epserie = (Episodio *) listaVideos[i];
            if ((epserie -> getSerie() == serie) && listaVideos[i] -> getCalificacion() == califiacion){
                listaVideos[i] -> muestra();
            }
        }
    }
}

//6. Mostrar las películas con cierta calificación
void muestraPelCal(Video *listaVideos[], int c){
    int calificacion;
    cout << "¿Qué calificación de pelicula deseas ver? (1-5) ";
    cin >> calificacion;
    cout << left << setw(5) << "Id" << setw(35) << "Nombre" << setw(18) << "Genero" << setw(11) << "Duración" << setw(15) << "Calificación" << setw(10) << endl;
    for (int i = 0; i < c; i++){
        if ((typeid(*listaVideos[i]) == typeid(Pelicula) && listaVideos[i] -> getCalificacion() == calificacion)){
            listaVideos[i] -> muestra();
        }
    }
}

int main() {
    ifstream arch, series;
    arch.open("datosVideos.txt");
    series.open("series.txt");
    char tipoVideo;
    int idVideo, calificacion, idSerie[10], idS, cantSeries = 0, opcionMenu;
    string nombre, genero, serie, nombreSerie[10], nomS, numEp, temporada;
    double duracion;
    Video *listaVideos[100];
    int c = 0;
    
    while (arch >> tipoVideo){
        if (tipoVideo == 'p'){
            arch >> idVideo >> nombre >> genero >> duracion >> calificacion;
            listaVideos[c] = new Pelicula(idVideo, nombre, genero, duracion, calificacion);
        }
        else if (tipoVideo == 'e'){
            arch >> idVideo >> nombre >> genero >> duracion >> calificacion >> serie >> numEp >> temporada;
            listaVideos[c] = new Episodio(idVideo, nombre, genero, duracion, calificacion, serie, numEp, temporada);
        }
        c++;
    }
    while (series >> idS >> nomS){
        idSerie[cantSeries] = idS;
        nombreSerie[cantSeries] = nomS;
        cantSeries++;
    }
    
    do
    {
        cout << endl;
        cout << "Menu de opciones " << endl;
        //cout << endl;
        cout << "1) muestra lista de películas " << endl;
        cout << "2) muestra lista de series " << endl;
        cout << "3) muestra los videos en general con cierta calificación " << endl;
        cout << "4) muestra los videos en general con cierto género" << endl;
        cout << "5) muestra los episodios de una determinada serie con sus calificaciones" << endl;
        cout << "6) muestra las peliculas con cierta calificación" << endl;
        cout << "0) Salir" << endl;
        cout << endl;
        cout << "opcion -> " << endl;
        cin >> opcionMenu;
        
        switch (opcionMenu) {
            case 1: {
                muestraPeliculas(listaVideos,  c);
                break;
            }
            case 2: {
                muestraSeries(idSerie, nombreSerie,  cantSeries);
                break;
            }
            case 3: {
                muestraCalificacion(listaVideos, c);
                break;
            }
            case 4: {
                muestraGenero(listaVideos, c);
                break;
            }
            case 5: {
                muestraEpSerieCal(listaVideos,  c);
                break;
            }
            case 6: {
                muestraPelCal(listaVideos, c);
                break;
            }
        }
    } while (opcionMenu != 0);
    return 0;
}
