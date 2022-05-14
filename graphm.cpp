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
#include <algorithm>


GraphM::GraphM(){
    for(int i = 0; i<MAXNODES; i++){
        for(int j = 0; j<MAXNODES; j++){
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
        string nodename = "";
        for(int i = 0; i< size; i++){
            if(inFile.eof()){
                    return;
                }
            getline(inFile, nodename);
            if(nodename == "\r"){
                getline(inFile, nodename);
            }
            nodename.pop_back();
            data[i] = nodename;
            cout << nodename << endl;
        }
        int source, end, dist;
        do{ 
            inFile >> source >> end >> dist;
            source--;
            end--;
            cout << source <<" "<< end << " " << dist << endl;
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

void GraphM::findShortestPath(){
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
    for(int source = 1; source<= size; source++){
        T[source][source].dist = 0;
        T[source][source].visited = true;
        for(int i = 1; i<= size; i++){
            int cost = INFT;
            int index = -1; 
            for(int j = 1; j<=size; j++){
                if(T[source][j].dist < cost){
                    cost = T[source][j].dist;
                    index = j;
                }
            }
            T[source][index].visited = true;
            for(int j = 1; j<=size; j++){
                if(!T[source][j].visited && C[index][j]!= INFT){
                    if(T[source][j].dist > T[source][index].dist+C[index][j]){
                        T[source][j].dist = T[source][index].dist+C[index][j];
                        T[source][j].path = index; 
                    }
                    
                }
            }
        }
    }

}

void GraphM::display(int n1, int n2) const{
    cout<< n1 <<"   "<< n2;
    if(C[n1][n2] < INFT){
        cout << T[n1][n2].dist << endl;
        displayPathHelp(n1, n2);
        cout << endl;
    }
}

void GraphM::displayPathHelp(int n1, int n2) const{
    int othercol = T[n1][n2].path;
    if(othercol != 0){
        cout<< n2 << " ";
        displayPathHelp(n1, othercol);
    } else {
        cout << n1 << endl;
    }
}


void GraphM::displayAll() const{

}