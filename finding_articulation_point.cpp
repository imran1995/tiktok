#include<bits/stdc++.h>
using namespace std;
#define mx 10004

int num[mx],low[mx],par[mx],ver[mx];


void arti(int u)
{
    low[u]=cnt;
    num[u]=cnt++;
    for(int j=0;j<adj[u].size();j++){
        pi v=adj[u][j];
        if(num[v.first]==-1){
            par[v.first]=u;
            if(u==root)rt++;

            arrti(v.first);
            if(low[v.first]>=num[u])art[u]=true;

            if(low[v.first]>num[u])printf("%d %d is a bridge.\n",u,v.first);
        }
    }

    else if(v.first!=par[u])low[u]=min(low[u],num[v.first]);
}


int main()
{
    cnt=0;
    num.assign(v,-1);
    low.assign(v,0);

    par.assign(v,0);
    art.assign(v,0);

    for(int i=0;i<v;i++){
        if(num[i]==-1){
            root=i;
            rt=0;
            arti(i);
            art[root]=(rt>1);
        }
        }
    }

    printf("articulation points:\n");
    for(int i=0;i<v;i++){
        if(art[i])printf("Vertex %d\n",i);
    }
}
