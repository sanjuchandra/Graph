#include <iostream>
#include <unordered_map>
#include <list>
#include <cstring>
using namespace std;

class Graph{
    unordered_map<string , list<pair<string , int>>> adjList;
    public:
    Graph(){

    }
    void addEdge(string src, string dest , bool bidir , int wt){
        adjList[src].push_back(make_pair(dest , wt));
        if(bidir){
            adjList[dest].push_back(make_pair(src, wt));
        }
    }

    void print_graph(){
        for(auto x : adjList){
            cout<<x.first<<" --> ";
            for(auto y : x.second){
                cout<<"( "<<y.first<<" , "<<y.second<<" ) , ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge("A", "B", true , 20);
    g.addEdge("A", "C", true , 10);
    g.addEdge("B", "D" , true , 40);
    g.addEdge("C", "D" , true , 30);
    g.addEdge("A", "D" , false , 50);
    g.print_graph();
    return 0;
}
