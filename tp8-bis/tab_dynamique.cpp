#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

int main (int, char **) {
  std::vector<int> v;  
  int input;
  
  while (std::cin >> input)
    v.push_back (input);  
  
  std::sort(v.begin(), v.end());

  //std::copy (v.begin(), v.end(), 
  //std::ostream_iterator<int> (std::cout, "\n")); -> considere un peu dure


  // Affichage en utilisant des itérateurs begin() et end()
  for (auto it = v.begin(); it != v.end(); ++it) {
      std::cout << *it;

      // Vérifier si l'élément actuel n'est pas le dernier pour ajouter un espace
      if (std::next(it) != v.end()) {
          std::cout << " ";
      }
  }
  std::cout << std::endl;

  // Affichage en utilisant la boucle for étendue (C++11)
  for (int& e : v) // on pourrait oublier le mot int par 'auto' mais ici on a un vector de int donc pas besoin
    std::cout << e << std::endl;

  
  return 0;
}
