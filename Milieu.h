#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include <cstdlib>
#include <cmath>
#include <stdlib.h>  

#include <iostream>
#include <vector>

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bestiole>   listeBestioles;
   float deathProbability, birthProbability;
   float alphaMin, alphaMax; 
   float deltaYmin, deltaYmax;
   float delta0min, delta0max;
   float gamma0min, gamma0max;


public :
   Milieu( int _width, int _height );
   ~Milieu( void );
   float get_deathProbability( void ) const { return deathProbability;};
   float get_birthProbability( void ) const { return birthProbability;};
   float get_alphaMin( void ) const { return alphaMin;};
   float get_alphaMax( void ) const { return alphaMax;};
   float get_deltaYmin( void ) const { return deltaYmin;};
   float get_deltaYmax( void ) const { return deltaYmax;};
   float get_delta0min( void ) const { return delta0min;};
   float get_delta0max( void ) const { return delta0max;};
   float get_gamma0min( void ) const { return gamma0min;};
   float get_gamma0max( void ) const { return gamma0max;};

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); } 
   void removeMember ( ) { listeBestioles.erase(listeBestioles.begin()+1);};
   int nbVoisins( const Bestiole & b );

};


#endif
