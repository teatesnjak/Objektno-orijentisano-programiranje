#include <iostream>
#include "KozmetickiSalon.h"
void prikaziMenu() {
    std::cout << "Izaberite opciju:" << std::endl;
    std::cout << "1. Dodaj uposlenika" << std::endl;
    std::cout << "2. Dodaj uslugu" << std::endl;
    std::cout << "3. Ispis svih uposlenika" << std::endl;
    std::cout << "4. Odabir usluge" << std::endl;
    std::cout<<  "5. Promjena stanja uposlenika "<<std::endl;
    std::cout << "0. Izlaz iz programa" << std::endl;
}
int main() {
    KozmetickiSalon Salon;
    Salon.ucitajUslugeIzFajla();
    system("cls");
    while (true) {
        prikaziMenu();

        int opcija;
        do{
            std::cout << "Unesite opciju: ";
            std::cin >> opcija;
        }while(opcija<0 || opcija>5);


        switch (opcija) {
            case 1: {
                system("cls");
                Salon.dodajZaposlenog();
                std::cout<<"\n";
                system("pause");
                system("cls");
                break;
            }
            case 2:
                system("cls");
                std::cin.ignore();
                Salon.dodajUsluge();
                std::cout<<"\n";
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                Salon.prikaziZaposlene();
                std::cout<<"\n";
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                Salon.odaberiUslugu();
                std::cout<<"\n";
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                Salon.oslobodiRadnika();
                std::cout<<"\n";
                system("pause");
                system("cls");
                break;
            case 0:
                std::cout << "Izlaz iz programa." << std::endl;
                Salon.sacuvajUslugeUFajl();
                return 0;

        }
    }
}
