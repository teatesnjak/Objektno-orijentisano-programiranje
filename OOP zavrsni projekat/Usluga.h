
#ifndef OOP_USLUGA_H
#define OOP_POMOC_USLUGA_H

#include <iostream>
class Usluga {
private:
    std::string opisUsluge;
    double cijena;
    std::string strucnjak;
public:
    Usluga();
    void setOpis();
    void setCijena();
    void setStrucnjak();

    void setStrucnjakOcitavanje(std::string  strucnjak);
    void setCijenaOcitavanje(double cijena);
    void setOpisOcitavanje(std::string opis);

    std::string getStrucnjak();
    std::string getOpis();
    double getCijena();

    friend std::istream & operator>>(std::istream &istream, Usluga &usluga );
    ~Usluga(){};
};


#endif //OOP_USLUGA_H
