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
void ConsultarListaServicios(Servicio *serv[]){
    for(int i = 0; i < 20; i++){
        serv[i]->Muestra();
        cout << endl;
    }
}

/*
 Consultar lista reservaciones

 Ense;a al usuarios todos los reservaciones

 Parametros:
 nada

 Return:
 nada   void
 */
void ConsultarListaReservaciones(Reserva *res[]){
    for(int i = 0; i < 7; i++){
        cout << "Clave: " << res[i]->getClaveServicio() << endl;
        cout << "Id del cliente: " << res[i]->getIdCliente() << endl;
        Hora haux;
        haux.setM(res[i]->getHoraInicio().getM());
        haux.setH(res[i]->getHoraInicio().getH());
        cout << "Hora de Inicio: "<< haux << endl;
        cout << "Duracion: "<< res[i]->getDuracion() << endl;
        haux.setM(res[i]->CalculaHoraFinReservacion().getM());
        haux.setH(res[i]->CalculaHoraFinReservacion().getH());
        cout << "Hora de terminacion: " << haux << endl;
        cout << endl;
    }
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
    cout << "test" << endl;
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
 Hacer reservacion
 
 Crea una reservacion y la actualiza en el txt
 
 Parametros:
 muchos
 
 Return:
 nada   void
 */
bool HacerReservacion(int idCliente, string claveServ, Hora haux, int duracion, int numRes, Reserva *reservaciones[],Servicio *servicios[], Reserva &reservacion){
    //variables auxiliares
    bool b = true, a = true;
    char input;
    int indiceServ = 0;
    
    cout << endl;
    
    //verificar que la clave del servicio exista
    while(b){
        for(int i = 0;i < 20 && b; i++){
            if(servicios[i]->getClave() == claveServ){
                b = false;
                indiceServ = i;
            }
        }
        if(b){
            cout << "Esa clave no existe" << endl;
            cout << "Porfavor reingrese la clave :";
            cin >> claveServ;
        }
    }
    
    cout << "Usted quiere reservar... " << endl;
    servicios[indiceServ]->Muestra();
    cout << "...una duracion de " << duracion << endl;
    
    b = true;
    
    while(duracion > servicios[indiceServ]->getTiempoMax() && b){
        cout << "la cual exide el tiempo maximo" << endl;
        cout << "Desea rentarlo por menos tiempo?[y/n]" << endl;
        cin >> input;
        if(input == 'y' || input == 'Y'){
            cout << "Porfavor ingrese la duracion: ";
            cin >> duracion;
        }else{
            b = false;
            a = false;
        }
    }
    
    
    if(!b || a){
        for(int i = 0; i < numRes && a; i++){
            //checar si hora de incio no esta entre otra horaa de incio y finalizar
            // y checar si hora de finalizar no esta entre otra hora de incio y finalizar
            //y checar si concuerdan los codigos de servicio

            //codigo de servicio concuerda
            if(reservaciones[i]->getClaveServicio() == claveServ){
                cout << "mismo codigo" << endl;
                //hora de incio entre horas
                if((reservaciones[i]->getHoraInicio() <= haux &&
                    haux <=reservaciones[i]->CalculaHoraFinReservacion())
                    ||
                    (reservaciones[i]->getHoraInicio() <= haux+duracion &&
                    haux+duracion <=reservaciones[i]->CalculaHoraFinReservacion())){
                        a = false;
                }
            }
        }
        if(!a){
            cout << "Esa hora y duracion no esta disponible" << endl;
        }
    }
    
    reservacion.setDuracion(duracion);
    reservacion.setHoraInicio(haux);
    
    return a;
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
    
    arch1.close();
    arch2.close();
    
    int iOpt = 0;

    while(iOpt != 6 ){

        showMenu();
        cin >> iOpt;

        switch (iOpt) {
            case 1:
                ConsultarListaServicios(servicios);
                break;

            case 2:
                ConsultarListaReservaciones(reservaciones);
                break;

            case 3:{
                string claveServ;
                ConsultarReservacionesPorServicio(claveServ);
                break;}

            case 4:{
                Hora haux;
                ConsultarReservacionesPorHora(haux);
                break;}

            case 5:{
                if(numRes < 40){
                    string claveServ;
                    int hh = 25, mm = 60, idCliente, duracion;
                    cout << "Porfavor ingrese su ID de cliente: ";
                    cin >> idCliente;
                    cout << "Porfavor ingrese la clave del servicio: ";
                    cin >> claveServ;
                    while(hh > 24){
                        cout << "Porfavor ingrese la hora (hh) de inicio: ";
                        cin >> hh;
                        if(hh > 24){cout << "Ese numero es invalido" << endl;}
                    }
                    while(mm > 59){
                        cout << "Porfavor ingrese la hora (mm) de inicio: ";
                        cin >> mm;
                        if(hh > 59){cout << "Ese numero es invalido" << endl;}
                    }
                    Hora haux(hh,mm);
                    cout << "Porfavor ingrese la duracion: ";
                    cin >> duracion;
                    Reserva reservacion(claveServ,idCliente,haux,duracion);
                    if(HacerReservacion(idCliente,claveServ,haux,duracion, numRes,reservaciones,servicios, reservacion)){
                        reservaciones[numRes] = &reservacion;
                        numRes++;
                        cout << reservacion.getIdCliente() << endl;
                    }
                }else{
                    cout << "El cupo limitado de reservaciones se a agotado" << endl;
                }

                break;}

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
