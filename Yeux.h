//
//  Yeux.h
//
//
//
#ifndef Yeux_h
#define Yeux_h
#include <stdio.h>
#include "Bestiole.h"

#include "Milieu.h"
#include "Capteur.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Yeux: public Capteur {
    public:
        Yeux(Bestiole *laBestiole): Capteur(laBestiole){}
    void update(){
        
        
    }
}

