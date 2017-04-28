/*
 main.cpp
 
 Proyecto_3 de la clasde de Programacion
 Orientada a Objetos. Progamada de un
 club deportivo
 
 Eduardo Aguilar Leal    A01193626
 27/04/2017
 
 version 1.0
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Hora.h"
#include "Reserva.h"
#include "Servicio.h"
#include "Aparato.h"
#include "Cancha.h"

/*
 ShowMenu
 
 Ense;a el menu principal
 
 Parametros:
 nada
 
 Return:
 nada   void
*/
void showMenu(){
    cout << "-------------------MENU-------------------" <<  endl;
    cout << endl;
    cout << "1. Consultar la lista de servicios" << endl;
    cout << "2. Consultar la lista de reservaciones" << endl;
    cout << "3. Consultar las reservaciones de un servicio dado" << endl;
    cout << "4. Consultar las reservaciones de una hora especsifica" << endl;
    cout << "5. Hacer una reservacion" << endl;
    cout << "6. Terminar" << endl;
    cout << endl;
    cout << "Porfavor ingrese el numero de la opcion que desee : ";
}

/*
 Consultar lista servicios
 
 Ense;a al usuarios todos los servicios
 
 Parametros:
 nada
 
 Return:
 nada   void
*/
void ConsultarListaServicios(){
}

/*
 Consultar lista reservaciones
 
 Ense;a al usuarios todos los reservaciones
 
 Parametros:
 nada
 
 Return:
 nada   void
 */
void ConsultarListaReservaciones(){
}

/*
 ConsultarReservacionesPorServicio
 
 Ense;a al todas las reservaciones por dicho servicio
 
 Parametros:
 nada
 
 Return:
 nada   void
 */
void ConsultarReservacionesPorServicio(string saux){
}

/*
 ConsultarReservacionesPorHora
 
 Ense;a al todas las reservaciones por dicha Hora
 
 Parametros:
 nada
 
 Return:
 nada   void
*/
void ConsultarReservacionesPorHora(Hora haux){
}
/*
 Main
 
 Inisializa variables, maneja logica basica
 y manda a llamar metodos
 
 Parametros:
 nada
 
 Return:
 0  con el fin de evtiar errores
*/
int main() {
    
    //inisialicion de arreglos
    Servicio *servicios[20];
    Reserva *reservaciones[40];
    
    //Manejo de documento
    ifstream arch1, arch2;
    arch1.open("Servicios.txt");
    arch2.open("Reserva.txt");
    
    //variables auxiliares
    string cveServicio, descripcion;
    int tiempoMax, costo, cantMaxPer, numServ = 0;
    char tipoServ, conIns;
    
    while(!arch1.eof()){
        arch1 >> cveServicio >> tiempoMax >> tipoServ;
        //si es aparato
        if(tipoServ == 'C' || tipoServ == 'E' || tipoServ == 'B'){
            arch1 >> costo >> conIns;
            getline(arch1, descripcion);
            //si tiene instructor
            if(conIns == 'T'){
                servicios[numServ] = new Aparato(cveServicio, tiempoMax, tipoServ, costo, true, descripcion);
            }else{
                servicios[numServ] = new Aparato(cveServicio, tiempoMax, tipoServ, costo, false, descripcion);
            }
        //si es cancha
        }else{
            arch1 >> costo >> cantMaxPer;
            getline(arch1, descripcion);
            servicios[numServ] = new Cancha(cveServicio, tiempoMax, tipoServ, costo, cantMaxPer, descripcion);
        }
        numServ++;
    }
    
    //variables auxiliares
    string clave;
    int id, duracion, hh, mm, numRes = 0;
    Hora haux;
    
    //cargar arreglo de reservaciones
    while(!arch2.eof()){
        arch2 >> clave >> hh >> mm >> duracion >> id;
        haux.setH(hh);
        haux.setM(mm);
        reservaciones[numRes] = new Reserva(clave,id,haux,duracion);
        
        numRes++;
    }
    
    int iOpt = 0;
    
    while(iOpt != 6 ){
        
        //showMenu();
        cin >> iOpt;
        
        switch (iOpt) {
            case 1:
                ConsultarListaServicios();
                break;
                
            case 2:
                ConsultarListaReservaciones();
                break;
                
            case 3:{
                string claveServ;
                ConsultarReservacionesPorServicio(claveServ);
                break;}
                
            case 4:{
                Hora haux;
                ConsultarReservacionesPorHora(haux);
                break;}
                
            case 5:
                
                break;
                
            case 6:
                cout << "Saliendo de la applicacion" << endl;
                break;
                
            default:
                cout << "Esa opcion es invalida" << endl;
                break;
        }
    }
    return 0;
}
