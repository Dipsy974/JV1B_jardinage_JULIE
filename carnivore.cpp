#ifndef CARNIVORE_CPP
#define CARNIVORE_CPP

#include <string>
#include "Carnivore.h"

Carnivore::Carnivore() : Plant(){
    _isEnTrainDeDigerer = false; 
    _daysDigestion = 7; 
} 

Carnivore::Carnivore(string name) : Plant(name){
    _isEnTrainDeDigerer = false; 
    _daysDigestion = 7;
} 

void Carnivore::eat(){
    _isEnTrainDeDigerer = true; 
}

void Carnivore::sleep(){  
    _cut -= 1;
    _hydratation -=1; 
    _isFed = false; 
    if(_isEnTrainDeDigerer){
            this->grow();
            _daysDigestion -= 1; 
            if(_daysDigestion <= 0){
                _daysDigestion = 7; 
                _isEnTrainDeDigerer = false; 
            }
    }
}

 
#endif