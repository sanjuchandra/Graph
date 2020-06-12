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

    void const print_map(const unordered_map<T , pair<bool , bool>> &status){
        for(auto x : status){
            cout<<x.first<<" --> "<<x.second.first<<" , "<<x.second.second<<endl;
        }
        cout<<endl;
    }

    bool isCyclic_helper(T src , unordered_map<T , pair<bool , bool>>& status){
        status[src] = make_pair(true , true);
    
        for(auto x : adjList[src]){
            if(!status[x].first){
                bool ans = isCyclic_helper(x , status);
                if(ans){
                    //status[src].second = false;
                    return true;
                }
            }
            else if(status[x].first and status[x].second){
                //status[src].second = false;
                return true;
            }
            else if(status[x].first and !status[x].second){ //node which is already visited and is out of stack now
                break;
            }
        }
        status[src].second = false;
        return false;
    }

    bool isCyclic(){
        unordered_map<T , pair<bool , bool >> status;  //element , {visited , instack}
        for(auto x : adjList){
            status[x.first] = make_pair(false , false);
        }

        for(auto x : adjList){
            if(!status[x.first].first){
                bool ans = isCyclic_helper(x.first , status);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }

};

int main(){
    Graph <int> g;
    /*g.addEdge(1 , 2 , false);
    g.addEdge(1 , 3 , false);
    g.addEdge(2 , 4 , false);
    g.addEdge(3 , 4 , false);
    //g.addEdge(4 , 5 , false);
    g.addEdge(4 , 5 , false);
    g.addEdge(4 , 7 , false);
    g.addEdge(5 , 6 , false);
    g.addEdge(6 , 7 , false);
    g.addEdge(7 , 9 , false);
    g.addEdge(7 , 7 , false);*/
    g.addEdge(0 , 2 , false);
    g.addEdge(0 , 1 , false);
    g.addEdge(2 , 3 , false);
    g.addEdge(2 , 4 , false);
    g.addEdge(1 , 5 , false);
    g.addEdge(3 , 0 , false);
    //g.print_graph();
    if(g.isCyclic()){
        cout<<"Cyclic Directed Graph"<<endl;
    }
    else{

        cout<<"Non Cyclic Directed graph"<<endl;
    }
    /*unordered_map<int , pair<bool , bool>> status;
    status[4] = make_pair(false , false);
    status[1] = make_pair(true , true);
    bool ans = g.isCyclic_helper(4 , status);
    cout<<ans<<endl;
    for(auto x : status){
        cout<<x.first<<" --> "<<x.second.first<<" , "<<x.second.second<<endl;
    }*/
    return 0;
}
