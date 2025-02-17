#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "Pracownik.h"
#include "Wydatek.h"

void Pracownik::wczytaj_pracownikow(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string Imie, Nazwisko, Stanowisko;
        int pensja;
        while (file >> Imie >> Nazwisko >> Stanowisko >> pensja) { //wczytujemy wszystko i pensje
            pracownicy.emplace_back(Imie, Nazwisko, Stanowisko, pensja);
        }
        file.close();
    }
    else {
        std::cerr << "Nie mozna otworzyc pliku z danymi pracownikow do odczytu.\n";
    }
}

void Pracownik::zatrudnijPracownika(Pracownik pracownik, Wydatek& wydatek) {
    if (!czyPracownikIstnieje(pracownik.Nazwisko)) {
        if (pracownik.Pensja > 0) {
            pracownicy.push_back(pracownik);
            wydatek.budzet -= pracownik.Pensja; // aktualizacja bud¿etu o pensje pracownika
        }
        else {
            std::cerr << "Nieprawidlowa wartosc pensji pracownika.\n";
        }
    }
    else {
        std::cout << "Pracownik o podanym nazwisku ju¿ istnieje.\n";
    }
}

void Pracownik::zwolnijPracownika(std::string Nazwisko, Wydatek& wydatek) {
    int pensjaZwolnionego = 0; //zmienna przechowujaca pensje pracownika, ktory zostanie zwolniony

    auto iterator = std::remove_if(
        pracownicy.begin(),
        pracownicy.end(),
        [&](Pracownik& pracownik) {//[&] Sprawdza wszystkie parametry przekazane jako referencje (tu to beda pracownicy)
            if (pracownik.Nazwisko == Nazwisko) {
                pensjaZwolnionego = pracownik.Pensja; //przechwytujemy pensje pracownika
                return true;
            }
            return false;
        });

    if (iterator != pracownicy.end()) {//Sprawdzenie, czy funkcja std::remove_if znalaz³a pracownika do usuniêcia
        pracownicy.erase(iterator, pracownicy.end());
        wydatek.budzet += pensjaZwolnionego; //aktualizacja bud¿etu o pensje pracownika
    }
    else {
        std::cout << "Nie ma pracownika o podanym nazwisku.\n";
    }
}

void Pracownik::PokazListePracownikow() {
    std::cout << "\nLista Pracownikow:\n";
    for (auto pracownik : pracownicy) {
        std::cout << pracownik.Imie << " " << pracownik.Nazwisko << ", " << pracownik.Stanowisko << "\tPensja: " << pracownik.Pensja << "zl\n";
    }
}

bool Pracownik::czyPracownikIstnieje(std::string Nazwisko) {
    for (auto pracownik : pracownicy) {
        if (pracownik.Nazwisko == Nazwisko) {
            return true;
        }
    }
    return false;
}

void Pracownik::zmienPensje(std::string Nazwisko, int nowaPensja, Wydatek& wydatek) {
    int staraPensja = 0; //przechowywana obecna pensja przed zmian¹
    bool pracownikZnaleziony = false;

    for (auto& pracownik : pracownicy) {
        if (pracownik.Nazwisko == Nazwisko) {
            staraPensja = pracownik.Pensja; //zapis obecnej pensji
            if (nowaPensja < 0) {
                std::cout << "Nowa pensja nie moze byc ujemna.\n";
                return;
            }//obsluga bledu ujemnej pensji
            pracownik.Pensja = nowaPensja; //zmiana pensji
            pracownikZnaleziony = true;
            break;
        }
    }

    if (!pracownikZnaleziony) {
        std::cout << "Pracownik o nazwisku " << Nazwisko << " nie istnieje.\n";
        return;
    }

    //obliczanie ró¿nicy w pensji
    int roznicaPensji = nowaPensja - staraPensja;
    //aktualizacja bud¿etu o roznice w pensji
    wydatek.budzet -= roznicaPensji;
}

void Pracownik::zapisz_pracownikow(std::string filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (auto pracownik : pracownicy) {
            file << pracownik.Imie << " " << pracownik.Nazwisko << " " << pracownik.Stanowisko << " " << pracownik.Pensja << "\n"; //zapis pensji
        }
        file.close();
    }
}