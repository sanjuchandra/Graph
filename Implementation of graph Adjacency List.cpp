#include <iostream>
#include <list>
#include <cstring>
using namespace std;


class Graph{
    int v;
    list<int> *adjList;
    public:

    Graph(int v){
        this->v = v;
        adjList = new list<int>[v];
    }

    void addEdge(int u , int v , bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void print_graph(){
        for(int i = 0 ; i < v ; i++){
            cout<<i<<"-->";
            for(auto d : adjList[i]){
                cout<<d<<" , ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0 , 1);
    g.addEdge(0 , 4);
    g.addEdge(4 , 3);
    g.addEdge(4 , 1);
    g.addEdge(3 , 1);
    g.addEdge(3 , 2);
    g.addEdge(2 , 1);
    g.print_graph();

}
