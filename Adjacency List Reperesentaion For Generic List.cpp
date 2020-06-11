#include <iostream>
#include <list>
#include <cstring>
#include <map>
using namespace std;

template<class T>
class Graph{
    map<T , list<T>> adjList;
    public:

    Graph(){
        
    }

    void addEdge(T u , T v , bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void print_graph(){
        for(auto x : adjList){
            cout<<x.first<<"-->";
            for(auto d : x.second){
                cout<<d<<" , ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Putin" , "Trump" , false);
    g.addEdge("Putin" , "Modi" , false);
    g.addEdge("Putin" , "Pope" , false);
    g.addEdge("Modi" , "Trump" , true);
    g.addEdge("Modi" , "Yogi" , true);
    g.addEdge("Yogi" , "Prabhu" , false);
    g.addEdge("Prabhu" , "Modi" , false);
    g.print_graph();


    Graph<int> g2;
    g2.addEdge(0 , 1);
    g2.addEdge(0 , 4);
    g2.addEdge(4 , 3);
    g2.addEdge(4 , 1);
    g2.addEdge(3 , 1);
    g2.addEdge(3 , 2);
    g2.addEdge(2 , 1);
    g2.print_graph();

}
