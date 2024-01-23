#include "catch.hpp"
#include <cstring>
#include <sstream>
#include "Chaine.hpp"
#include "Pile.hpp"


TEST_CASE("Constructeur par défaut")
{
    Pile p;
    CHECK( p.isEmpty());
    CHECK( 0 == p.size() );
}


TEST_CASE("Exceptions de mauvaise construction") 
{
   REQUIRE_THROWS_AS( Pile(-1).isEmpty(), std::invalid_argument );
   REQUIRE_THROWS_AS( Pile( 0).isEmpty(), std::invalid_argument );
   
}


TEST_CASE("Exception pile vide") 
{
   REQUIRE_THROWS_AS( Pile().pop(), std::invalid_argument );  
}


TEST_CASE("Live pile") 
{
    Pile p(10);

    CHECK(  p.isEmpty() );
    CHECK(  0 == p.size() );

    p.push(5);

    CHECK( !p.isEmpty() );
    CHECK( 1 == p.size() );
    CHECK( 5 == p.top() );

    p.push(2);
    p.push(1);

    CHECK( 3 == p.size() );
    CHECK( 1 == p.top() );

    p.pop();

    CHECK( 2 == p.size() );
    CHECK( 2 == p.top() );

    p.pop();
    p.pop();

    CHECK( 0 == p.size() );

}

/***
 * Rajout tests Exceptions sur Chaine
*/


TEST_CASE("Exceptions aux bornes") 
{
  Chaine s(10);
    
  REQUIRE_THROWS_AS( s[-1] == 0, Chaine::OutOfRangeException);
  REQUIRE_THROWS_AS( s[-1] == 0, std::out_of_range);
  REQUIRE_THROWS_AS( s[12] == 0, std::out_of_range);  // :-)
}


TEST_CASE("Exception std::bad_alloc")
{
    SECTION("Mauvaise allocation (std::bad_alloc)")
    {
        //REQUIRE_THROWS_AS(Chaine(1000000000000000000000000000), Chaine::BadAllocException);
        //REQUIRE_THROWS_AS(Chaine(100000000000000000000000000), std::bad_alloc);   
    } 
}


TEST_CASE("Exception sur pointeur null") 
{
  Chaine s(0);

  std::logic_error * pe = new null_pointer;  
  delete pe;

  REQUIRE_THROWS_AS( s[1] == 0, null_pointer);
}