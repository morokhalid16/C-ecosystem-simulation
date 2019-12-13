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

class Capteur
{
    private :
        Bestiole *laBestiole;
        double alpha;
        double deltaY;
        double deltaO;
        double gamma;
    public :
        Capteur(Bestiole * laBestiol){};
    
        ~Capteur();
    
        virtual void update() = 0;
    
    protected :
        Bestiole *getBestiole(){
        }
};


#endif /* Capteur_h */
