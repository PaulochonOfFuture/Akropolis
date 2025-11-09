#pragma once
#include "../abstract/Construction.h"

  

class Hexagone {
private:
    Construction* construction; 
    int étage;
    bool est_vide;
 public:
     Hexagone(Coordonee& c);
     ~Hexagone();
     void afficher_hexagone();

};