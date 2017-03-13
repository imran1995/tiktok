#include<bits/stdc++.h>
using namespace std;
#define eps pow(10,-9)
#define mx 104
#define pi pair<double,int>
#define pii pair<int,pi>
#define mp make_pair
#define INF 100000009
vector<int>g[mx];
int dist[mx];
vector<int>cost[mx];
#define ss second
#define ff first

int disra(int t)
{

    for(int i=0;i<mx;i++)dist[i]=INF;

    set<pi>q;
    q.insert(mp(0,0));

    dist[0]=0;

    while(!q.empty()){

        pi top=*q.begin();
        q.erase(top);

        int u=top.second;
        if(u==t)return dist[u];

        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            int val=dist[u]+cost[u][i];
            if(val<dist[v]){
                q.erase(mp(dist[v],v));
                dist[v]=val;
                    //par[v]=u;
                q.insert(mp(dist[v],v));

            }
        }


    }
    return dist[t];
}

int main()
{
    int m,u,v,t,ct=0,k,s,n;
    int w;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            g[i].clear();
            dist[i]=0;
            cost[i].clear();
        }
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(v);
            cost[u].push_back(w);
            g[v].push_back(u);
            cost[v].push_back(w);

        }

        int ans=disra(n-1);


        printf("Case %d: %d\n",++ct,ans);


    }
}
