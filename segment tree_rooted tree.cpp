#include<bits/stdc++.h>
using namespace std;
#define MAX 100010

vector<int>g[MAX];
int s[MAX],f[MAX],h[MAX],st=1;

void visit(int u,int v)
{
    for(int i=0;i<g[u].size();i++){
        int x=g[u][i];
        if(x!=v){
            h[x]=h[u]+1;
            s[x]=st++;
            visit(x,u);
        }
    }
    f[u]=st++;
    return;
}

void dfs(int u)
{
    s[u]=st++;
    h[u]=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        h[v]=h[u]+1;
        s[v]=st++;
        visit(v,u);
    }
    f[u]=st++;
    return;
}

int main()
{
    int n,u,v;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for(int i=1;i<=n;i++)cout<<s[i]<<" "<<h[i]<<endl;

}
