#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;


struct DSU{
    vector<int> parent , size;

    void init(int n){
        parent.resize(n);
        size.resize(n);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int get_super_parent(int x){
        if(parent[x] == x) return x;
        //path compression
        return parent[x] = get_super_parent(parent[x]); 
    }

    void unite(int x , int y){
        int super_parent_x = get_super_parent(x);
        int super_parent_y = get_super_parent(y);
        if(super_parent_x != super_parent_y){
            parent[super_parent_x] = super_parent_y;
            size[super_parent_y] += size[super_parent_x];
            size[super_parent_x] = 0;
        }
    }

} G ;

void Krushkals_minimum_spanning_tree(){
    int n , m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    G.init(n);
    for(int i = 0 ; i < m ; i++){
        int x , y , wt;
        cin>>x>>y>>wt;
        x--;
        y--;//for zero based in dexing
        edges[i] = {wt , x , y};
    }
    int ans = 0;
    for(auto it : edges){
        int wt = it[0];
        int x = it[1];
        int y = it[2];
        if(G.get_super_parent(x) != G.get_super_parent(y)){
            G.unite(x , y);
            ans += wt;
            cout<<x<<"-->"<<y<<" wt "<<wt<<endl;
        }
    }
    cout<<ans<<endl;
}


int main(){
    Krushkals_minimum_spanning_tree();
    return 0;
}
