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
    int snake_and_ladder(T src , T dest){
        queue<T> Q;
        unordered_map<T , int> dist;
        unordered_map<T , int> parent;
        for(auto x : adjList){
            dist[x.first] = INT_MAX;
        }
        Q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!Q.empty()){
            T front = Q.front();
            Q.pop();

            for(auto x : adjList[front]){
                if(dist[x] == INT_MAX){
                    Q.push(x);
                    dist[x] = dist[front] + 1;
                    parent[x] = front;
                }
            }
        }
        T temp = dest;
        while(temp != src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;
        return dist[dest];
    }
};

int main(){
    
    Graph<int> g;
    int jump[50] = {0};
    jump[2] = 13;
    jump[5] = 2;
    jump[9] = 18;
    jump[18] = 11;
    jump[17] = -13;
    jump[20] = -14;
    jump[24] = -8;
    jump[25] = -10;
    jump[32] = -2;
    jump[34] = -22;


    for(int u = 0 ; u <= 36 ; u++){
        for(int dice = 1 ; dice <= 6 ; dice++){
            int v = u + dice + jump[u + dice];
            g.addEdge(u , v , false);
        }
    }
    cout<<g.snake_and_ladder(4 , 36)<<endl;
    return 0;

}
