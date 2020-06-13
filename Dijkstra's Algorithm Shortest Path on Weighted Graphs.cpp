#include <iostream>
#include <unordered_map>
#include <set>
#include <climits>
#include <list>
#include <cstring>
using namespace std;

template <class T>
class Graph{
    unordered_map<T , list<pair<T , int>>> adjlist;

    public:
    void addEdge(T u , T v , int d , bool bidir = true){
        adjlist[u].push_back({v , d});
        if(bidir){
            adjlist[v].push_back({u , d});
        }
    }
    class cmp{
    public:
        bool operator () (const pair<T, int>&x , const pair<T , int> &y){
            return x.second <= y.second;
        }
    };
    void print(){
        for(auto x : adjlist){
            cout<<x.first<<" --> ";
            for(auto y : x.second){
                cout<<" ( "<<y.first<<", "<<y.second<<" ) ";
            }
            cout<<endl;
        }
    }

    void Djikstra_Algo_shortest_path(T src){
        unordered_map<T , int> distance;
        unordered_map<T , bool> visited;
        set<pair<T , int> , cmp> s;

        for(auto x : adjlist){
            distance[x.first] = INT_MAX;
            s.insert({x.first , INT_MAX});
            visited[x.first] = false;
        }

        s.erase({src , INT_MAX});
        s.insert({src , 0});
        distance[src] = 0;

        while(!s.empty()){
            auto it = s.begin();
            T src = it->first;
            visited[src] = true;
            s.erase(it); 
            // distance already updated
            for(auto x : adjlist[src]){
                if(!visited[x.first]){
                    int old_Dist = distance[x.first];
                    int new_Dist = distance[src] + x.second;
                    if(new_Dist < old_Dist){
                        distance[x.first] = new_Dist;
                        s.erase(x);
                        s.insert({x.first , new_Dist});
                    }
                }
            }  
        }

        cout<<"Source "<<src<<endl;
        for(auto x : distance){
            cout<<x.first<<" D "<<x.second<<endl;
        }
    }

};


int main(){
    Graph <int> g;
    g.addEdge(1 , 2 , 1);
    g.addEdge(1 , 3 , 4);
    g.addEdge(1 , 4 , 7);
    g.addEdge(2 , 3 , 1);
    g.addEdge(3 , 4 , 2);
    g.addEdge(4 , 5 , 2);
    g.addEdge(3 , 5 , 1);
    //g.print();
    g.Djikstra_Algo_shortest_path(1);


    Graph <string> g2;
    g2.addEdge("Amritsar" , "Jaipur" , 4);
    g2.addEdge("Amritsar" , "Delhi" , 1);
    g2.addEdge("Jaipur" , "Mumbai" , 8);
    g2.addEdge("Jaipur" , "Delhi" , 2);
    g2.addEdge("Delhi" , "Agra" , 1);
    g2.addEdge("Agra" , "Bhopal" , 2);
    g2.addEdge("Bhopal" , "Mumbai" , 3);
    //g2.print();
    g2.Djikstra_Algo_shortest_path("Amritsar");
    return 0;
}
