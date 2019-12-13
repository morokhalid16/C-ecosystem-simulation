#include "Bestiole.h"

#include <iostream>

using namespace std;

class Comportement{

private:
    int comportement;
    bool persoMultiple;
    static const float     PROBA_GREGAIRE;
    static const float     PROBA_PEUREUSE;
    static const float     PROBA_KAMIKAZE;
    static const float     PROBA_PREVOYANTE;
    static const float     PROBA_PERSOMULT;
    static const float     PROBA_CHANGECOMP;
    
public:
    Comportement( void );
    ~Comportement( void );
    void ChangeComportement( void );
};