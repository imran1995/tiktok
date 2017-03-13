#include<bits/stdc++.h>
using namespace std;
int u,v;
#define mx 1000
int dist[mx][mx];
vector<int>g[mx];
vector<int>cost[mx];
int main()
{
    int i,j,k,v,x,y,e,w;
    cin>>v>>e;
    memset(dist,100000000,sizeof(dist));
    for(i=0;i<e;i++){
        cin>>x>>y>>w;
        g[x].push_back(y);
        g[y].push_back(x);
        //dist[x][y]=w;
        //dist[y][x]=w;
        cost[x].push_back(w);
        cost[y].push_back(w);
    }
    for(i=0;i<v;i++){
        for(k=0;k<v;k++){
            for(j=0;j<v;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    printf("%d",dist[2][3]);
    return 0;
}
