// --------------------- graphl.cpp -----------------------------------------
// Abhimanyu Kumar CSS 343 B
// 5/8/22 
// 4/24/22 
// --------------------------------------------------------------------------------------------------------------------
// This program is the repesentation of dijistras algoritmn   
// -------------------------------------------------------------------------------------------------------------------- 
//
// --------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<fstream>
#include "graphl.h"
#include <algorithm>
#include <iomanip>
// --------------------- GraphL() -----------------------------------------
// Default constructor
// --------------------------------------------------------------
GraphL::GraphL(){
    size = 0;
    for(int i = 0; i < MAXNODES; i++) {
        nodeArr[i].edgeHead = NULL;
        nodeArr[i].data = NULL;
        nodeArr[i].visited = false;
    }
}
// --------------------- ~GraphL() -----------------------------------------
// Destructor
// --------------------------------------------------------------
GraphL::~GraphL(){
    for(int i = 1; i <= size; i++) {
        nodeArr[i].visited = false;
        delete nodeArr[i].data;
        nodeArr[i].data = NULL;
        if(nodeArr[i].edgeHead != NULL) {
            EdgeNode* target = nodeArr[i].edgeHead;
            while(target != NULL) {
                nodeArr[i].edgeHead = nodeArr[i].edgeHead -> nextEdge;
                delete target;
                target = NULL;
                target = nodeArr[i].edgeHead;
            }
        }
    }
}
// --------------------- buildGraph() -----------------------------------------
// Builds up graph node information and adjacency list of edges between each
// --------------------------------------------------------------
void GraphL::buildGraph(ifstream& inFile){
    try {
        int n1, n2;
        inFile >> size;
        if(size > 0) {
            string str;
            getline(inFile, str);
            for(int i = 1; i <= size; i++) {
                nodeArr[i].data = new NodeData();
                nodeArr[i].data -> setData(inFile);
            }
            while(inFile >> n1 >> n2) {
                if(n1 == 0) {
                    break;
                }
                EdgeNode* node = new EdgeNode;
                node -> adjGraphNode = n2;
                if(nodeArr[n1].edgeHead == NULL) {
                    nodeArr[n1].edgeHead = node;
                    nodeArr[n1].edgeHead -> nextEdge = NULL;
                } else {
                    node -> nextEdge = nodeArr[n1].edgeHead;
                    nodeArr[n1].edgeHead = node;
                }
            }
        }
    } catch (out_of_range const&) {
        cerr << "File was not opened" << endl;
    }
}
// --------------------- depthFirstSearch() -----------------------------------------
// Makes a depth-first search and displays each node in depth-first order
// --------------------------------------------------------------
void GraphL::depthFirstSearch(){
    cout << "Depth-first ordering: ";
    for(int i = 1; i <= size; i++) {
        if(!nodeArr[i].visited) {
            depthFHelp(i);
        }
    }
    cout << "\n" << endl;
}
// --------------------- depthFHelp() -----------------------------------------
// Helper function for depthFirstSearch()
// --------------------------------------------------------------
void GraphL::depthFHelp(int n1){
    cout << "  " << n1;
    nodeArr[n1].visited = true;
    EdgeNode* current = nodeArr[n1].edgeHead;
    while(current != NULL) {
        if(!nodeArr[current -> adjGraphNode].visited) {
            depthFHelp(current -> adjGraphNode);
        }
        current = current -> nextEdge;
    }
}
// --------------------- displayGraph() -----------------------------------------
// Displays each node information and edge in the graph
// --------------------------------------------------------------
void GraphL::displayGraph(){
    cout << "Graph: " << endl;
    for(int i = 1; i <= size; i++) {
        cout << "Node" << i << "\t\t " << *nodeArr[i].data << endl;
        cout << endl;
        EdgeNode* current = nodeArr[i].edgeHead;
        while(current != NULL) {
            cout << "  " << "edge  " << i << "  " << current -> adjGraphNode << endl;
            current = current -> nextEdge;
        }
    }
    cout << endl;
}