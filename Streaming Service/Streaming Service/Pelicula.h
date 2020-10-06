//
//  Pelicula.h
//  Situacion Problema
//
//  Created by Roby Saldana on 6/1/20.
//  Copyright © 2020 Roby Saldana. All rights reserved.
//

#ifndef Pelicula_h
#define Pelicula_h

#include "Video.h"

class Pelicula : public Video{
public:
    Pelicula();
    Pelicula(int idV, string nom, string gen, double dur, int cali);
    
    void muestra();
};

Pelicula::Pelicula() : Video(){
    
}

Pelicula::Pelicula(int idV, string nom, string gen, double dur, int cali) : Video(idV, nom, gen, dur, cali){
}

void Pelicula::muestra(){
    cout << left << setw(5) << idVideo << setw(35) << nombre << setw(18) << genero << setw(11) << duracion << setw(15) << calificacion << endl;
}
#endif /* Pelicula_h */
