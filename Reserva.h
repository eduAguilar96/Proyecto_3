#ifndef Reserva_h
#define Reserva_h

#include "Hora.h"

class Reserva
{
    public:
        //Metodos de acesso
        string getClaveServicio();
        void setClaveServicio(string sAux);
        int getIdCliente();
        void setIdCliente(int iAux);
        Hora getHoraInicio();
        void setHoraInicio(Hora hAux);
        int getDuracion();
        void setDuracion(int iAux);
        //Constructores
        Reserva();
        Reserva(string sAux, int iAux, Hora hAux, int iAux2);
    private:
        string sClaveServicio;
        int iIdCliente;
        Hora hHoraInicio;
        int iDuracion;
};

    string Reserva::getClaveServicio()
    {
        return sClaveServicio;
    }
    void Reserva::setClaveServicio(string sAux)
    {
        sClaveServicio = sAux;
    }
    int Reserva::getIdCliente()
    {
        return iIdCliente;
    }
    void Reserva::setIdCliente(int iAux)
    {
        iIdCliente = iAux;
    }
    Hora Reserva::getHoraInicio()
    {
        return hHoraInicio;
    }
    void Reserva::setHoraInicio(Hora hAux)
    {
        hHoraInicio.setH(hAux.getH());
        hHoraInicio.setM(hAux.getM());
    }
    int Reserva::getDuracion()
    {
        return iDuracion;
    }
    void Reserva::setDuracion(int iAux)
    {
        iDuracion = iAux;
    }
    Reserva::Reserva()
    {
        sClaveServicio = "Sin Clave";
        iIdCliente = 0;
        iDuracion = 0;
    }
    Reserva::Reserva(string sAux, int iAux, Hora hAux, int iAux2)
    {
        sClaveServicio = sAux;
        iIdCliente = iAux;
        hHoraInicio.setH(hAux.getH());
        hHoraInicio.setH(hAux.getM());
        iDuracion = iAux2;
    }

#endif /* Reserva_h */
