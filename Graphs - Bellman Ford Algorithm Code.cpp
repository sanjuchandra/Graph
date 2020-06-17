#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> Bellman_ford(const int n , const vector<vector<int>> &edges , int src = 1){
    vector<int> dist(n+1 , INT_MAX);
    dist[src] = 0;

    for(int i = 1 ; i <= n-1 ; i++){
        for(auto x : edges){
            int from = x[0];
            int to = x[1];
            int wt = x[2];
            if(dist[from] != INT_MAX and dist[to] > dist[from] + wt){
                dist[to] = dist[from] + wt;
            }
        }
    }

    for(auto x : edges){
            int from = x[0];
            int to = x[1];
            int wt = x[2];
            if(dist[from] != INT_MAX and dist[to] > dist[from] + wt){
                cout<<"Negative Edge Cycle"<<'\n';
                exit(0);
            }
    }
    return dist;
}



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;

    for(int i = 0 ; i < m ; i++){
        int from , to , wt;
        cin>>from>>to>>wt;
        edges.push_back({from , to , wt});
    }

    vector<int> ans = Bellman_ford(n , edges);
    for(int i = 1 ; i <= n ; i++){
        cout<<"Dist of "<<i<<" from src "<<1<<" is "<<ans[i]<<endl;
    }
    return 0;
}
