
#include "Usluga.h"

Usluga::Usluga() {
    this->opisUsluge="Nista";
    this->cijena=0;
}

void Usluga::setOpis() {
    std::cout<<"Unesite opis usluge: ";
    std::getline(std::cin,this->opisUsluge);
}

void Usluga::setCijena() {
    std::cout<<"Unesite cijenu: ";
    std::cin>>this->cijena;
}

std::string Usluga::getOpis() {
    return this->opisUsluge;
}

double Usluga::getCijena() {
    return this->cijena;
}


std::istream & operator>>(std::istream &istream,Usluga &usluga){
    usluga.setOpis();
    usluga.setCijena();
    usluga.setStrucnjak();
    return istream;
}

void Usluga::setStrucnjak() {
    int x;
    do{
        std::cout<<"Za ovu uslugu je potreban (0-Manikir, 1-Pedikir): ";
        std::cin>>x;
    }while(x<0 || x>1);
    if(x==0){
        this->strucnjak="Manikir";
    }
    else{
        this->strucnjak="Pedikir";
    }
}

std::string Usluga::getStrucnjak() {
    return this->strucnjak;
}

void Usluga::setStrucnjakOcitavanje(std::string strucnjak) {
    this->strucnjak=strucnjak;

}

void Usluga::setCijenaOcitavanje(double cijena) {
    this->cijena=cijena;

}

void Usluga::setOpisOcitavanje(std::string opis) {
    this->opisUsluge=opis;

}
