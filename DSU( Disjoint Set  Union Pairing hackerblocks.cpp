#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;


struct pairing{
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

} Graph ;

int main(){
    int n, m;
    cin>>n>>m;
    Graph.init(n);
    while(m--){
        int x ,y;
        cin>>x>>y;
        Graph.unite(x , y);
    }

    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        int super_parent_i = Graph.get_super_parent(i);
        ans += (n - Graph.size[super_parent_i]);
    }
    cout<<ans/2<<endl;
    return 0;
}
