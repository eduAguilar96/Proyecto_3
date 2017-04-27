//
//  Servicio.h
//  Proyecto_3
//
//  Created by Eduardo on 4/27/17.
//  Copyright © 2017 Eduardo Aguilar. All rights reserved.
//

#ifndef Servicio_h
#define Servicio_h

class Servicio{
public:
    //metodos virtuales
    virtual void Muestra() = 0;
    virtual double calculaCosto() = 0;
    
    //constructores
    Servicio(){
        clave = "clave";
        tiempoMax = 0;
        tipo = 'A';
    }
    Servicio(string saux, int iaux, char caux){
        clave = saux;
        tiempoMax = iaux;
        tipo = caux;
    }
    
    //geters
    string getClave(){
        return clave;
    }
    int getTiempoMax(){
        return tiempoMax;
    }
    char getTipo(){
        return tipo;
    }
    
    //seters
    void setClave(string saux){
        clave = saux;
    }
    void setTiempoMax(int iaux){
        tiempoMax = iaux;
    }
    void setTipo(char caux){
        tipo = caux;
    }
    
protected:
    string clave;
    int tiempoMax;
    char tipo;
};


#endif /* Servicio_h */
