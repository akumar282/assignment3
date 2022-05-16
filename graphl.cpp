#include<iostream>
#include<fstream>
#include "graphl.h"
#include <algorithm>
#include <iomanip>

GraphL::GraphL(){
    size = 0;
    for(int i = 0; i < MAXNODES; i++) {
        nodeArr[i].edgeHead = NULL;
        nodeArr[i].data = NULL;
        nodeArr[i].visited = false;
    }
}

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

void GraphL::buildGraph(ifstream& inFile){
    try {
        int from, to;
        inFile >> size;
        if(size > 0) {
            string str;
            getline(inFile, str);
            for(int i = 1; i <= size; i++) {
                nodeArr[i].data = new NodeData();
                nodeArr[i].data -> setData(inFile);
            }
            while(inFile >> from >> to) {
                if(from == 0) {
                    break;
                }
                EdgeNode* node = new EdgeNode;
                node -> adjGraphNode = to;
                if(nodeArr[from].edgeHead == NULL) {
                    nodeArr[from].edgeHead = node;
                    nodeArr[from].edgeHead -> nextEdge = NULL;
                } else {
                    node -> nextEdge = nodeArr[from].edgeHead;
                    nodeArr[from].edgeHead = node;
                }
            }
        }
    } catch (out_of_range const&) {
        cerr << "File was not opened" << endl;
    }
}

void GraphL::depthFirstSearch(){
    cout << "Depth-first ordering: ";
    for(int i = 1; i <= size; i++) {
        if(!nodeArr[i].visited) {
            depthFHelp(i);
        }
    }
    cout << "\n" << endl;
}

void GraphL::depthFHelp(int v){
    cout << "  " << v;
    nodeArr[v].visited = true;
    EdgeNode* current = nodeArr[v].edgeHead;
    while(current != NULL) {
        if(!nodeArr[current -> adjGraphNode].visited) {
            depthFHelp(current -> adjGraphNode);
        }
        current = current -> nextEdge;
    }
}

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