#include "Milieu.h"

#include <cstdlib>
#include <ctime>

#include "Bestiole.h"
const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{
   deathProbability=0.01;
   birthProbability=0.01;
   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{ 
// Add new born bestioles
  float probaOfBirth=((double) std::rand() / (RAND_MAX)); 
  if (probaOfBirth < this->birthProbability){
    
      addMember(Bestiole());
   }
// Remove dead bestioles
  float probaOfDeath=((double) std::rand() / (RAND_MAX)); 
  if (probaOfDeath < this->deathProbability){
    
      removeMember();
   }
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
    
      it->action( *this );
      it->draw( *this );

   } // for

}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}
