#include<bits/stdc++.h>
using namespace std;
#define mx 200004

vector<int>g[mx];
vector<int>srt;
bool vis[mx];

void top(int u)
{
    vis[u]=true;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]==false){
            top(v);
        }
    }
    srt.push_back(u);
}

int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i]==false)top(i);
    }

    for(int i=n-1;i>=0;i--)printf("%d ",srt[i]);
}
