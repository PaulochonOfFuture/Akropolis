#pragma once
#include "../abstract/Construction.h"

class Tuile {
private:
    Construction* construction;
};



using namespace std;

class Tuile
{
private:
    int id_tuile;
    string nature_tuile; //habitation, marché, ...

public:
    concevoir_tuile(int id_tuile = 0, const string &type = "inconnue") : id_tuile(id_tuile), nature_tuile(nature_tuile){}
    int getNature_tuile() const { return id_tuile; }
    const string &getNature_tuile() const { return nature_tuile;}

    void afficher_tuile() const { cout << "La tuile" << id_tuile << "représente" << nature_tuile << endl;}
}tuile;
