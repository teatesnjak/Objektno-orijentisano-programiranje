
#ifndef OOP_KOZMETICKISALON_H
#define OOP_KOZMETICKISALON_H

#include <vector>
#include <fstream>
#include "Usluga.h"
#include "Uposlenik.h"
class KozmetickiSalon {
private:
    std::vector<Usluga>usluge;
    std::vector<Uposlenik>uposlenici;
public:
    KozmetickiSalon();
    void dodajUsluge();
    void dodajZaposlenog();

    void oslobodiRadnika();
    void prikaziZaposlene();
    void odaberiUslugu();
    void sacuvajUslugeUFajl();
    void ucitajUslugeIzFajla();

    ~KozmetickiSalon(){};


};



#endif //OOP_KOZMETICKISALON_H
