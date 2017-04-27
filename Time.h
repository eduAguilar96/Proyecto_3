#ifndef Hora_h
#define Hora_h

class Hora {
public:
    //Constructores
    Tiempo(){
        mm = 0;
        hh = 0;
    }
    Tiempo(int h, int m){
        mm = m;
        hh = h;
    }
    //Getters y seters
    void setH(int h){
        hh = h;
    }
    void setM(int m){
        mm = m;
    }
    int getH(){
        return hh;
    }
    int getM(){
        return mm;
    }
    //Muestra
    void muestra()
    {
        cout << hh << ":";
        
        if (mm < 10){
            cout << "0";
        }
        cout << mm << ":";
    }
    
    //Metodos de sobrecarga
    Tiempo operator+ (Tiempo T1, int m){
        
        Tiempo aux;
        int i;
        
        //igualacion
        aux.hh = T1.hh;
        aux.mm = T1.mm + m;
        
        //validacion
        if (aux.mm > 59){
            i = aux.mm % 60;
            aux.mm -= 60*i;
            aux.hh += i;
        }
        
        return aux;
    }
    
    bool operator>= (Tiempo T){
        
        if(hh*60 + mm >= T.hh*60 + T.mm){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool operator<= (Tiempo T){
        
        if(hh*60 + mm <= T.hh*60 + T.mm){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool operator== (Tiempo T){
        
        if(hh*60 + mm == T.hh*60 + T.mm){
            return true;
        }
        else{
            return false;
        }
    }
    
private:
    int hh, mm, ss;
};

#endif
