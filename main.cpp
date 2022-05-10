#include "botanist.cpp"
#include "plant.cpp"
#include "flower.cpp"


#include <thread>
#include <iostream>
#include <string>

using namespace std; 


int main(){
    
    int day = 1; 
    Botanist * newPlayer = new Botanist("Mathieu");

   
   
   




    while(day < 30){
        string action; 
        string choixAchat; 
        int choixPlante; 
        Plant * currentPlant; 
        string actionPlante = "0"; 

        cout << "Bonjour " << newPlayer->getName() <<". Vous êtes prêts à vous occuper de votre jardin ?" << endl; 
        cout << "Plantes : " << endl; 
        if(newPlayer->getPlants().size() > 0){
            for(int i = 0; i < newPlayer->getPlants().size(); i++){
                cout<< newPlayer->getPlants()[i]->getName() << " - Maturité : " << newPlayer->getPlants()[i]->getMaturity() << endl; 
            }
        }
        
        cout << "Argent : " << newPlayer->getMoney() << " - Engrais : " << newPlayer->getFertilizer(); 
        cout << endl; 
        cout << "Que voulez-vous faire ? 1 : Achetez une plante (60 dollarz) - 2 : Achetez un engrais (20 dollarz) - 3 : Vous occuper de vos plantes - 4 : Dormir" << endl; 
        cin >>  action ; 
        if(action == "1"){
           cout << "Quelle plante vous intéresse ? 1 : Agave - 2 : Arnica - 3 : Aloès - 4 : Enthurium - 5 : Flora Piranha" << endl; 
           cin >> choixAchat;
           if(choixAchat == "1"){
                newPlayer->buyPlant("Agave");
           }else if(choixAchat == "2"){
                newPlayer->buyPlant("Arnica");
           }else if(choixAchat == "3"){
                newPlayer->buyPlant("Aloès");
           }else if(choixAchat == "4"){
                newPlayer->buyFlower("Enthurium");
           }else if(choixAchat == "5"){
                newPlayer->buyCarnivore("Flora Piranha");
           }
        }else if(action == "2"){
            newPlayer->buyFertilizer();
        }else if(action == "3"){
            cout << "De quelle plante vous occuper ?" << endl; 
            for(int i = 0; i < newPlayer->getPlants().size(); i++){
                cout<< i+1 << " : " << newPlayer->getPlants()[i]->getName() << endl; 
            }
            cin >> choixPlante;
            currentPlant = newPlayer->getPlants()[choixPlante - 1]; 

            while(actionPlante != "5"){
                cout << "Que faire avec " << currentPlant->getName() << " ? 1 : Nourrir - 2 : Arroser - 3 : Tailler - 4 : Inspecter - 5 : Rien" << endl; 
                cin >> actionPlante;
                if(actionPlante == "1"){
                    if(newPlayer->getFertilizer() > 0){
                        newPlayer->useFertilizer(); 
                        currentPlant->feed();
                        currentPlant->checkState();
                    }else{
                        cout<< "Pas assez d'engrais !" << endl; 
                    }
                    
                }else if(actionPlante == "2"){
                    currentPlant->water();
                    currentPlant->checkState(); 
                }else if(actionPlante == "3"){
                    currentPlant->cut();
                    currentPlant->checkState();
                }else if(actionPlante == "4"){
                    cout << "Nom d'espèce : " << currentPlant->getName() << endl;
                    cout << "Santé : " << currentPlant->getHealth() << endl;
                    cout << "Hydratation : " << currentPlant->getHydratation() << endl;
                    cout << "Maturité : " << currentPlant->getMaturity() << endl;
                    cout << "Valeur : " << currentPlant->getValue() << endl;
                }
            }
        }else if(action == "4"){
            for(int i = 0; i < newPlayer->getPlants().size(); i++){
                newPlayer->getPlants()[i]->sleep(); 
            }
        }


        day++; 
    }


    return 0;
}