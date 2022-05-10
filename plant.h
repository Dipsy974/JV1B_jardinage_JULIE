#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <vector>
#include <iostream>

class Plant{
    
    protected:
        std::string _speciesName;
        int _hydratation;
        int _cut; 
        int _health; 
        int _maturity;
        bool _isAlive; 
        bool _isFed; 
        int _value; 
       

    public:
        std::string getName();
        //Renvoie le nom d'espèce de la plante

        bool getAlive();
        //Renvoie si la plante est vivante ou non 

        int getMaturity();
        //Renvoie la maturité de la plante

        int getHydratation();
        //Renvoie le niveau d'hydratation de la plante

        int getHealth();
        //Renvoie la santé de la plante

        int getCut();
        //Renvoie le niveau de taillage de la plante

        int getValue();
        //Renvoie la valeur de la plante

        void checkState();
        //Examine l'état de la plante (hydratation et taillage)

        void cut();
        //Taille la plante

        void water();
        //Arrose la plante

        void feed();
        //Donne de l'engrais

        void grow();
        //La plante pousse en fonction de sa santé

        void sleep();
        //Actualise certaines valeur le jour suivant (cut, hydratation)

        Plant(); 
        Plant(std::string name); 

}; 


#endif