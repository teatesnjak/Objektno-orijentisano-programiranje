
#include "Uposlenik.h"

void Uposlenik::setPlata() {
    std::cout<<"Unesite platu uposlenika: ";
    std::cin>>this->plata;

}

void Uposlenik::setPozicija() {
    int x;
    do{
        std::cout<<"Unesite poziciju uposlenika! (0-Manikir, 1-Pedikir ,2-Recepcija): ";
        std::cin>>x;
    }while(x<0 || x>2);
    this->pozicija=static_cast<Pozicija>(x);
}

double Uposlenik::getPlata() {
    return this->plata;
}

Pozicija Uposlenik::getPozicija() {
    return this->pozicija;
}

void Uposlenik::postaviUposlenika() {
    std::string ime;
    std::cout<<"Unesite ime uposlenika: ";
    std::cin.ignore();
    std::getline(std::cin,ime);
    this->setIme(ime);
    int x;
    std::cout<<"Unesite godine uposlenika: ";
    std::cin>>x;
    this->setGodine(x);
    this->setPozicija();
    this->setPlata();
    this->zauzet= false;

}

std::string Uposlenik::vratiPoziciju(Pozicija poz) {
    if(poz==Manikir){
        return "Manikir";
    } else if (poz==Pedikir){
        return "Pedikir";
    } else{
        return "Recepcija";
    }
}

void Uposlenik::promjeniStanje() {
    this->zauzet=!this->zauzet;

}

bool Uposlenik::getStanje() {
    return this->zauzet;
}
