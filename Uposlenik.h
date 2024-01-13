#ifndef OOP_UPOSLENIK_H
#define OOP_UPOSLENIK_H

#include "Osoba.h"
enum Pozicija{Manikir,Pedikir,Recepcija};
class Uposlenik : public Osoba{
private:

    double plata;
    Pozicija pozicija;
    bool zauzet;
public:
    void setPlata();
    void setPozicija();
    std::string vratiPoziciju(Pozicija poz);
    void promjeniStanje();

    bool getStanje();
    void setIme(const std::string& ime) {
        Osoba::setIme(ime);
    }
    void setGodine(int godine){
        if(godine<=0){
            std::cout<<"Godine su manje ili jednake nuli!";
            return;
        } else{
            Osoba::setGodine(godine);
        }
    }

    void postaviUposlenika();

    double getPlata();
    Pozicija getPozicija();



};


#endif //OOP_UPOSLENIK_H
