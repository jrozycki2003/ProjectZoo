#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "Wydatek.h"

void Wydatek::wczytaj_budzet(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> budzet;
        file.close();
    }
    else {
        std::cerr << "Nie mozna otworzyc pliku z budzetem do odczytu.\n";
    }
}

void Wydatek::zapisz_budzet(std::string filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << budzet;
        file.close();
    }
    else {
        std::cerr << "Nie mozna otworzyc pliku z budzetem do zapisu.\n";
    }
}

void Wydatek::zwiekszBudzet(int ilosc) {
    if (ilosc > 0) {
        budzet += ilosc;
    }
    else {
        std::cerr << "Nieprawidlowa wartosc do zwiekszenia budzetu.\n";
    }
}

void Wydatek::ListaWydatkow() {
    wydatki = { {"Karma dla zwierzat", 2000}, {"Opieka weterynaryjna", 3000}, {"Koszt utrzymania wybiegu", 1000}, {"Koszt energii elektrycznej", 500} };
}

void Wydatek::wyswietlWydatki() {//wyswietlenie zawartosci wektora wydatki
    std::cout << "\nLista Wydatkow:\n";
    int numer = 1;
    for (const auto& wydatek : wydatki) {//dzieki const element nie moze byc modyfikowany
        std::cout << numer << ". " << wydatek.nazwa << " - " << wydatek.koszt << " zl\n";
        ++numer;
    }
}

void Wydatek::dodajWydatek(int numer) {//uzytkownik wybiera za jaki wydatek chce zaplacic
    if (numer > 0 && numer <= wydatki.size()) {
        budzet -= wydatki[numer - 1].koszt;
        std::cout << "Zaplacono za: " << wydatki[numer - 1].nazwa << " (" << wydatki[numer - 1].koszt << " zl)\n";
    }
    else {
        std::cout << "Nieprawidlowy numer wydatku.\n";
    }
}