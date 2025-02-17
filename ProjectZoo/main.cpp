#include <iostream>
#include <vector>
#include "Zwierze.h"
#include "Zoo.h"
#include "Pracownik.h"
#include "Wydatek.h"
#include "logowanie.h"

int main() {

    if (!zaloguj()) {
        return 1; // Zakonczenie programu w przypadku nieudanej autoryzacji
    }

    Zoo zoo;
    Wydatek wydatek;
    Pracownik pracownik;

    int opcja;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "=======================================\n";
        std::cout << "1. Dodaj zwierze (-" << zoo.koszt_dodania_zwierzecia << " zl)\n";
        std::cout << "2. Usun zwierze (+" << zoo.koszt_usuniecia_zwierzecia << " zl)\n";
        std::cout << "3. Pokaz liste zwierzat w Zoo\n";
        std::cout << "4. Zatrudnij pracownika\n";
        std::cout << "5. Zwolnij pracownika\n";
        std::cout << "6. Pokaz liste pracownikow\n";
        std::cout << "7. Zarzadzaj wydatkami\n";
        std::cout << "8. Zwieksz budzet\n";
        std::cout << "9. Zmien pensje pracownika\n";
        std::cout << "10. Wyjscie\n";
        std::cout << "=======================================\n" << std::endl;
        std::cout << "Aktualny Miesieczny Budzet Zoo: " << wydatek.budzet << " zl\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> opcja;

        switch (opcja) {
        case 1: {
            int wybor;
            std::cout << "Wybierz rodzaj zwierzecia:\n";
            std::cout << "1. Ssak\n";
            std::cout << "2. Ptak\n";
            std::cout << "3. Inny\n";
            std::cin >> wybor;

            std::string Gatunek, Kolor, Strefa, Plec, KrajPochodzenia;
            int Wiek;

            std::cout << "Podaj Gatunek: ";
            std::cin >> Gatunek;

            Zwierze* noweZwierze;//wskaznik na obiekt noweZwierze, deklaracja wskaŸnika do obiektu klasy Zwierze, uzycie polimorfizmu
            if (wybor == 3) {
                std::cout << "Podaj Kolor nowego zwierzecia: ";
                std::cin >> Kolor;

                std::cout << "Podaj Strefe w zoo w ktorej ma zostac zakwaterowany: ";
                std::cin >> Strefa;

                std::cout << "Podaj Plec: ";
                std::cin >> Plec;

                std::cout << "Podaj Wiek: ";
                std::cin >> Wiek;

                std::cout << "Podaj Kraj pochodzenia: ";
                std::cin >> KrajPochodzenia;

                noweZwierze = new Inny(Gatunek, Kolor, Strefa, Plec, Wiek, KrajPochodzenia);
            }
            else if (wybor == 2) {
                std::cout << "Podaj Ubarwienie: ";
                std::cin >> Kolor;
                std::cout << "Podaj Strefe w zoo: ";
                std::cin >> Strefa;
                noweZwierze = new Ptak(Gatunek, Kolor, Strefa);
            }
            else {
                std::cout << "Podaj Kolor: ";
                std::cin >> Kolor;
                std::cout << "Podaj Strefe w zoo: ";
                std::cin >> Strefa;
                noweZwierze = new Ssak(Gatunek, Kolor, Strefa);
            }
            zoo.DodajZwierze(*noweZwierze, wydatek);//dodanie obiektu wskazywanego przez noweZwierze do obiektu zoo
            break;
        }

        case 2: {
            std::string Gatunek;

            std::cout << "Podaj gatunek zwierzecia do usuniecia: ";
            std::cin >> Gatunek;

            zoo.UsunZwierze(Gatunek, wydatek);
            break;
        }

        case 3: {
            zoo.PokazListeZwierzat();
            break;
        }
        case 4: {
            std::string Imie, Nazwisko, Stanowisko;
            int pensja;

            std::cout << "Podaj Imie nowego pracownika: ";
            std::cin >> Imie;
            std::cout << "Podaj Nazwisko: ";
            std::cin >> Nazwisko;
            std::cout << "Podaj Stanowisko: ";
            std::cin >> Stanowisko;
            std::cout << "Podaj pensje (w zl): ";
            std::cin >> pensja;

            pracownik.zatrudnijPracownika(Pracownik(Imie, Nazwisko, Stanowisko, pensja), wydatek);
            break;
        }


        case 5: {
            std::string Nazwisko;

            std::cout << "Podaj nazwisko pracownika do zwolnienia: ";
            std::cin >> Nazwisko;

            pracownik.zwolnijPracownika(Nazwisko, wydatek);
            break;
        }
        case 6: {
            pracownik.PokazListePracownikow();
            break;
        }
        case 7: {
            // Kod dla wyœwietlania listy wydatków
            wydatek.wyswietlWydatki();
            // Dodawanie wydatku
            int numer;
            std::cout << "Podaj numer wydatku do zaplacenia: ";
            std::cin >> numer;
            wydatek.dodajWydatek(numer);
            break;
        }
        case 8: {
            int kwota;
            std::cout << "Podaj kwote do zwiekszenia budzetu (w zl): ";
            std::cin >> kwota;
            wydatek.zwiekszBudzet(kwota);
            break;
        }
        case 9: {
            // Zmiana pensji pracownika
            pracownik.PokazListePracownikow();
            std::string nazwisko;
            int nowaPensja;

            std::cout << "\nPodaj nazwisko pracownika: ";
            std::cin >> nazwisko;
            std::cout << "Podaj nowa pensje (w zl): ";
            std::cin >> nowaPensja;

            pracownik.zmienPensje(nazwisko, nowaPensja, wydatek);
            break;
        }
        case 10: {
            std::cout << "Koniec.\n";
            break;
        }
        default: {
            std::cout << "Nieprawidlowy wybor. Prosze sprobowac ponownie.\n";
            break;
        }
        }

        std::cout << "Pozostaly Budzet: " << wydatek.budzet << " zl" << std::endl;

    } while (opcja != 10);

    zoo.zapisz_zwierzeta_do_pliku("zwierzeta.txt");
    pracownik.zapisz_pracownikow("pracownicy.txt");
    wydatek.zapisz_budzet("budzet.txt");

    return 0;
}