#pragma once
#include "nodedata.h"

class GraphL {
    public:
        GraphL();
        ~GraphL();
        void buildGraph(ifstream&);
        void depthFirstSearch();
        void displayGraph();
    private:
        int size;
        static int const MAXNODES = 100; 
        struct EdgeNode;

        struct GraphNode {
        EdgeNode* edgeHead;       
        NodeData* data;           
        bool visited;
    };
        GraphNode nodeArr[MAXNODES];
        
        struct EdgeNode {
        int adjGraphNode;           
        EdgeNode* nextEdge;        
    };
    void depthFHelp(int n1);
};

