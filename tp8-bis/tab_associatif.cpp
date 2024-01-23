#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

using mss = std::map<string, string>;

void afficherMap(const mss& m) {
    for (const auto& entry : m) {
        cout << entry.first << " " << entry.second << endl;
    }
}

string paire(const pair<string, string>& p) {
    return p.first + " " + p.second;
}

int main(int argc, char* argv[]) {
    mss annuaire;

    // Lire les entrées de l'annuaire à partir d'un fichier texte (nom du fichier codé en dur)
    ifstream fichier("annuaire.txt");
    if (fichier) {
        string nom, numero;
        while (fichier >> nom >> numero) {
            annuaire[nom] = numero;
        }
        fichier.close();
    } else {
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
        return 1;
    }

    if (argc == 1) {
        // Afficher la liste des entrées sur la sortie standard s'il n'y a aucun paramètre en ligne de commande
        afficherMap(annuaire);
    } else {
        // Afficher l'entrée trouvée ou "non trouvé" si un argument est donné en ligne de commande
        string recherche = argv[1];
        auto it = annuaire.find(recherche);
        if (it != annuaire.end()) {
            cout << it->first << " " << it->second << endl;
        } else {
            cout << "non trouvé" << endl;
        }
    }

    // Essayer l'algorithme copy() sur la map
    mss copieAnnuaire;
    copy(annuaire.begin(), annuaire.end(), inserter(copieAnnuaire, copieAnnuaire.begin()));

    // Utiliser la fonction paire() sur le modèle de first() pour afficher le contenu de la map
    transform(annuaire.begin(), annuaire.end(), ostream_iterator<string>(cout, "\n"), paire);

    // Créer l'annuaire inversé
    mss annuaireInverse;
    for (const auto& entry : annuaire) {
        annuaireInverse[entry.second] = entry.first;
    }

    return 0;
}

