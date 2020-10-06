//
//  Video.h
//  Situacion Problema
//
//  Created by Roby Saldana on 6/1/20.
//  Copyright © 2020 Roby Saldana. All rights reserved.
//

#ifndef Video_h
#define Video_h
#include <string>

class Video{
public:
    Video();
    Video(int idV, string nom, string gen, double dur, int cali);
    //id video, nombre, genero, duración, calificación
    
    int getIdVideo() {return idVideo;}
    string getNombre() {return nombre;}
    string getGenero() {return genero;}
    double getDuracion() {return duracion;}
    int getCalificacion() {return calificacion;}
    
    void setIdVideo(int idV) {idVideo = idV;}
    void setNombre(string nom) {nombre = nom;}
    void setGenero(string gen) {genero = gen;}
    void setDuracion(double dur) {duracion = dur;}
    void setCalificacion(int cali) {calificacion = cali;}
    
    virtual void muestra() = 0;
protected:
    int idVideo, calificacion;
    string nombre, genero;
    double duracion;
};

Video::Video(){
    idVideo = 0;
    nombre = '-';
    genero = '-';
    duracion = 0;
    calificacion = 0;
}

Video::Video(int idV, string nom, string gen, double dur, int cali){
    idVideo = idV;
    nombre = nom;
    genero = gen;
    duracion = dur;
    calificacion = cali;
}

#endif /* Video_h */
