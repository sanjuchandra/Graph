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

    void single_source_shortest_path(T start_node){
        queue<pair<T , int>> Q;
        unordered_map<T , bool> visited;
        Q.push({start_node , 0});
        visited[start_node] = true;
        cout<<" SOURCE "<<" DESTINATION "<<" DISTANCE "<<endl;
        while(!Q.empty()){
            pair<T , int> front = Q.front();
            Q.pop();
            cout<<"    "<<start_node<<"         "<<front.first<<"        "<<front.second<<endl;
            for(auto x : adjList[front.first]){
                if(!visited[x]){
                    Q.push({x , front.second + 1});
                    visited[x] = true;
                }
            }
        }
    }
};

int main(){
    Graph <int>g3;
    g3.addEdge(0 , 1);
    g3.addEdge(0 , 4);
    g3.addEdge(1 , 2);
    g3.addEdge(2 , 4);
    g3.addEdge(4 , 3);
    g3.addEdge(3 , 5);
    //g3.print_graph();
    g3.single_source_shortest_path(5);
    //g3.BFS(2);

}
