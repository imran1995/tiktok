#include<bits/stdc++.h>
using namespace std;
#define mx 10000
vector<int>edge[mx];
char clr[mx];
int dis[mx],fin[mx],par[mx],tm=0,n;

void visit(int u)
{
    clr[u]='g';
    tm++;
    dis[u]=tm;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(clr[v]=='w'){
            par[v]=u;
            visit(v);
        }
    }
    clr[u]='b';
    tm++;
    fin[u]=tm;
    return;
}

void dfs(void)
{
    for(int i=0;i<mx;i++){
        clr[i]='w';
        par[i]=NULL;
    }
    //tm=0;
    for(int i=0;i<n;i++){
        if(clr[i]=='w')visit(i);
    }
    return;
}

int main()
{
    int m,i,j,u,v;
    cin>>n>>m;
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);

    }
    dfs();
    for(i=0;i<n;i++){
        printf("%d\n",par[i]);
    }
    return 0;
}
