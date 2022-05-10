#ifndef FLOWER_CPP
#define FLOWER_CPP

#include <string>
#include "flower.h"

Flower::Flower() : Plant(){
    _eclosionDays = 3; 
    _isEclos = false; 
} 

Flower::Flower(string name) : Plant(name){
    _eclosionDays = 3; 
    _isEclos = false; 
} 

void Flower::eclosion(){
    _isEclos = true;
    _value = _value * 2; 
}

void Flower::faner(){
    _value = _value / 10; 
}

void Flower::grow(){
    if(_health < 3){
        _maturity -= 1 ;
    }else if(_health > 5){
        _maturity +=  0.5 ; //Croissance plus lente qu'une plante
    }

    if(_maturity <= 0){
        cout <<  _speciesName <<" ne pousse plus, elle est décédée..." << endl; 
        _isAlive = false; 
    }

    if(_maturity > 3 && !_isEclos){
        this->eclosion(); 
    }
}

void Flower::sleep(){  
    _cut -= 1;
    _hydratation -=1; 
    _isFed = false; 
    this->grow();
    if(!_isEclos){
        _eclosionDays -=1; //Jours durant lesquels la fleur est dans l'état éclos.
        if(_eclosionDays <= 0){
            this->faner();  // Fane si les jours sont finis
        }
    }
}

 
#endif