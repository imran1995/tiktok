#include<bits/stdc++.h>
using namespace std;
#define mx 10010
#define ll long long
#define ff first
#define ss second
#define pi pair<int,int>
#define mp make_pair
#define MAXE 10000
#define MAXN 100
int par[1004],d[MAXN],cost[MAXE];
pair<int,pi> e[MAXN];
vector<int>g[MAXN],vec;

int main() {

    int n,m,u,v,w,s;
    int t,ct=0;

    cin>>n>>m;
    cin>>s;

    for(int i=1;i<=n;i++) d[i]=1000000000;
    d[s]=0;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        e[i]=mp(w,mp(u,v));
    }
    int neg_cycle=false;

    for(int k=1;k<=n;k++)
    {
        bool up=false;
        for(int i=1;i<=m;i++)
        {
            int u=e[i].ss.ff,v=e[i].ss.ss;
            if(d[u]+e[i].ff<d[v])
            {
                up=true;
                if(k==n)neg_cycle=true;
                d[v]=d[u]+e[i].ff;
                par[v]=u;
            }
        }
        if(up==false)break;
    }

    if(neg_cycle==true)
    {
        cout<<"Negative Cycle Detected"<<endl;
    }
    else{
        //cout<<"Negative Cycle Not Detected"<<endl;
        int q;
        cin>>q;
        for(int i=1;i<=q;i++){
            cin>>u;
            cout<<d[u]<<" ";
        }
    }
    return 0;
}
