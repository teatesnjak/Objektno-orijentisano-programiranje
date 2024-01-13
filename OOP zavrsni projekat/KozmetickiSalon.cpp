//
// Created by toshiba on 11. 1. 2024..
//

#include "KozmetickiSalon.h"
#include "KozmetickiSalon.h"
#include <memory>
#include <sstream>

void KozmetickiSalon::dodajUsluge() {
    Usluga usluga;
    std::cin>>usluga;
    this->usluge.push_back(usluga);

}

void KozmetickiSalon::dodajZaposlenog() {

    std::shared_ptr<Uposlenik> u1= std::make_shared<Uposlenik>();
    u1->postaviUposlenika();
    this->uposlenici.push_back(*u1);
}

void KozmetickiSalon::prikaziZaposlene() {
    try {
        if (uposlenici.empty()) {
            std::cout << "Nema uposlenika!";
            return;
        } else {
            for (int i = 0; i < uposlenici.size(); i++) {
                std::cout << i + 1 << ". " << uposlenici[i].getIme() << " " << uposlenici[i].getGodine() << " godine (";
                std::cout << uposlenici[i].vratiPoziciju(uposlenici[i].getPozicija()) <<")"<< std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Greska prilikom prikazivanja zaposlenih: " << e.what() << std::endl;
    }
}


void KozmetickiSalon::odaberiUslugu() {
    if(usluge.empty()){
        std::cout<<"Nema usluga za odabir!";
        return;
    } else{
        for (int i = 0; i < usluge.size(); i++) {
            std::cout<<i+1<<". " << usluge[i].getOpis() << " " << usluge[i].getStrucnjak() <<" , usluga kosta: "<<usluge[i].getCijena()<<"KM" <<std::endl;
        }
        int x;
        do{
            std::cout<<"Odaberite redni broj pored usluge: ";
            std::cin>>x;
        }while(x<1 || x>usluge.size());
        x=x-1;
        bool postoji= true;
        for (int i=0;i<uposlenici.size();i++){
            if(uposlenici[i].vratiPoziciju(uposlenici[i].getPozicija())==usluge[x].getStrucnjak() && (uposlenici[i].getStanje()==false) ){
                std::cout<<uposlenici[i].getIme()<< " " << uposlenici[i].getGodine() << " godine ";
                std::cout<<"("<<uposlenici[i].vratiPoziciju(uposlenici[i].getPozicija())<<")" << " - ce vas uskoro usluziti!";
                uposlenici[i].promjeniStanje();
                postoji= false;
            }
        }
        if(postoji){
            std::cout<<"Trenutno nema uposlenika koji moze obaviti taj posao.";
        }
    }
}

void KozmetickiSalon::oslobodiRadnika() {
    if(!uposlenici.empty()){
        this->prikaziZaposlene();
        int x;
        do{
            std::cout<<"Unesite index pored osobe kojoj zelite stanje promijeniti: ";
            std::cin>>x;
        }while(x<1 || x>uposlenici.size());
        x=x-1;
        if(uposlenici[x].getStanje()== false){
            std::cout<<"Uposlenik je sada zauzet.";
            this->uposlenici[x].promjeniStanje();
        } else{
            uposlenici[x].promjeniStanje();
            std::cout<<"Uposlenik je sada slobodan.";
        }
    } else{
        std::cout<<"Nema uposlenika!";
    }
}

KozmetickiSalon::KozmetickiSalon() {

}

void KozmetickiSalon::sacuvajUslugeUFajl()  {
    std::ofstream file("usluge.txt");

    if (file.is_open()) {
        for ( auto& usluga : usluge) {
            file << usluga.getOpis() << "," << usluga.getCijena() << ","<<usluga.getStrucnjak()<<std::endl;
        }
        std::cout << "Podaci o uslugama su  sacuvani u usluge.txt." << std::endl;
    } else {
        std::cerr << "Greska prilikom otvaranja datoteke usluge.txt za pisanje." << std::endl;
    }
}

void KozmetickiSalon::ucitajUslugeIzFajla() {

    std::ifstream file("usluge.txt");

    if (file.is_open()) {
        std::string linija;

        while (std::getline(file, linija)) {
            std::istringstream ss(linija);
            std::string opis;
            double cijena;
            std::string strucnjak;


            if (std::getline(ss, opis, ',') && ss >> cijena && ss.ignore() && std::getline(ss, strucnjak)) {
                Usluga u1;
                u1.setStrucnjakOcitavanje(strucnjak);
                u1.setCijenaOcitavanje(cijena);
                u1.setOpisOcitavanje(opis);
                usluge.push_back(u1);
            } else {
                std::cerr << "Greska prilikom parsiranja linije: " << linija << std::endl;
            }
        }

        std::cout << "Podaci o uslugama su uspjesno ucitani iz usluge.txt." << std::endl;
    } else {
        std::cerr << "Greska prilikom otvaranja datoteke usluge.txt za citanje." << std::endl;
    }
}




