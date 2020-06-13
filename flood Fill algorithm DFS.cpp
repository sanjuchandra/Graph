#include <iostream>
#include <cstring>
using namespace std;

int R , C;
int dx[] = {0 , 0 , -1 , 1};
int dy[] = {1 , -1 , 0 , 0};

void floodFill(char mat[][50] , int i , int j , char color_to_replace , char color_by_which_replace){
    if(i < 0 or j < 0 or i >= R or j >=C){
        return;
    }

    if(mat[i][j] != color_to_replace){
        return;
    }

    mat[i][j] = color_by_which_replace;
    for(int k = 0 ; k < 4 ; k++){
        floodFill(mat , i + dx[k] , j + dy[k] , color_to_replace , color_by_which_replace);
    }
    return;
}

int main(){
    cin>>R>>C;
    char mat[15][50];
    for(int  i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin>>mat[i][j];
        }
    }
    floodFill(mat , 8 , 13 , '.' , 'R');
    //print_figure(mat);
}
