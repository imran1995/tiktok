#include<bits/stdc++.h>
using namespace std;
vector<int>grp[100];
int color[100],vis[1000];
int main()
{
    queue<int>q;
    q.push(1);
    color[1]=1;
    vis[1]=1;
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        grp[x].push_back(y);
        grp[y].push_back(x);
    }
    memset(color,-1,sizeof(color));
    memset(vis,-1,sizeof(vis));
    bool isbipt=true;
    while(!q.empty() & isbipt==true){
        int u=q.front();
        q.pop();
        for(int i=0;i<grp[u].size();i++){
            int v=grp[u][i];
            if(color[v]==-1){
                color[v]=1-color[u];
                vis[v]=1;
                q.push(v);
            }
            else{
                if(vis[v]==1 && vis[u]==1)
                    isbipt=false;
                    break;
            }
        }
    }
    if(isbipt==true)printf("The graph is Bipartite.");
    else printf("The graph is not Bipartite.");
    return 0;
}
