#ifndef BOTANIST_CPP
#define BOTANIST_CPP

#include "botanist.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;     

    Botanist::Botanist() : _name("Unknown"){
        Plant * newPlant = new Plant("Plante de débutant");
        _money = 100;
        _plants = {newPlant};
        _fertilizer = 5; 

    }

    Botanist::Botanist(string name) : _name(name){
        Plant * newPlant = new Plant("Plante de débutant");
        _money = 100;
        _plants = {newPlant};
        _fertilizer = 5; 
    }
       


    string Botanist::getName(){
        return _name;
    }

    vector<Plant *> Botanist::getPlants(){
        return _plants; 
    }

    int Botanist::getMoney(){
        return _money;
    }

    int Botanist::getFertilizer(){
        return _fertilizer;
    }

    void Botanist::useFertilizer(){
        _fertilizer -= 1;  
    }

    void Botanist::buyPlant(string speciesName){
        if(_money >= 60){
            Plant * newPlant = new Plant(speciesName);
            _plants.push_back(newPlant); 
            _money -= 60; 
        }else{
            cout << "Pas assez d'argent, une plante coûte 60 dollarz." << endl; 
        }
        
    }

    void Botanist::buyFlower(string speciesName){
        if(_money >= 60){
            Flower * newFlower = new Flower(speciesName);
            _plants.push_back(newFlower); 
            _money -= 60; 
        }else{
            cout << "Pas assez d'argent, une fleur coûte 60 dollarz." << endl; 
        } 
    }

    void Botanist::buyCarnivore(string speciesName){
        if(_money >= 60){
            Carnivore * newPlant = new Carnivore(speciesName);
            _plants.push_back(newPlant); 
            _money -= 60; 
        }else{
            cout << "Pas assez d'argent, une fleur coûte 60 dollarz." << endl; 
        }
        
    }

    void Botanist::buyFertilizer(){
        if(_money >= 20){
            _fertilizer += 1;
            _money -= 20;   
        }else{
            cout << "Pas assez d'argent, un engrais coûte 20 dollarz." << endl; 
        }
       
    }

    void Botanist::sellPlant(Plant plant){
        _money += plant.getValue(); 
        
        
        //RETIRE LA PLANTE DE LA LISTE DES PLANTES
    }

        



#endif