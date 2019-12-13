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
#define PI 3.14159265

using namespace std;

class Yeux: public Capteur {
    public:
        Yeux(Bestiole *laBestiole): Capteur(laBestiole){}
    void update(){
        double xBest = getBestiole()->getX();
        double yBest = getBestiole()->getY();
        double orient = getBestiole()->getOrientation();
        double deltaY = this.deltaY;
        double alpha = this.alpha;
        std::vector<Bestiole> newListV;
        std::vector<Bestiole> listB= getBestiole()->getMilieu()->getListeBestioles();
        double probVoir = static_cast<double>( rand() )/RAND_MAX;
        for ( std::vector<Bestiole>::iterator it = listeB.begin() ; it != listeB.end() ; ++it )
        {
            double xCur = it->getX();
            double yCur = it->getY();
            double angle = (atan2(yCur-yBest,xCur-xBest)*180 / PI)-orient;
            if (angle<alpha/2){
                double dist = sqrt(pow(yCur-yBest,2)+pow(xCur-xBest,2));
                if (dist<deltaY){
                    newListV.push_back(*it);
                };
            };
        };
    };
};

