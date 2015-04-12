//
//  Assignment8.cpp
//  Assignment 8
//
//  Created by Nolawee Mengist on 4/6/15.
//  Copyright (c) 2015 nope. All rights reserved.
//

#include "Assignment8.h"
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>
using namespace std;

Graph::Graph(){
    
}

Graph::~Graph(){
    //dtor
}
void Graph::addEdge(string v1, string v2, int weight){
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);
        
    }
}
void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }
    
}

void Graph::graphInit(){
    ifstream myFile;
    int w = 0;
    myFile.open("zombieCities.txt");
    if(myFile){
        string line;
        while (getline(myFile, line)) {
            cout<<line<<endl;
            w++;
        }
        myFile.close();
    }
    myFile.open("zombieCities.txt");
    if (myFile) {
        bool first = false;
        string line2;
        while(getline(myFile, line2))
        {
            stringstream iss(line2);
            if(first == false){
                for(int i = 0; i<w; i++){
                    string name;
                    getline(iss, name, ',');
                    if(name != "cities"){
                        addVertex(name);
                    }
                }
                first = true;
            }
            else{
                bool found = false;
                string name;
                getline(iss, name, ',');
                for(int i = 0; i<(w-1); i++){
                    string d;
                    getline(iss, d, ',');
                    int distance = stoi(d);
                    if (distance != -1 && distance != 0) {
                        for(int r = 0; r < vertices[i].adj[r].weight; r++){
                            if (distance == vertices[i].adj[r].weight) {
                                found = true;
                                break;
                            }
                        }
                    }
                    if(found == false){
                        addEdge(name, vertices[i].name, distance);
                    }
                }
            }
        }
        myFile.close();
    }
}
void Graph::BFTraversal(){
    vertex v;
    int districtID = 1;
    queue<vertex*> bfq;
    
    for(int j = 0; j < vertices.size(); j++){
        vertices[j].visited = false;
    }
    
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].visited == false)
        {
            vertices[i].visited = true;
            vertices[i].ID = districtID;
            districtID++;
            bfq.push(&vertices[i]);
            
        }
    
        
        while(!bfq.empty())
        {
            v = *bfq.front();
            bfq.pop();
            for(int i = 0; i < v.adj.size(); i++)
            {
                if(v.adj[i].v->visited == false)
                {
                    bfq.push(v.adj[i].v);
                    v.adj[i].v->visited = true;
                    v.adj[i].v->ID = vertices[i].ID;
                }
            }
        }
    }
}

void Graph::Dijkstra(string starting, string destination){
    vector<vertex*> solved;
    vertex *end = nullptr;
    vertex *minVertex = NULL;
    int minDist = 0;
    
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
        vertices[i].previous = NULL;
        vertices[i].distance = INT_MAX;
        if (vertices[i].name == starting){
            vertices[i].visited = true;
            solved.push_back(&vertices[i]);
            vertices[i].distance = 0;
        }
        if (vertices[i].name == destination){
            end = &vertices[i];
        }
    }
    
    while(end->visited == false){
        minDist = INT_MAX;
        for (int u = 0; u < solved.size(); u++){
            for(int j = 0; j < solved[u]->adj.size(); j++){
                if(solved[u]->adj[j].v->visited == false && solved[u]->distance + solved[u]->adj[j].weight < minDist){
                    minDist = solved[u]->distance + solved[u]->adj[j].weight;
                    minVertex = solved[u]->adj[j].v;
                    minVertex->previous = solved[u];
                }
            }
        }
        solved.push_back(minVertex);
        minVertex->visited = true;
        minVertex->distance = minDist;
    }
    
    vertex *node = end;
    vector<string> qp;
    while(node != NULL){
        qp.push_back(node->name);
        node = node->previous;
    }
    cout << "Shortest Path" << endl;
    for (unsigned long i = qp.size() - 1; i > 0; i--){
        cout << qp[i];
        if(i > 0){
            cout << " - ";
        }
    }
    cout << "\nMinimum Distance: " << minDist << endl;
}

void Graph::printVertices(){
    for (int i; i < vertices.size(); i++) {
        cout<< vertices[i].ID <<":"
        <<vertices[i].name<<"-->";
        for (int j = 0; j < vertices[j].adj.size(); j++) {
            cout<<vertices[i].adj[j].v->name;
            if (j != vertices[i].adj.size()-1)
                cout<<"***";
        }
    }
        
}

void Graph::FindShortestPath(){
    vertex start;
    vertex end;
    string starting;
    string destination;
    
    cout << "Enter a starting city:" << endl;
    cin >> starting;
    
    cout << "Enter an ending city:" << endl;
    cin >> destination;
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == starting){
            start = vertices[i];
            starting = "found";
        }
        if (vertices[i].name == destination) {
            end = vertices[i];
            destination = "found";
        }
    }
    
    if(starting != "found" or destination != "found"){
        cout << "One or more cities doesn't exist" << endl;
    }
    else if(starting == "found" and destination == "found"){
        if(start.ID == end.ID){
            //placeholder
            for (int i =0; vertices[i].distance; i++) {
                cout<<vertices[i].distance<<endl;
            }
            //cout<< distance;
        }
        else if (start.ID == 0 || end.ID == 0)
        {
            cout<<"Please identify the districts before checking distances"<< endl;
        }
        else{
            cout << "No safe path between cities" << endl;
        }
    }
    
    
}