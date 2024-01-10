#include "Klijent.h"
using namespace std;

Klijent::Klijent(int ime, int godine) : Osoba(ime, godine) {}

void Klijent::prikaziInformacije() const {
    Osoba::prikaziInformacije();
}

/*obavezno napraviti Osoba!!! i staviti prikazi informacije te iz nje uzeti ime i prezime
napraviti za rezervacije funkcije ako moze ikako da i to dodamo */