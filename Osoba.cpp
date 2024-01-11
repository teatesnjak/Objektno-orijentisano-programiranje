
#include "Osoba.h"

Osoba::Osoba() {
    this->ime="Samra Smajic";
    this->godine=0;

}

void Osoba::setIme(std::string ime) {
    this->ime=ime;

}

void Osoba::setGodine(int godine) {
    this->godine=godine;
}

int Osoba::getGodine() {
    return this->godine;
}

std::string Osoba::getIme() {
    return this->ime;
}
