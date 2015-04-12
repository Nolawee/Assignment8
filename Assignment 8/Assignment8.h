//
//  Assignment8.h
//  Assignment 8
//
//  Created by Nolawee Mengist on 4/6/15.
//  Copyright (c) 2015 nope. All rights reserved.
//  Worked with Sami Meharzi

#ifndef Assignment_8_Assignment8_h
#define Assignment_8_Assignment8_h
#include <vector>
#include <iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    bool visited;
    //int weight;
    int distance;
    vertex *previous;
    std::vector<adjVertex> adj;
    int ID = 0;
};

class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2, int weight);
    void addVertex(std::string name);
    void displayEdges();
    void BFTraversal();
    void Dijkstra(std::string sourceVertex, std::string destinationVertex);
    void graphInit();
    void printVertices();
    void FindShortestPath(/*std::string starting, std::string destination*/);
protected:
private:
    //vector<edge> edges;
    std::vector<vertex> vertices;
    
};

#endif
