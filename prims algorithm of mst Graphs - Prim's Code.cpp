#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int , int>> graph[n+1];
    bool visitd[n+1] = {0};
    while(m--){
        int x , y , wt;
        cin>>x>>y>>wt;
        graph[x].push_back({y , wt});
        graph[y].push_back({x , wt});
    }
    long long int mst = 0;
    set<pair<int , int>> s;
    s.insert({0 , 1});
    while(!s.empty()){
        auto it = s.begin();
        s.erase(it);
        if(!visitd[it->second]){
            visitd[it->second] = true;
            mst += it->first;
        }
        else{
            continue;
        }
        for(auto x : graph[it->second]){
            if(!visitd[x.first]){
                s.insert({x.second , x.first});
            }
        }
    }
    cout<<mst<<endl;

}
