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


    void dfs_helper(T src , map<T , bool> &visited , list<T> &ordering){
        visited[src] = true;
        for(auto x : adjList[src]){
            if(!visited[x]){
                dfs_helper(x , visited , ordering);
            }
        }
        ordering.push_front(src);
        return;
    }

    void dfs_topological(){
        map<T , bool> visited;
        list<T> ordering;
        for(auto x : adjList){
            visited[x.first] = false;
        }
        
        for(auto x : adjList){
            if(!visited[x.first]){
                dfs_helper(x.first , visited , ordering);
            }
        }
        for(auto x : ordering){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    void BFS_topological(){
        unordered_map<T , int> indegree;
        unordered_map<T , bool> visited;
        queue<T> Q;
        for(auto x : adjList){
            indegree[x.first] = 0;
            visited[x.first] = false;
        }
        //calculate indegree
        for(auto x : adjList){
            for(auto y : adjList[x.first]){
                indegree[y]++;
            }
        }
        //push elements with 0 indegree to queue
        for(auto x : indegree){
            if(x.second == 0){
                Q.push(x.first);
                visited[x.first] = true; 
            }
        }
        if(Q.empty()){
            cout<<"Khali Queue hai"<<endl;
        }
        //main algo
        while(!Q.empty()){
            T front = Q.front();
            Q.pop();
            cout<<front<<" ";
            for(auto x : adjList[front]){
                if(!visited[x]){
                    indegree[x]--;
                    if(indegree[x] == 0){
                        Q.push(x);
                        visited[x] = true;
                    }
                }
            }
        }
    }

    bool isTree(){
        unordered_map<T , bool> visited;
        unordered_map<T , T> parent;
        queue<T> Q;
        for(auto x : adjList){
            visited[x.first] = false;
            parent[x.first] = x.first;
        }

        T src;
        for(auto x : adjList){
            src = x.first;
            break;
        }
        Q.push(src);
        visited[src] = true;
        //parent[src] = src;

        while(!Q.empty()){
            //cout<<"Inside "<<endl;
            T front = Q.front();
            Q.pop();
            for(auto x : adjList[front]){
                if(!visited[x]){
                    parent[x] = front;
                    visited[x] = true;
                    Q.push(x);
                }
                else if(parent[front] != x and visited[x]){
                    return false;
                }
            }
        }
        return true;
    }

    
};

int main(){
    Graph <int>g;
    g.addEdge(1 , 2);
    g.addEdge(1 , 3);
    g.addEdge(3 , 4);
    g.addEdge(2 , 4);
    if(g.isTree()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;

}
