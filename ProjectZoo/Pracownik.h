#pragma once
#include <iostream>
#include "Wydatek.h"

class Pracownik {
public:
    std::vector<Pracownik> pracownicy;

    Pracownik() {
        wczytaj_pracownikow("pracownicy.txt");
    }

    std::string Imie;
    std::string Nazwisko;
    std::string Stanowisko;
    int Pensja;

    Pracownik(std::string Imie, std::string Nazwisko, std::string Stanowisko, int Pensja) :
        Imie(Imie), Nazwisko(Nazwisko), Stanowisko(Stanowisko), Pensja(Pensja) {
    }//konstruktor i inicjalizator wartosci po dwukropku

    void wczytaj_pracownikow(std::string filename);
    void zmienPensje(std::string Nazwisko, int nowaPensja, Wydatek& wydatek);
    void zapisz_pracownikow(std::string filename);
    bool czyPracownikIstnieje(std::string Nazwisko);
    void zatrudnijPracownika(Pracownik pracownik, Wydatek& wydatek);
    void zwolnijPracownika(std::string Nazwisko, Wydatek& wydatek);
    void PokazListePracownikow();
};