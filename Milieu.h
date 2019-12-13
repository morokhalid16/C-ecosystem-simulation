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
   float cloneProbability;
   float clonageProbability;
   float alphaMin, alphaMax; 
   float deltaYmin, deltaYmax;
   float deltaOmin, deltaOmax;
   float gammaMin, gammaMax;


public :
   Milieu( int _width, int _height );
   ~Milieu( void );
   std::vector<Bestiole> get_listeBestiole(void){return listeBestioles;};
   float get_deathProbability( void ) const { return deathProbability;};
   float get_birthProbability( void ) const { return birthProbability;};
   float get_alphaMin( void ) const { return alphaMin;};
   float get_alphaMax( void ) const { return alphaMax;};
   float get_deltaYmin( void ) const { return deltaYmin;};
   float get_deltaYmax( void ) const { return deltaYmax;};
   float get_deltaOmin( void ) const { return deltaOmin;};
   float get_deltaOmax( void ) const { return deltaOmax;};
   float get_gammaMin( void ) const { return gammaMin;};
   float get_gammaMax( void ) const { return gammaMax;};

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void born(void);
   void die(void);
   void clone(void);
   void step( void );
   //void cloneMember(const Bestiole & b){listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); };
   void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); } ;
   void removeMember ( void) ;
   int nbVoisins( const Bestiole & b );

};


#endif
