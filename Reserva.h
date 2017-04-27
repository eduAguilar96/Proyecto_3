//
//  Reserva.h
//  Proyecto_3
//
//  Created by Eduardo on 4/27/17.
//  Copyright © 2017 Eduardo Aguilar. All rights reserved.
//

#ifndef Reserva_h
#define Reserva_h

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
        return hAux;
    }
    void Reserva::setHoraInicio(Hora hAux)
    {
        hHoraInicio.setHh(hAux.getHh());
        hHoraInicio.setHh(hAux.getMm());
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
        hHoraInicio.setHh(hAux.getHh());
        hHoraInicio.setHh(hAux.getMm());
        iDuracion = iAux2;
    }

#endif /* Reserva_h */
