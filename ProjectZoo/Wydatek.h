#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

class Wydatek {
public:
    std::vector<Wydatek> wydatki;

    Wydatek() {
        wczytaj_budzet("budzet.txt");
        ListaWydatkow();//musi byc w konstruktorze zeby lista wydatkow sie wywolala w case7
    }

    std::string nazwa;
    int koszt;
    int budzet;

    Wydatek(std::string nazwa, int koszt) : nazwa(nazwa), koszt(koszt) {}

    void wczytaj_budzet(std::string filename);
    void zapisz_budzet(std::string filename);
    void zwiekszBudzet(int ilosc);
    void ListaWydatkow();
    void wyswietlWydatki();
    void dodajWydatek(int numer);
};