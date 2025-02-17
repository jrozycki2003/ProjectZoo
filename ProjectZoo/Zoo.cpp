#include <iostream>
#include <algorithm>
#include "Zwierze.h"
#include "Zoo.h"
#include "Wydatek.h"

void Zoo::wczytaj_zwierzeta_z_pliku(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string Gatunek, Kolor, Strefa;
        while (file >> Gatunek >> Kolor >> Strefa) {
            zwierze.emplace_back(Gatunek, Kolor, Strefa);
        }
        file.close();
    }
    else {
        std::cerr << "Nie mozna otworzyc pliku z danymi zwierzat do odczytu.\n";
    }
}

void Zoo::zapisz_zwierzeta_do_pliku(std::string filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (auto stworzenie : zwierze) {
            file << stworzenie.Gatunek << " " << stworzenie.Kolor << " " << stworzenie.Strefa << "\n";
        }
        file.close();
    }
}

bool Zoo::czyZwierzeIstnieje(std::string Gatunek) {
    for (auto stworzenie : zwierze) {
        if (stworzenie.Gatunek == Gatunek) {
            return true;
        }
    }
    return false;
}
void Zoo::DodajZwierze(Zwierze stworzenie, Wydatek& wydatek) {//& na poczatku tworzy referencje do zmiennej a & na koñcu zwraca adres zmiennej w pamiêci.
    if (!czyZwierzeIstnieje(stworzenie.Gatunek)) {
        zwierze.push_back(stworzenie);
        wydatek.budzet -= koszt_dodania_zwierzecia;
    }
    else {
        std::cout << "Zwierze o podanym gatunku juz istnieje.\n";
    }
}

void Zoo::UsunZwierze(std::string Gatunek, Wydatek& wydatek) {
    auto iterator = std::remove_if(
        zwierze.begin(),
        zwierze.end(),
        [&](Zwierze stworzenie) {//za pomoca [&] przechwycilem gatunek stworzenia przez referencjê
            return stworzenie.Gatunek == Gatunek;
        });

    if (iterator != zwierze.end()) {
        zwierze.erase(iterator, zwierze.end());
        wydatek.budzet += koszt_usuniecia_zwierzecia;
    }
    else {
        std::cout << "Nie ma zwierzecia o podanym gatunku.\n";
    }
}

void Zoo::PokazListeZwierzat() {
    std::cout << "\nLista Zwierzat:\n";
    for (auto stworzenie : zwierze) {
        std::cout << "Gatunek: " << stworzenie.Gatunek << "\tKolor: " << stworzenie.Kolor << "\tStrefa: " << stworzenie.Strefa << "\n";
    }
}