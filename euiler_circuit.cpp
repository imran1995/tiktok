#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
#define pi pair<int,int>
#define mp make_pair
int vis[MAX];
vector<pi>g[MAX];
list<int>cir;

void tor(list<int>::iterator j,int u)
{
    for(int i=0;i<g[u].size();i++){
        pi v=g[u][i];
        if(v.second==1){
            v.second=0;
            for(int k=0;k<g[v.first].size();k++){
                pi uu=g[v.first][k];
                if(uu.first==u && uu.second==1){
                    uu.second=0;
                    break;
                }
            }
            tor(cir.insert(j,u),v.first);
        }
    }
}

int main()
{
    int n,i,j,u,v;
    while(scanf("&d&d&d",&u,&v,&w)!=EOF){
        memset(vis,0,sizeof(vis));
        cin>>u>>v;
        g[u].push_back(mp(v,1));
        g[v].push_back(mp(u,1));
        vis[v]++;
        vis[u]++;


    int flag=0;
    for(i=0;i<MAX;i++){
        if(vis[i]%2==1){
            flag=1;
            break;
        }
    }
    if(flag==0){
        tor(cir.begin(),1);
        for( i=0;i<cir.size();i++){
            printf("%d \n",i);
        }
    }
    }

}

