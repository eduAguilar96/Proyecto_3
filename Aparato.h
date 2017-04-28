#ifndef Aparato_h
#define Aparato_h

#include "Servicio.h"
#include "Hora.h"

class Aparato: public Servicio {
public:
    //constructores
    Aparato() : Servicio(){
        costoX15min = 10.0;
        conInstructor = true;
        descripcion = "sin descripcion";
    }
    Aparato(string sclave, int itiempoMax, char ctipo, double costo, bool instr, string desc) : Servicio(sclave, itiempoMax, ctipo){
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
    
    double calculaCosto(int i){
        return i*costoX15min;
    }
    double calculaCosto(Hora i){
        return (i.getH()*60 + i.getM())%15 * costoX15min;
    }
    
private:
    double costoX15min;
    bool conInstructor;
    string descripcion;
    
};

#endif /* Aparato_h */
