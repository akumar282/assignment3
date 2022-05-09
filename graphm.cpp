// --------------------- bintree.cpp -----------------------------------------
// Abhimanyu Kumar CSS 343 B
// 5/8/22 
// 4/24/22 
// --------------------------------------------------------------------------------------------------------------------
// This program is the repesentation a binary tree   
// -------------------------------------------------------------------------------------------------------------------- 
//
// --------------------------------------------------------------------------------------------------------------------
#include<iostream>
#include<fstream>
#include "graphm.h"


GraphM::GraphM(){
    for(int i = 1; i<MAXNODES; i++){
        for(int j = 1; j<MAXNODES; j++){
            T[i][j].dist = INFT;
            T[i][j].path = 0;
            T[i][j].visited = false;
            C[i][j] =  INFT;
        }
    }
}

void GraphM::buildGraph(ifstream &inFile){
    try{
        inFile >> size;
        string nodename;
        for(int i = 0; i< size; i++){
            getline(inFile, nodename);
            data[i] = nodename;
            cout << nodename << endl;
        }
        int source, end, dist;
        do{ 
            inFile >> source >> end >> dist;
            source--;
            end--;
            insertEdge(source, end, dist);
        } while (source != -1 and end != -1);
        
    } catch (out_of_range const&){
        cerr << "File was not opened";
    }
}

bool GraphM::insertEdge(int start, int end, int dist){
    if(start < 0 or end < 0){
        return false; 
    }
    C[start][end] = dist;
    return true;
}

bool GraphM::removeEdge(int start, int end){
    if(start < 0 or end < 0){
        return false; 
    }
    C[start][end] = 0;
    return true;
}

int GraphM::findShortestPath(){
    /*
    for (int source = 1; source <= nodeSize; source++) {
      T[source][source].dist = 0;
      // finds the shortest distance from source to all other nodes
      for (int i = 1; i<= nodeSize; i++) {
         find v //not visited, shortest distance at this point
         mark v visited  
         for each w adjacent to v
           if (w is not visited)
            T[source][w].dist=min(T[source][w].dist, T[source][v].dist+C[V][W]) 
      }
   }
   */
    for(int source = 1; source<= size; source++){\
        T[source][source].dist = 0;
        for(int i = 1; i<= size; i++){
            if(C[source][i] != INFT){
                T[source][i].dist = C[source][i];
                T[source][i].path = source;
            }
            for(int j = 1; j<=size; j++){
                
            }


        }
    }

}

void GraphM::display(int n1, int n2) const{

}

void GraphM::displayAll() const{

}