#ifndef OOP_OSOBA_H
#define OOP_OSOBA_H

#include <iostream>
class Osoba {
private:
    std::string ime;
    int godine;
public:
    Osoba();
    virtual void setIme(std::string ime);
    virtual void setGodine(int godine);
    int getGodine();
    std::string getIme();
    ~Osoba()=default;
};


#endif //OOP_OSOBA_H
