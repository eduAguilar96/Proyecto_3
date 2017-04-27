//
//  Aparato.h
//  Proyecto_3
//
//  Created by Eduardo on 4/27/17.
//  Copyright © 2017 Eduardo Aguilar. All rights reserved.
//

#ifndef Aparato_h
#define Aparato_h

#include "Servicio.h"

class Aparato: public Servicio {
    //constructores
    Aparato() : Servicio(){
        costoX15min = 10.0;
        conInstructor = true;
        descripcion = "sin descripcion";
    }
    Aparato(string saux, int iaux, char caux, double costo, bool instr, string desc) : Servicio(saux, iaux, caux){
        costoX15min = costo;
        conInstructor = instr;
        descripcion = desc;
    }
    
    //metodos
    void Muestra(){
        cout << "Aparato" << endl;
        cout << "Clave: " << clave << endl;
        cout << "Tiempo Maximo: " << tiempoMax << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Costo por 15 min: " << costoX15min << endl;
        cout << "Con Instructor?: ";
        if (conInstructor){
            cout << "Si";
        }else{
            cout << "No";
        }
        cout << endl;
        cout << "Descripcion: " << descripcion << endl;
    }
    
    double calculaCosto(){
        
    }
    
private:
    double costoX15min;
    bool conInstructor;
    string descripcion;
    
};

#endif /* Aparato_h */
