#ifndef KLIJENT_H
#define KLIJENT_H

class Klijent : public Osoba {

public:
    Klijent(int ime, int godine);
    void prikaziInformacije() const override;
};
#endif

