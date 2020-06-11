#include <iostream>
#include <list>
#include <cstring>
#include <map>
#include <queue>
#include <unordered_map>
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

    void BFS(T start_node){
        queue<T> Q;
        unordered_map<T , bool> marker;
        Q.push(start_node);
        marker[start_node] = true;
        while(!Q.empty()){
            T front = Q.front();
            Q.pop();
            cout<<front<<" ";
            for(auto x : adjList[front]){
                if(!marker[x]){
                    Q.push(x);
                    marker[x] = true;
                }
            }
        }
        cout<<endl;
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
    //g.print_graph();
    g.BFS("Modi");

    Graph<int> g2;
    g2.addEdge(0 , 1);
    g2.addEdge(0 , 4);
    g2.addEdge(4 , 3);
    g2.addEdge(4 , 1);
    g2.addEdge(3 , 1);
    g2.addEdge(3 , 2);
    g2.addEdge(2 , 1);
    //g2.print_graph();
    g2.BFS(3);

    Graph <int>g3;
    g3.addEdge(0 , 1);
    g3.addEdge(0 , 4);
    g3.addEdge(1 , 2);
    g3.addEdge(2 , 4);
    g3.addEdge(4 , 3);
    g3.addEdge(3 , 5);
    //g3.print_graph();
    g3.BFS(0);
    g3.BFS(2);

}
