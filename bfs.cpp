#include<bits/stdc++.h>
using namespace std;
int t,st,n,m;
#define mx 1010
vector<int>g[mx];
int d[mx];
void bfs(int s)
{
    d[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(d[v]==-1){
            d[v]=d[u]+1;
            q.push(v);
            }
        }
    }
}

int main()
{
    int u,v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(d,-1,sizeof(d));
        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
       }
       cin>>st;
       bfs(st);
       for(int i=1;i<=n;i++){
          if(i!=st){
              if(d[i]==-1)printf("-1 ");
              else printf("%d ",d[i]*6);
          }
       }

    }
}
