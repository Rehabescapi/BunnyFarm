//
//  Bunny.hpp
//  Bunny Farm
//
//  Created by Jason Lehmann on 1/31/17.
//  Copyright © 2017 LehmannGames. All rights reserved.
//

#ifndef Bunny_hpp
#define Bunny_hpp

#include <stdio.h>
#include "string"
#include <stdlib.h>
#include <iostream>
using namespace std;

static  int breedingBuns;
class Bunny
{
private:
    int age ,xLocation, yLocation;
    char sex;
    
   // string color;
    string Name;
    bool radioactive_mutant_vampire_bunny;
public:
    Bunny()
    {
        age = 1;
        sex = (rand()%2 > 0)? 'f': 'm';
        radioactive_mutant_vampire_bunny = (rand()% 100  < 2)? true : false;
        Name = "unknown";
    }
    Bunny(string k)
    {
        age = 1;
        sex = (rand()%2 > 0)? 'f': 'm';
        radioactive_mutant_vampire_bunny = (rand()% 100  < 2)? true : false;
        Name = k;
    }
    
    Bunny(string k, int xorigin , int yorigin)
    {
        
    }
    
    

    char getSex()
    {
        return sex;
    }
    
    string getName(){
    return Name;
    }
    
    bool canBreed();

    void ageOneYear()
    {
        age++;
    }
    bool isDead();
    void showBuns();
    bool isInfected()
    {
        return radioactive_mutant_vampire_bunny;
    }
    bool infect(Bunny & spreader);
    
    
    
};



#endif /* Bunny_hpp */
