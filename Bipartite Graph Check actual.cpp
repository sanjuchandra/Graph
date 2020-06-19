#include <iostream>
#include <vector>
using namespace std;

const int N = 100000;
vector<int> gr[N];
bool odd_cycle = false;
int visited_and_color[N] = {0};

void dfs_bipartite(int cur , int par , int col){
    visited_and_color[cur] = col;

    for(auto child : gr[cur]){
        if(!visited_and_color[child]){
            dfs_bipartite(child , cur , 3 - col); // 3 - col = (col + 3)%2
        }
        /*else if(child == par){
            continue;
        }*/
        else if(child != par and col == visited_and_color[child]){
            odd_cycle = true;
            //break;
        }
    }
    return;
}

int main(){
    int n , m;
    cin>>n>>m;
    while(m--){
        int x , y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    
    dfs_bipartite(1 , 0 , 1);
    if(odd_cycle){
        cout<<"Not Bipartite Graph"<<endl;
    }
    else{
        cout<<"Bipartite Graph"<<endl;
    }
    return 0;
}
