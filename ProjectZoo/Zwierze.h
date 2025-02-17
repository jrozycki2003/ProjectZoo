#pragma once

class Zwierze {
public:
    std::string Gatunek;
    std::string Kolor;
    std::string Strefa;

    Zwierze(std::string Gatunek, std::string Kolor, std::string Strefa) : Gatunek(Gatunek), Kolor(Kolor), Strefa(Strefa) {}//konstruktor klasy Zwierze
};

class Ssak : public Zwierze {//klasa ssak dziedziczy po klasie Zwierze
public:
    Ssak(std::string Gatunek, std::string Kolor, std::string Strefa) : Zwierze(Gatunek, Kolor, Strefa) {}
};

class Ptak : public Zwierze {
public:
    std::string& Ubarwienie = Kolor;//referencja, zmieniony kolor na ubarwienie ptaka ale to to samo
    Ptak(std::string Gatunek, std::string Ubarwienie, std::string Strefa) : Zwierze(Gatunek, Ubarwienie, Strefa) {}
};

class Inny : public Zwierze {
public:
    std::string Plec;
    int Wiek;
    std::string KrajPochodzenia;

    Inny(std::string Gatunek, std::string Kolor, std::string Strefa, std::string Plec, int Wiek, std::string KrajPochodzenia)
        : Zwierze(Gatunek, Kolor, Strefa), Plec(Plec), Wiek(Wiek), KrajPochodzenia(KrajPochodzenia) {
    }
};