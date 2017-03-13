#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
vector<int>g[MAX];
int par[MAX],level[MAX],d[MAX],f[MAX],dist[MAX],a[MAX];
int n;
int sp[MAX][32],tt=1;

void dfs(int u)//finding parent and level of every node
{
    d[u]=tt++;

    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];

        if(par[v]==0){
            par[v]=u;
            dist[v]=dist[u]^a[v];
            level[v]=level[u]+1;
            dfs(v);
        }
    }
    f[u]=tt++;
    return;
}

int lca(int p, int q)
  {
      int tmp,log,i;

      if(level[p]<level[q]){
          tmp=q,q=p,p=tmp;
      }

      log=1;
      while(1) {
        int next=log+1;
        if((1<<next)>level[p])break;
        log++;

      }

      for(i=log;i>=0;i--){
          if(level[p]-(1<<i)>=level[q]){

              p=sp[p][i];
          }
      }

      if(p==q)return p;
       // cout<<p;
      for (i=log;i>=0;i--){
          if(sp[p][i]!=0&&sp[p][i]!=sp[q][i]){
            p=sp[p][i],q=sp[q][i];
          }
      }
       cout<<p<<"#"<<endl;
      return par[p];
  }
int main()
{
    int m,u,v,t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=0;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        par[1]=1;
        dist[1]=a[1];
        dfs(1);

        for(int i=1;i<=n;i++){//For finding sparse table
            sp[i][0]=par[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;(1<<j)<=n;j++){
                sp[i][j]=sp[sp[i][j-1]][j-1];/////////
            }
        }


    }
}
