#ifndef FLOWER_H
#define FLOWER_H

#include <string>
#include "plant.cpp"

class Flower : public Plant{

    protected:
        int _eclosionDays;
        bool _isEclos; 

    public: 
        void grow(); 
        void sleep();
        void eclosion(); 
        void faner(); 
        Flower(); 
        Flower(string name); 
}; 

#endif