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

 Return:git push --set-upstream origin devCD
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

 Enseña al todas las reservaciones por dicho servicio

 Parametros:
 El arreglo de reservaciones, el arreglo de servicios y el numero de reservaciones

 Return:
 nada   void
 */
    void ConsultarReservacionesPorServicio(Servicio *serv[], Reserva *res[], int iNumServ){
        bool bExiste = false;
        string claveServ;
        // ciclo para verificar si la clave del espectador exista
        do{
            cout << "Porfavor ingrese la clave del servicio: " << endl;
            cin >> claveServ;
            cin.ignore();
            // ciclo que compara clave introducida con todas las que existen el los objetos de tipo espectadores
                for(int i = 0; i < 20; i++){
                    if (claveServ == serv[i]->getClave())
                    {
                        bExiste=true;
                        serv[i]->Muestra();
                        cout << endl;
                    }
                }
            if(bExiste == false)
                cout << "No existe una esa clave. Intentelo de nuevo" << endl;
        }while(bExiste==false);

        for(int i = 0; i < iNumServ; i++)
        {
            if (claveServ == res[i]->getClaveServicio())
            {
                Hora haux;
                haux.setM(res[i]->getHoraInicio().getM());
                haux.setH(res[i]->getHoraInicio().getH());
                cout << "Hora de Inicio: "<< haux << endl;
                haux.setM(res[i]->CalculaHoraFinReservacion().getM());
                haux.setH(res[i]->CalculaHoraFinReservacion().getH());
                cout << "Hora de terminacion: " << haux << endl;
                cout << endl;
            }
        }

    }

/*
 ConsultarReservacionesPorHora

 Ense;a al todas las reservaciones por dicha Hora

 Parametros:
 nada

 Return:
 nada   void
*/
void ConsultarReservacionesPorHora(Reserva *res[]){
    Hora haux;
    cout << "Porfavor ingrese la hora a buscar" << endl;
    cin >> haux;
    cout << haux << endl;
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
                ConsultarReservacionesPorServicio(servicios, reservaciones, numRes);
                break;}

            case 4:{
                ConsultarReservacionesPorHora(reservaciones);
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
