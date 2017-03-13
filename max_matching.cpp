#include<bits/stdc++.h>
using namespace std;
#define max_v 10000
#define inf 1000000000
int res[max_v][max_v],mf,f,s,t;
vector<int>p;
void augment(int v,int minedge){
    if(v==s){
        f=minedge;
        return;
    }
    if(p[v]!=-1){
        augment(p[v],min(minedge,res[p[v]][v]));
        res[p[v]][v]-=f;
        res[v][p[v]]+=f;
    }
}

int main()
{
    memset(res,0,sizeof(res));
    int mf=0,u,v,w,n,ct=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&u,&v);
        res[u+1][v+1]=1;
        res[1][u+1]=1;
        res[v+1][max_v-1]=1;
    }
    s=1,t=max_v-1;
    //cin>>s>>t;
    while(1){
        f=0;
        queue<int>q;
        q.push(s);
        vector<int>dist(max_v,inf);
        dist[s]=0;
        p.assign(max_v,-1);
        while(!q.empty()){
            u=q.front();
            q.pop();
            if(u==t)break;
            for(v=0;v<max_v;v++){
                if(res[u][v]>0 && dist[v]==inf){
                    dist[v]=dist[u]+1;
                    q.push(v);
                    p[v]=u;
                }
            }
        }
        augment(t,inf);
        if(f==0)break;
        mf+=f;
        ct++;
    }
    cout<<mf;
}

