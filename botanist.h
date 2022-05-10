#ifndef BOTANIST_H
#define BOTANIST_H

#include "plant.cpp"
#include "flower.cpp"
#include "carnivore.cpp"

#include <string>
#include <vector>
#include <iostream>

class Botanist{
    
    protected:
        std::string _name;
        int _money;
        vector<Plant *> _plants; 
        int _fertilizer; 
       

    public:
        std::string getName();
        //Renvoie le nom du botaniste

        vector<Plant *> getPlants();
        //Renvoie les plantes possédées

        int getMoney();
        //Renvoie l'argent possédé

        int getFertilizer();
        //Renvoie l'engrais possédé

        void buyPlant(std::string speciesName);
        //Acquérir une nouvelle plante

         void buyFlower(std::string speciesName);
        //Acquérir une nouvelle fleur

         void buyCarnivore(std::string speciesName);
        //Acquérir une nouvelle plante carnivore

        void sellPlant(Plant plant);
        //Vend une plante

        void buyFertilizer();
        //Acquérir de l'engrais

        void useFertilizer();
        //Utilise un engrais





        Botanist(); 
        Botanist(std::string name); 

}; 


#endif