#pragma once

#include "nodedata.h"
#include <iostream>

class GraphM { 
    private:
        static const int MAXNODES = 100;
        static const int INFT = INT32_MAX;

        struct TableType{
            bool visited;
            int dist;
            int path;
        };
        
        NodeData data[MAXNODES];
        int C[MAXNODES][MAXNODES];
        int size;
        TableType T [MAXNODES][MAXNODES];

    public: 
        GraphM();
        void buildGraph(ifstream &);
        bool insertEdge(int start, int end, int dist);
        bool removeEdge(int start, int end);
        int findShortestPath();
        void displayAll() const; 
        void display(int n1, int n2) const;

};
