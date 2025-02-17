#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "Wydatek.h"

class Zoo {
public:
    std::vector<Zwierze> zwierze;

    Zoo() {
        wczytaj_zwierzeta_z_pliku("zwierzeta.txt");// Wczytanie danych z pliku przy starcie programu, funkcje wczytaj napisane nizej
    }
    /*
  destruktor moznaby wywolac, gdy program siê konczy. System wywoluje automatycznie destruktor tej klasy. Po zapisaniu danych zwierzat do pliku,
  destruktor zamyka plik, aby upewniæ siê, ¿e dane zosta³y zapisane poprawnie.Po zakoñczeniu dzia³ania destruktora, niszczony jest obiekt klasy Zoo.
  */
    int koszt_dodania_zwierzecia = 9500;
    int koszt_usuniecia_zwierzecia = 7500;

    void wczytaj_zwierzeta_z_pliku(std::string filename);
    void zapisz_zwierzeta_do_pliku(std::string filename);
    bool czyZwierzeIstnieje(std::string Gatunek);
    void DodajZwierze(Zwierze stworzenie, Wydatek& wydatek);
    void UsunZwierze(std::string Gatunek, Wydatek& wydatek);
    void PokazListeZwierzat();
};