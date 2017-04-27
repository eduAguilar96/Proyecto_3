#ifndef Hora_h
#define Hora_h

class Hora {
public:
    //Constructores
    Hora(){
        mm = 0;
        hh = 0;
    }
    Hora(int h, int m){
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
    friend Hora operator+ (Hora H1, int m){
        
        Hora aux;
        int i;
        
        //igualacion
        aux.hh = H1.hh;
        aux.mm = H1.mm + m;
        
        //validacion
        if (aux.mm > 59){
            i = aux.mm % 60;
            aux.mm -= 60*i;
            aux.hh += i;
        }
        
        return aux;
    }
    
    bool operator>= (Hora T){
        
        if(hh*60 + mm >= T.hh*60 + T.mm){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool operator<= (Hora T){
        
        if(hh*60 + mm <= T.hh*60 + T.mm){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool operator== (Hora T){
        
        if(hh*60 + mm == T.hh*60 + T.mm){
            return true;
        }
        else{
            return false;
        }
    }
    
    friend ostream& operator<< (ostream &salida, Hora &aux){
        salida << aux.hh << ":" << aux.mm;
        return salida;
    }
    
    friend istream& operator>> (istream &entrada, Hora &aux){
        entrada >> aux.hh;
        entrada >> aux.mm;
        return entrada;
    }
    
private:
    int hh, mm, ss;
};

#endif
