//
//  main.cpp
//  Assignment 8
//
//  Created by Nolawee Mengist on 4/6/15.
//  Copyright (c) 2015 nope. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Assignment8.h"
#include <sstream>
#include <string>
void displayMenu();
using namespace std;

int main(int argc, const char * argv[])
{
    Graph g;
    g.graphInit();
    string command;
    displayMenu();
    getline(cin, command);
    while (command != "6") {
        if (command == "1") {
            cout<<"Printing Verticies"<<endl;
        }
        else if (command == "2")
        {
            cout<<"Finding districts"<<endl;
            
        }
        else if (command == "3")
        {
            cout<<"Finding shortest path"<<endl;
        }
        else if (command == "4")
        {
            cout<<"Finding shortest distance"<<endl;
        }
        else if (command == "5")
        {
            cout<<"Shit I'm not doing"<<endl;
        }
        else
            cout<<"Invalid Selection"<<endl;
        displayMenu();
        getline(cin, command);
    }
    
    return 0;
}


/*displays a menu with options to enqueue and dequeue a message and transmit the entire message and quit*/
void displayMenu()
{
    cout << "======Main Menu=====" << endl;
    cout << "1. Print verticies" << endl;
    cout << "2. Find districts" << endl;
    cout << "3. Find shortest Path" << endl;
    cout << "4. Find shortest Distance" << endl;
    cout << "5. Extra Credit" << endl;
    cout << "6. Quit" << endl;
    return;
}
/*
void printVertices(){
    cout<< verticies[i].district << ":"
    <<vertices[i].name<<"-->";
    for(int i = 0; i < v.adj.size(); i++){
        
    }

 }
*/