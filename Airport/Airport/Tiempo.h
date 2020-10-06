//
//  Tiempo.h
//  PROYECTO INTEGRADOR
//
//  Created by Roby Saldana on 11/30/19.
//  Copyright © 2019 Roby Saldana. All rights reserved.
//

#ifndef Tiempo_h
#define Tiempo_h

class Tiempo {
public:
    Tiempo();
    Tiempo(int h, int m);
    void setHora(int h);
    void setMin(int m);
    int getHora();
    int getMin();
private:
    int hora, min;
};

Tiempo::Tiempo() {
    hora = 0;
    min = 0;
}

Tiempo::Tiempo(int h, int m) {
    hora = h;
    min = m;
}


void Tiempo::setHora(int h) {
    hora = h;
}

void Tiempo::setMin(int m) {
    min = m;
}

int Tiempo::getHora() {
    return hora;
}

int Tiempo::getMin() {
    return min;
}

#endif /* Tiempo_h */
