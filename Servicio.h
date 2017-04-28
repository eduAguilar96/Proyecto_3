#ifndef Servicio_h
#define Servicio_h

class Servicio{
public:
    //metodos virtuales
    virtual void Muestra() = 0;
    virtual double calculaCosto(int) = 0;
    
    //constructores
    Servicio(){
        clave = "clave";
        tiempoMax = 0;
        tipo = 'A';
    }
    Servicio(string sclave, int iTiempoMax, char cTipo){
        clave = sclave;
        tiempoMax = iTiempoMax;
        tipo = cTipo;
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
