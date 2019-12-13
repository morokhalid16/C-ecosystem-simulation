#include "Milieu.h"

#include <cstdlib>
#include <ctime>

#include "Bestiole.h"
const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{	
   deathProbability=0.1;
   birthProbability=0.1;
   cloneProbability=0.001;
   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}

void Milieu::removeMember ( void){

 cout<<" size de listebestionles"<<listeBestioles.size()<<endl;
  listeBestioles.erase(listeBestioles.end()); 
 	
}

void Milieu::born(void){                                         // Add new born to bestioles
 
float probaOfBirth=((double) std::rand() / (RAND_MAX)); 
  if (probaOfBirth < this->birthProbability){
    
      addMember(Bestiole());
   }

}

void Milieu::die(void){                                          // Kill and remove dead bestioles

float probaOfDeath=((double) std::rand() / (RAND_MAX)); 
  if (listeBestioles.size()!=0) {

  if (probaOfDeath < this->deathProbability){
      cout<<"mort"<<endl;
      removeMember();
                                            }

                               }
                    }

void Milieu::clone(void){                                      //Clonage


std::vector<Bestiole> clones;
    for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   { 
    float probaOfClonage=((double) std::rand() / (RAND_MAX));  
    if (probaOfClonage < this->cloneProbability){
        cout<<"bestiole cloned"<<endl;
	Bestiole b=*it;
        clones.push_back(b);
    
   }
   }
   cout<<"size clones " <<clones.size()<<endl;

   if (clones.size()>0){                                     // Add Clones 
   listeBestioles.insert(listeBestioles.end(),clones.begin(),clones.end());
}

}

void Milieu::step( void )
{ 
  
  born();
  die();
  clone();

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );



   

// draw and show Bestioles

   if(listeBestioles.size()!=0){
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {  
	//cout<<"bestiole"<<endl;
	//Bestiole b=*it;
      //cout<<"addMmeber"<<endl;
      //addMember(Bestiole());    
      if (it!=listeBestioles.end()){
      it->action( *this );
      it->draw( *this );
      }
   } // for
}
}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}
