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

using namespace std;

Graph::Graph()
{
    
}

Graph::~Graph()
{
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

void Graph::BFTraversal(string startingCity)
{
    vertex v;
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
        if(vertices[i].name == startingCity)
        {
            vertices[i].visited = true;
            v = vertices[i];
        }
    }
    queue<vertex*> bfq;
    bfq.push(&v);
    while(!bfq.empty())
    {
        v = *bfq.front();
        bfq.pop();
        cout<<v.name<<endl;
        for(int i = 0; i < v.adj.size(); i++)
        {
            if(v.adj[i].v->visited == false)
            {
                bfq.push(v.adj[i].v);
                v.adj[i].v->visited = true;
            }
        }
    }
}
