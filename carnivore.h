#ifndef CARNIVORE_H
#define CARNIVORE_H

#include <string>
#include "plant.cpp"

class Carnivore : public Plant{

    protected:
        bool _isEnTrainDeDigerer;  
        int _daysDigestion; 

    public: 
        void eat(); 
        void sleep();  
        Carnivore(); 
        Carnivore(string name); 
}; 

#endif