//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

int Grid[100][100];
int Node,Edge;
bool visited[100];
bool color[100];
bool flag=false;
void Bipartite(int u,int clr){

    visited[u]=true;
    color[u]=clr;
    for(int  v=0;v<Node;v++){
        if( Grid[u][v]){
            if(!visited[v]){
                Bipartite(v,1-clr);
                //visited[v]=true;
                //color[v]=  !(color[u]);
                //if(!Bipartite(v)) return false;
            }
            else if(color[v]==color[u]) {
                    flag=false;break;
            }
         }
   }

   //return true;
}

int main() {
    int src;
    cin>>Node>>Edge;
    for(int i=0;i<Edge;i++){
        int x,y;
        cin>>x>>y;
        src=x;
        Grid[x][y]=1;
        Grid[y][x]=1;
    }
    flag=true;
    Bipartite(src,1);
    // for(int i=1;i<=Node;i++){
    //     for(int j=1;j<=Node;j++){
    //         cout<<Grid[i][j]<<" ";

    //     }
    //     cout<<endl;
    // }

    if(flag) cout<<"Bipartite"<<endl;
    else cout<<"Not ....."<<endl;


}
