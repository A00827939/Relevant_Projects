//
//  Pasajero.h
//  AAA PROYECTO INTEGRADOR
//
//  Created by Roby Saldana on 12/2/19.
//  Copyright © 2019 Roby Saldana. All rights reserved.
//

#ifndef Pasajero_h
#define Pasajero_h

class Pasajero{
public:
    Pasajero();
    Pasajero(string nom, int numV);
    void setNomPasajero(string nom);
    void setNumVueloPasj(int numV);
    string getNomPasajero();
    int getNumVueloPasj();
private:
    string nomPasajero;
    int numVuelo;
};
Pasajero::Pasajero(){
    nomPasajero = "-";
    numVuelo = 0;
}
Pasajero::Pasajero(string nom, int numV){
    nomPasajero = nom;
    numVuelo = numV;
}
void Pasajero::setNomPasajero(string nom){
    nomPasajero = nom;
}
void Pasajero::setNumVueloPasj(int numV){
    numVuelo = numV;
}
string Pasajero::getNomPasajero(){
    return nomPasajero;
}
int Pasajero::getNumVueloPasj(){
    return numVuelo;
}

#endif /* Pasajero_h */
