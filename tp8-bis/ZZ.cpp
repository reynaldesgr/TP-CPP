#include <iostream>
#include <string>
#include <queue> // Pour std::priority_queue
#include <algorithm> // Pour std::sort

class ZZ {
    std::string nom;
    std::string prenom;
    double note;

    public:
        // Constructeur
        ZZ(const std::string& nom, const std::string& prenom, double note) : nom(nom), prenom(prenom), note(note) {}

        // Getter pour la note
        double getNote() const {
            return note;
        }

        // Opérateur < pour comparer les éléments (ordre)
        bool operator<(const ZZ& autre) const {
            return note < autre.note;
        }

        // Opérateur << pour afficher un élément sur le flux donné
        friend std::ostream& operator<<(std::ostream& flux, const ZZ& element) {
            flux << "Nom: " << element.nom << ", Prénom: " << element.prenom << ", Note: " << element.note;
            return flux;
        }
};

using vzz = std::vector<ZZ>;


int main() {
    ZZ z1("Dupont", "Jean", 15.5);
    ZZ z2("Martin", "Alice", 18.2);

    // Utilisation de l'opérateur <
    if (z1 < z2) {
        std::cout << "Le premier étudiant a une note inférieure au deuxième." << std::endl;
    } else {
        std::cout << "Le premier étudiant a une note supérieure ou égale au deuxième." << std::endl;
    }

    // Utilisation de l'opérateur <<
    std::cout << "Informations sur le premier étudiant : " << z1 << std::endl;
    std::cout << "Informations sur le deuxième étudiant : " << z2 << std::endl;





    vzz zz;

    // Ajout d'éléments à zz en utilisant push_back
    zz.push_back(ZZ("Mechoud", "Louane", 13.5)); 
    zz.push_back(ZZ("Lourenco", "Cynthia", 15.2)); 

    std::priority_queue<ZZ> tri;

    for (vzz::iterator it = zz.begin(); it != zz.end(); ++it)
        tri.push(*it);

    while (!tri.empty()) {
        std::cout << tri.top() << " ";
        tri.pop();
    }

    std::cout << std::endl;


    // Vecteur et pointeurs

    std::vector<ZZ*> vecteurPointeursZZ;

    // allocation dynamique avec new
    vecteurPointeursZZ.push_back(new ZZ("Bouterige", "Pierre", 15.7));
    vecteurPointeursZZ.push_back(new ZZ("Segerie", "Reynalde", 17.2));
    vecteurPointeursZZ.push_back(new ZZ("Viton", "Antoine", 16.2));

    // affichage 
    for (const auto& ptr : vecteurPointeursZZ) {
        std::cout << *ptr << std::endl;
    }

    // tri du vecteur de pointeurs de ZZ en utilisant l'opérateur < (defini dans la classe)
    std::sort(vecteurPointeursZZ.begin(), vecteurPointeursZZ.end(), [](const ZZ* a, const ZZ* b) { return *a < *b; });

    // affichage 
    for (const auto& ptr : vecteurPointeursZZ) {
        std::cout << *ptr << std::endl;
    }

    // liberation de la memoire
    for (auto ptr : vecteurPointeursZZ) {
        delete ptr; // Libérer chaque objet ZZ alloue dynamiquement
    }
    
    vecteurPointeursZZ.clear(); // Effacer le vecteur


    return 0;
}
