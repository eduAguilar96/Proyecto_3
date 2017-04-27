#ifndef Cancha_h
#define Cancha_h

#include <string>
#include "Servicio.h"
class Cancha : public Servicio{
public:
    //constructores
    Cancha() : Servicio(){
        costoXHr = 10.0;
        cantMaxPers = 20;
        deporte = "Segway Polo";
    }
    Cancha(string saux, int iaux, char caux, double costo, int maxp, string depor) : Servicio(saux, iaux, caux){
        costoXHr = costo;
        cantMaxPers = maxp;
        deporte = depor;
    }
    
    //metodos
    void Muestra(){
        cout << "Cancha" << endl;
        cout << "Clave: " << clave << endl;
        cout << "Tiempo Maximo: " << tiempoMax << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Costo por Hora: " << costoXHr << endl;
        cout << "Cantidad Maxima de Personas: " << cantMaxPers << endl;
        cout << "Deporte: " << deporte << endl;
    }
    
    double calculaCosto(int i){
        return i*costoXHr;
    }
    double calculaCosto(Hora i){
        return (i.getH() + i.getM()/60) * costoXHr;
    }
    
private:
    double costoXHr;
    int cantMaxPers;
    string deporte;

};
#endif /* Cancha_h */
