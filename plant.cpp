#ifndef PLANT_CPP
#define PLANT_CPP

#include "plant.h"
#include <string>
#include <vector>
#include <iostream>


using namespace std;     

    Plant::Plant() : _speciesName("Non répertoriée"){
        _maturity = 1;
        _health = 4;
        _cut = 2;
        _hydratation = 2; 
        _isAlive = true; 
        _isFed = false; 
        _value = 60; 
    }

     Plant::Plant(string name) : _speciesName(name){
        _maturity = 1;
        _health = 4;
        _cut = 2;
        _hydratation = 2; 
        _isAlive = true; 
        _isFed = false;
        _value = 60; 
    }
       


        string Plant::getName(){
            return _speciesName;
        }

        bool Plant::getAlive(){
            return _isAlive; 
        }
        

        int Plant::getHydratation(){
            return _hydratation; 
        }

        int Plant::getMaturity(){
            return _maturity; 
        }
    

        int Plant::getHealth(){
            return _health; 
        }


        int Plant::getCut(){
            return _cut; 
        }

        int Plant::getValue(){
            return _value; 
        }


        void Plant::checkState(){
            if(_cut > 3){
                cout << "Vous avez trop taillé votre plante, sa santé se dégrade" << endl; 
                _health -= 1; 
                _cut -= 1; 
            }else if(_cut < 1){
                cout << "Vous n'en prenez pas soin, sa santé se dégrade" << endl; 
                _health -= 1; 
            }

            if(_hydratation > 3){
                cout << "N'arrosez pas trop ! Votre plante se noie, sa santé se dégrade" << endl; 
                _health -= 1; 
                _hydratation -= 1; 
            }else if(_hydratation < 1){
                cout << "Vous ne l'arrosez pas, sa santé se dégrade" << endl; 
                _health -= 1; 
            }

            if(_health <= 0){
                cout << "Vous avez trop maltraité votre plante, elle est décédée..." << endl; 
                _isAlive = false; 
            }
        }


        void Plant::cut(){
            _cut += 1; 
        }


        void Plant::water(){
            _hydratation += 1; 
        }

        void Plant::grow(){
            if(_health < 3){
                _maturity -=1;
            }else if(_health > 5){
                _maturity += 1;
            }

            if(_maturity <= 0){
                cout <<  _speciesName <<" ne pousse plus, elle est décédée..." << endl; 
                _isAlive = false; 
            }

        }


        void Plant::feed(){
            if(!_isFed){
                _health += 1;
                _maturity +=1; 
                _isFed = true;
            }else{
                cout << "La plante a déjà été nourrie aujourd'hui." << endl; 
            }
            
        }

        void Plant::sleep(){  
            _cut -= 1;
            _hydratation -=1; 
            _isFed = false; 
            this->grow();
 
        }






#endif