#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
#define ll long long
vector<ll>g[MAX],cost[MAX];
ll par[MAX],level[MAX],dist[MAX];
ll n;
ll sp[MAX][32];



void dfs(ll u)//finding parent and level of every node
{
    for(int i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(par[v]==0){
            par[v]=u;
            level[v]=level[u]+1;
            dist[v]=dist[u]+cost[u][i];
            dfs(v);
        }
    }
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

      return par[p];
  }

int get(int p,int q,int k)
{
    int lc=lca(p,q),d;
    if(p==lc){
        d=level[q]-level[p]+1;
        k=d-k+1;
        swap(p,q);
    }
    else if(lc!=q){
        d=level[p]+level[q]-2*level[lc]+1;
        if(level[p]-level[lc]+1<k){
            swap(p,q);
            k=d-k+1;
        }
    }

    int lg;
    for(lg=1;1<<lg<=level[p];lg++);
    lg--;
    k--;

    for(int i=lg;i>=0;i--){
        if(1<<i<=k){
            p=sp[p][i];
            k-=1<<i;
        }
    }
    return p;

}

int main()
{
    int m,u,v,t,w,k;
    string s;
    cin>>t;
    while(t--){

        cin>>n;
        for(int i=0;i<=n;i++){
            g[i].clear();
            cost[i].clear();
            par[i]=0;
        }


        for(int i=1;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(v);
            cost[u].push_back(w);
            g[v].push_back(u);
            cost[v].push_back(w);
        }
        par[1]=1;
        level[1]=0;
        dist[1]=0;
        dfs(1);

        for(int i=1;i<=n;i++){//For finding sparse table
            sp[i][0]=par[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;(1<<j)<=n;j++){
                sp[i][j]=sp[sp[i][j-1]][j-1];/////////
            }
        }
        while(true){
            cin>>s;
            if(s=="DONE")break;
            else if(s=="DIST"){
                cin>>u>>v;
                int lc=lca(u,v);
                cout<<dist[u]+dist[v]-2*dist[lc]<<endl;
            }
            else{
                cin>>u>>v>>k;
                cout<<get(u,v,k)<<endl;
            }
        }

    }

}

