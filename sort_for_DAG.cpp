//Single source sortest path for a DAG

#include<bits/stdc++.h>
using namespace std;
#define mx 200004

vector<int>g[mx],cost[mx],temp[mx];
vector<int>srt;
int dist[mx];
bool vis[mx];
void top(int u)                   //Function for topological sorting
{
    vis[u]=true;
    for(int i=0;i<g[u].size();i++){    //Using normal dfs
        int v=g[u][i];
        if(vis[v]==false){
            top(v);
        }
    }
    srt.push_back(u);              //only deference from dfs
}

int main()
{
    int n,m,x,y,s,t,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&w);
        g[x].push_back(y);
        temp[y].push_back(x);
        cost[y].push_back(w);
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i]==false)top(i);
    }

    cin>>s>>t;
    int idx,v;                 //taking source and  destination
    for(int i=0;i<n;i++){
        if(srt[i]==s){
            idx=i;
            break;
        }
    }
    for(int i=0;i<=n+3;i++){
        dist[i]=1000000009;
    }
    dist[s]=0;
    for(int i=idx;i>=0;i--){
        for(int j=0;j<temp[srt[i]].size();j++){
            v=temp[srt[i]][j];
            if(dist[v]+cost[srt[i]][j]<dist[srt[i]]){
                dist[srt[i]]=dist[v]+cost[srt[i]][j];
                //cout<<dist[srt[i]];
            }
        }
        if(srt[i]==t){
            break;
        }

    }
    if(dist[t]!=1000000009){
        printf("%d ",dist[t]);
    }
    else cout<<"-1";

}
