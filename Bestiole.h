#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include <vector>
#include "UImg.h"
#include "Capteur.h"
#include <iostream>



class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   std::vector<Bestiole>   listeVoisinsVoit;
   std::vector<Bestiole>   listeVoisinsEntend;
   static int              next;
   std::vector<Capteur> listeCapteurs;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );
   void notifyCapteurs(void);
   void attach( Capteur nouvCapteur );
   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );
   int getX( void ) const { return x;};
   int getY( void ) const { return y;};
   std::vector<Bestiole> getListeVoisinsVoit( void ) const {return listeVoisinsVoit;};
   std::vector<Bestiole> getListeVoisinsEntend( void ) const {return listeVoisinsEntend;};
   void setListeVoisinsEntend( std::vector<Bestiole> newListV ){listeVoisinsEntend = newListV;};
   void setListeVoisinsVoit( std::vector<Bestiole> newListV ){listeVoisinsVoit = newListV;};
   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
