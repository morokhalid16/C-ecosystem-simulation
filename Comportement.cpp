#include "Bestiole.h"

#include "Milieu.h"

#include "Comportement.h"

const float      Comportement::PROBA_GREGAIRE = 0.2;
const float      Comportement::PROBA_PEUREUSE = 0.5;
const float      Comportement::PROBA_KAMIKAZE = 0.7;
const float      Comportement::PROBA_PREVOYANTE = 0.9;
const float      Comportement::PROBA_PERSOMULT = 1;
const float      Comportement::PROBA_CHANGECOMP = 0.01;

Comportement::Comportement( void )
{
    this->persoMultiple = False;
    float probaComportement=((double) std::rand() / (RAND_MAX)); 
    if (0 <= probaComportement < PROBA_GREGAIRE){
        this->comportement = 1;
    }
    if (PROBA_GREGAIRE <= probaComportement < PROBA_PEUREUSE){
        this->comportement = 2;
    }
    if (PROBA_PEUREUSE <= probaComportement < PROBA_KAMIKAZE){
        this->comportement = 3;
    }
    if (PROBA_KAMIKAZE <= probaComportement < PROBA_PREVOYANTE){
        this->comportement = 4;
    }
    if (PROBA_PREVOYANTE <= probaComportement < PROBA_PERSOMULT){
        this->comportement = 5;
        this->persoMultiple = True;
    }
}

Comportement::~Comportement( void )
{
    delete[] this;

   cout << "dest Comportement" << endl;
}

void Comportement::ChangeComportement( void )
{
    if (persoMultiple){
        float probaComportement=((double) std::rand() / (RAND_MAX));
        if (probaComportement < PROBA_CHANGECOMP){
            if (0 <= probaComportement < PROBA_GREGAIRE){
                this->comportement = 1;
            }
            if (PROBA_GREGAIRE <= probaComportement < PROBA_PEUREUSE){
                this->comportement = 2;
            }
            if (PROBA_PEUREUSE <= probaComportement < PROBA_KAMIKAZE){
                this->comportement = 3;
            }
            if (PROBA_KAMIKAZE <= probaComportement < PROBA_PREVOYANTE){
                this->comportement = 4;
            }
        }
    }
}

