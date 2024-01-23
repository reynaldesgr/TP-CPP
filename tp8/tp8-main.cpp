#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(int argc, char** argv) {

    if (argc == 1) 
    {
        std::map<std::string, std::string> phoneBook;

        std::ifstream inputFile("annuaire.txt");
        if (!inputFile.is_open()) 
        {
            std::cerr << "Erreur lors de l'ouverture du fichier annuaire.txt" << std::endl;
            return 1;
        }

        std::string name, phoneNumber;
        while (inputFile >> name >> phoneNumber) 
        {
            phoneBook[name] = phoneNumber;
        }

        inputFile.close();

        for (const auto& entry : phoneBook) 
        {
            std::cout << "Nom : " << entry.first << ", Numéro de téléphone : " << entry.second << std::endl;
        }
    } 
    else if (argc == 2) 
    {
        std::string searchName = argv[1];
        std::map<std::string, std::string> phoneBook;

        std::ifstream inputFile("annuaire.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Erreur lors de l'ouverture du fichier annuaire.txt" << std::endl;
            return 1;
        }

        std::string name, phoneNumber;
        bool found = false;
        while (inputFile >> name >> phoneNumber) 
        {
            phoneBook[name] = phoneNumber;
            if (name == searchName) {
                std::cout << "Nom : " << name << ", Numéro de téléphone : " << phoneNumber << std::endl;
                found = true;
                break;
            }
        }

        inputFile.close();

        if (!found) 
        {
            std::cout << "Entrée non trouvée pour le nom : " << searchName << std::endl;
        }
    } 
    else 
    {
        std::cerr << "Usage : " << argv[0] << " [nom]" << std::endl;
        return 1;
    }

    return 0;
}