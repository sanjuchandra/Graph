#include <iostream>
#include <list>
#include <cstring>
#include <map>
#include <queue>
#include <unordered_map>
#include <climits>
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

    void single_source_shortest_path_my(T start_node){
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
    void single_source_shortest_path_prateek(T start_node){
        queue<T> Q;
        unordered_map<T , int> dist;
        for(auto x : adjList){
            dist[x.first] = INT_MAX;
        }
        Q.push(start_node);
        dist[start_node] = 0;

        while(!Q.empty()){
            T front = Q.front();
            Q.pop();

            for(auto x : adjList[front]){
                if(dist[x] == INT_MAX){
                    Q.push(x);
                    dist[x] = dist[front] + 1;
                }
            }
        }
        for(auto d : dist){
            cout<<d.first<<" at D "<<d.second<<endl;
        }
    }


    void dfs_helper(T src , map<T , bool> &visited){
        cout<<src<<" ";
        visited[src] = true;
        for(auto x : adjList[src]){
            if(!visited[x]){
                dfs_helper(x , visited);
            }
        }
        return;
    }

    void dfs(){
        map<T , bool> visited;
        for(auto x : adjList){
            visited[x.first] = false;
        }

        int component = 0;
        for(auto x : adjList){
            if(!visited[x.first]){
                cout<<"component "<<component<<" : ";
                dfs_helper(x.first , visited);
                cout<<endl;
                component++;
            }
        }
        cout<<"Total "<<component<<" components"<<endl;
    }
    
};

int main(){
    Graph <int>g3;
    g3.addEdge(0 , 1);
    g3.addEdge(0 , 3);
    g3.addEdge(1 , 2);
    g3.addEdge(3 , 4);
    g3.addEdge(4 , 5);
    g3.addEdge(7 , 8);
    g3.addEdge(9 , 10);
    g3.addEdge(10 , 11);
    g3.addEdge(11 , 89);
    g3.addEdge(10000 , -1);
    g3.dfs();

}
