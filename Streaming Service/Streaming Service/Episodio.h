//
//  Episodio.h
//  Situacion Problema
//
//  Created by Roby Saldana on 6/1/20.
//  Copyright © 2020 Roby Saldana. All rights reserved.
//

#ifndef Episodio_h
#define Episodio_h
#include "Video.h"

class Episodio : public Video{
public:
    Episodio();
    Episodio(int idV, string nom, string gen, double dur, int cali, string s, string nEp, string temp);
    //id video, nombre, genero, duración, calificación, serie, numero Episodio, temporada
    
    string getSerie() {return serie;}
    string getNumEp() {return numEp;}
    string getTemporada() {return temporada;}
    
    void setSerie(string s) {serie = s;}
    void setNumEp(string nEp) {numEp = nEp;}
    void setTemporada(string temp) {temporada = temp;}
    
    void muestra();
    
private:
    string serie, numEp, temporada;
};

Episodio::Episodio() : Video(){
    serie = '-';
    numEp = '-';
    temporada = '-';
}

Episodio::Episodio(int idV, string nom, string gen, double dur, int cali, string s, string nEp, string temp) : Video(idV, nom, gen, dur, cali){
    serie = s;
    numEp = nEp;
    temporada = temp;
}

void Episodio::muestra(){
    cout << left << setw(5) << idVideo << setw(35) << nombre << setw(18) << genero << setw(11) << duracion << setw(15) << calificacion << setw(10) << serie << setw(4) << temporada << setw(4) << numEp <<endl;
}

#endif /* Episodio_h */
