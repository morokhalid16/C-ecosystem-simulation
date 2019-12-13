//
//  Capteur.h
//  
//

//

#ifndef Capteur_h
#define Capteur_h
#include <stdio.h>
#include "UImg.h"
#include "Bestiole.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Capteur :
{
    private :
        Bestiole *laBestiole;
        double alpha;
        double deltaY;
        double deltaO;
        double gamma;
    public :
        Capteur(Bestiole * laBestiol){
            laBestiole = laBestiol;
            alpha = laBestiole->getMilieu()->get_alphaMin()+static_cast<double>( rand() )/RAND_MAX*(laBestiole->getMilieu()->get_alphaMax()-laBestiole->getMilieu()->get_alphaMin()) ;
            deltaY = laBestiole->getMilieu()->get_deltaYMin()+static_cast<double>( rand() )/RAND_MAX*(laBestiole->getMilieu()->get_deltaYmax()-laBestiole->getMilieu()->get_deltaYmin()) ;
            deltaO = laBestiole->getMilieu()->get_deltaOmin()+static_cast<double>( rand() )/RAND_MAX*(laBestiole->getMilieu()->get_deltaOmax()-laBestiole->getMilieu()->get_deltaOmin()) ;
            gamma = laBestiole->getMilieu()->get_gammaMin()+static_cast<double>( rand() )/RAND_MAX*(laBestiole->getMilieu()->get_gammaMax()-laBestiole->getMilieu()->get_gammaMin()) ;
            laBestiole ->attach(this);
        }
    
        ~Capteur();
    
        virtual void update() = 0;
    
    protected :
        Bestiole *getBestiole(){
            return laBestiole;
        }
}
#endif /* Capteur_h */
