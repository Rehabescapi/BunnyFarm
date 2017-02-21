//
//  main.cpp
//  Bunny Farm
//
//  Created by Jason Lehmann on 1/31/17.
//  Copyright © 2017 LehmannGames. All rights reserved.
//

#include <iostream>
#include "Bunny.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <Cmath>
using namespace std;

int  displayNUpdateBuns(vector <Bunny> & arg );
void removeDead( vector <Bunny> & arg);
void infectRound(vector <Bunny> & arg, vector <int> location);
void infectRound();
int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<Bunny> hoard;
    vector <string> bname;
    fstream myfile;
    string line;
    myfile.open("./Names.txt");
    
    if(myfile.is_open())
    {
        while ( getline (myfile,line))
        {
            
            bname.push_back(line);
        }
        myfile.close();
    }
    else
    {
        cout << "no file" << endl;
    }
    int bsize  = (int) bname.size();
    
    srand(time(NULL));
    int randomNum = rand () % bsize;
    int years = 0;

    cout << "Please enter number of years you want the farm to grow" <<endl;
   if ( !(cin >> years) )
    {
        cin.clear();
        cin.ignore();
        cout << "Incorrect entry. setting years to 50: ";
        years = 50;
    }
       int stock = 5;
    int counter = 1;
    while( counter ++ > years )
    {
       if(counter > 10  && stock == 0)
       {
           break;
           //
       }
        cout << "year " << counter;
        while (stock > 0)
        {
            
            hoard.push_back(Bunny (bname.at(randomNum)));
            randomNum = rand() % bsize;
            stock--;
        }
        cout << endl <<endl;
        
         stock = displayNUpdateBuns(hoard);
    }
}
void removeDead( vector <Bunny> & arg)
{
    int ssizzle = (int) arg.size();
    for(int i = 0; i < ssizzle ; i++)
    {
        if(arg.at(i).isDead())
        {
            cout << "goodbye " << arg.at(i).getName() << endl;
            arg.erase(arg.begin() + i);
            ssizzle--;
            i--;
            if(i < 0)
                continue;
        }
    }
}

int  displayNUpdateBuns(vector <Bunny> &arg)//Bunnies Reproduce and then deal with possible infection
{
    int breedable = 0;
    bool viableM = false;
    vector <int> infectSource;
    
    removeDead(arg);
    
    for(int i = 0 ; i < arg.size() ; i ++)
    {
        
        arg.at(i).ageOneYear();
       
       if(arg.at(i).isInfected())
        infectSource.push_back(i);
        
        if(arg.at(i).canBreed() && (arg.at(i).getSex() == 'm'))
            viableM = true;
        if(arg.at(i).canBreed() && (arg.at(i).getSex() == 'f'))
            breedable ++;
    }
    cout << "Infected Buns " << infectSource.size() << "  Total Buns " << arg.size()  << endl;
    if(infectSource.size() >0)
        infectRound(arg, infectSource);

       if(viableM)
    return breedable;
   else
    return 0;
  
}

void infectRound(vector <Bunny> & arg, vector <int> location)
{
    int rounds = (int)location.size();
    int infectorSource ,Spos, Sneg;
    
    for(int i = 0 ;i < rounds; i++)
    {
        infectorSource = location.at(i);
        Spos = infectorSource +1;
        Sneg = infectorSource -1;
        
        //not the most efficient way to spread infection 
        while(true)
        {
            if(Sneg < 0 || Spos >= arg.size())
            {
                break;
            }
            if(arg.at(Spos).infect(arg.at(infectorSource)))
            {
                break;
            }
            if(arg.at(Spos).infect(arg.at(infectorSource)))
            {
                break;
            }
            Spos ++;
            Sneg --;
        }
    }
    
}
