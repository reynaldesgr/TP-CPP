#include "catch.hpp"
#include <iostream>
#include <cstring>
#include <sstream>
#include "PileG.hpp"
#include "Liste.hpp"



// typedef PileGen<int> Pile; // ça marche mais c'est un peu old school
using  PileEntiers = PileG<int>;

/*
TEST_CASE("Constructeur par defaut") {
   PileEntiers p; 
   
   CHECK(  p.isEmpty() );
   CHECK(  0 == p.size() );
}


TEST_CASE("Empty list", "[Liste]") {
    Liste myList;
    REQUIRE(myList.empty());
    REQUIRE(myList.getDeb() == nullptr);
    REQUIRE(myList.getNbElem() == 0);

    SECTION("Push_front on empty list") {
        myList.push_front(42);
        REQUIRE_FALSE(myList.empty());
        REQUIRE(myList.getDeb() != nullptr);
        REQUIRE(myList.getNbElem() == 1);
        REQUIRE(myList.front().val == 42);
    }
}

TEST_CASE("Non-empty list", "[Liste]") {
    Liste myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);

    REQUIRE_FALSE(myList.empty());
    REQUIRE(myList.getNbElem() == 3);
    REQUIRE(myList.front().val == 30);
    REQUIRE(myList.back().val == 10);
}

TEST_CASE("Front and back of empty list throw exception", "[Liste]") {
    Liste myList;

    REQUIRE_THROWS_AS(myList.front(), std::invalid_argument);
    REQUIRE_THROWS_AS(myList.back(),  std::invalid_argument);
}*/

TEST_CASE("Destructor frees memory", "[Liste]") 
{
    Liste* myList = new Liste;
    myList->push_front(100);
    myList->push_front(200);

    REQUIRE(myList->getNbElem() == 2);

    delete myList; 
}

/*
TEST_CASE("pop_front on empty list throws exception", "[Liste]") {
    Liste myList;

    REQUIRE_THROWS_AS(myList.pop_front(), std::invalid_argument);
    REQUIRE(myList.empty());
}*/

TEST_CASE("pop_front removes element from the front", "[Liste]") {
    Liste myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);

    myList.pop_back();

    REQUIRE(myList.getNbElem() == 2);
    REQUIRE(myList.front().val == 30);
} 


TEST_CASE("pop_back on empty list throws exception", "[Liste]") {
    Liste myList;

    REQUIRE_THROWS_AS(myList.pop_back(), std::invalid_argument);
    REQUIRE(myList.empty());
}


TEST_CASE("pop_back removes element from the back", "[Liste]") {
    Liste myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);

    myList.pop_back();
    
    REQUIRE(myList.getNbElem() == 2);
    REQUIRE(myList.back().val  == 20);
}

TEST_CASE("ostream operator << prints the list", "[Liste]") {
    Liste myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);

    std::ostringstream output;
    myList.operator<<(output);

    REQUIRE(output.str() == "30 20 10 \n");
}


TEST_CASE("ITListe : liste avec itérateurs", "[ITListe]")
{
    Liste l1;
    l1.push_front(10);
    l1.push_front(20);
    l1.push_front(30);

    Liste::ItList it = l1.begin();
    while (it != l1.end()) 
    {
        std::cout << *it << std::endl;
        ++it;
    }
}
