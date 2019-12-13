//
//  Oreilles.h
//
//
//
#ifndef Oreilles_h
#define Oreilles_h
#include <stdio.h>
#include "Bestiole.h"

#include "Milieu.h"
#include "Capteur.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#define PI 3.14159265

using namespace std;

class Oreilles: public Capteur {
    public:
        Oreilles(Bestiole *laBestiole): Capteur(laBestiole){}
    void update(){
        double xBest = getBestiole()->getX();
        double yBest = getBestiole()->getY();
        double orient = getBestiole()->getOrientation();
        double deltaO = this.deltaO;
        double gamma = getBestiole()->getGamma();
        std::vector<Bestiole> newListV;
        std::vector<Bestiole> listB= getBestiole()->getMilieu()->getListeBestioles();
        double probVoir = static_cast<double>( rand() )/RAND_MAX;
        for ( std::vector<Bestiole>::iterator it = listeB.begin() ; it != listeB.end() ; ++it )
        {
            double xCur = it->getX();
            double yCur = it->getY();
            if (dist<delta0){
                if (probVoir<gamma){
                    newListV.push_back(*it);
                };
            };
        };
        getBestiole()->setListVoisinsEntend(newListV);
    };
};


