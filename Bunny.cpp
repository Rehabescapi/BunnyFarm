//
//  Bunny.cpp
//  Bunny Farm
//
//  Created by Jason Lehmann on 1/31/17.
//  Copyright © 2017 LehmannGames. All rights reserved.
//

#include "Bunny.hpp"


bool Bunny::canBreed()
{
    if(this->age > 2 && !(this->radioactive_mutant_vampire_bunny))
    {
        return true;
    }
    else return false;
}

bool Bunny::infect(Bunny & spreader)
{
    if(this->radioactive_mutant_vampire_bunny == true)
    {
        return false;
    }
   
    
        this->radioactive_mutant_vampire_bunny = true;
    cout << this->Name << " was infected by " << spreader.getName() << endl;
    return true;
}

bool Bunny::isDead()
{
        if (this->age > 10 && (this->radioactive_mutant_vampire_bunny == false))
    {
              return true;
    }
        else if (this -> age > 50){
            return true;
        }
    
    else
        return false;
}

void Bunny::showBuns()
{
    cout << this->Name << "  sex: " << sex << " age :" << age;
    if(this->radioactive_mutant_vampire_bunny)
    {
        cout << "  Rabid " << endl;
        
    }else
        cout << "  Normal " << endl;
    
}
