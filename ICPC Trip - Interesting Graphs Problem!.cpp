
#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <climits>

using namespace std;

template <class T>
class Graph{
    unordered_map<T , list< pair<T , pair<int , int>>> >adjlist;

    public:
    
    void addEdge(T u , T v , int train , int flight , bool bidir = true){
        adjlist[u].push_back(make_pair(v , make_pair(train , flight)));
        if(bidir){
            adjlist[v].push_back(make_pair(u , make_pair(train , flight)));
        }
    }

    void print(){
        for(auto x : adjlist){
            cout<<x.first<<" --> ";
            for(auto y : adjlist[x.first]){
                cout<<"{ "<<y.first<<" , "<<"( "<<y.second.first<<" , "<<y.second.second<<" ) }   ";
            }
            cout<<endl;
        }
    }


    const unordered_map<T , int> Djikstra_Algo_shortest_path(T src ){ //reference is returned to avoid unneccessary copy
        unordered_map<T , int> distance;
        unordered_map<T , bool> visited;
        set<pair<int , T>> s;

        for(auto x : adjlist){
            distance[x.first] = INT_MAX;
            visited[x.first] = false;
        }

        distance[src] = 0;
        s.insert({0 , src});

        while(!s.empty()){
            auto it = s.begin();
            T src = it->second;
            s.erase(it);
            visited[src] = true;
            for(auto x : adjlist[src]){
                if(!visited[x.first]){
                    int old_Dist = distance[x.first];
                    int new_Dist = distance[src] + x.second.first;
                    if(new_Dist < old_Dist){
                        distance[x.first] = new_Dist;
                        s.erase({old_Dist , x.first });
                        s.insert({new_Dist , x.first});
                    }
                }
            }
        }
        /*for(auto x : distance){
            cout<<x.first<<" "<<x.second<<endl;
        }*/
        return distance;
    }


    int min_cost(T src , T dest){
        unordered_map<T , int> dist1 = Djikstra_Algo_shortest_path(src); //dist1 shortest_dist_from_src
        unordered_map<T , int> dist2 = Djikstra_Algo_shortest_path(dest); //dist2 shortest_dist_from_dest

        int ans = INT_MAX;
        
        //iterate for all edges andhadhun

        for(auto x : adjlist){
            for(auto y : adjlist[x.first]){
                //edge = x to y 
                //threrefore dist1[x.first] + dist2[y.first] + y.second.second
                //cout<<dist1[x.first]<<" "<<y.second.second<<" "<<dist2[y.first]<<endl;
                ans = min(ans , dist1[x.first] + y.second.second + dist2[y.first]);
                //cout<<ans<<endl;
            }
        }
        return min(ans , dist1[dest]);
    }
};


int main(){
    Graph <string> g2;
    g2.addEdge("Amritsar" , "Jaipur" , 4 , 2);
    g2.addEdge("Amritsar" , "Delhi" , 1 , 8);
    g2.addEdge("Jaipur" , "Mumbai" , 8 , 4);
    g2.addEdge("Jaipur" , "Delhi" , 2 , 3);
    g2.addEdge("Delhi" , "Agra" , 1 , 6);
    g2.addEdge("Agra" , "Bhopal" , 2 , 1);
    g2.addEdge("Bhopal" , "Mumbai" , 3 , 2);
    //g2.print();
    cout<<g2.min_cost("Amritsar" , "Mumbai")<<endl;
}
