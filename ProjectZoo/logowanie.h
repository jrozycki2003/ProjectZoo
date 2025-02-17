#pragma once
#include <iostream>
#include <fstream>

bool zaloguj() {
    std::string username, password;
    std::string stored_username, stored_password;

    std::ifstream loginFile("login.txt");
    if (!loginFile) {
        std::cerr << "Nie mozna otworzyc pliku z danymi logowania.\n";
        return false;
    }

    loginFile >> stored_username >> stored_password;//Odczytujemy nazwê u¿ytkownika i has³o z pliku 
    //i zapisujemy je do zmiennych stored_username i stored_password
    loginFile.close();//Zamykanie pliku

    std::cout << "Wprowadz nazwe uzytkownika: ";
    std::cin >> username;
    std::cout << "Wprowadz haslo: ";
    std::cin >> password;

    if (username == stored_username && password == stored_password) {
        std::cout << "Zalogowano pomyslnie.\n";
        return true;
    }
    else {
        std::cout << "Bledna nazwa uzytkownika lub haslo.\n";
        return false;
    }
}