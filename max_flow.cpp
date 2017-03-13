#include<bits/stdc++.h>
using namespace std;
#define eps pow(10,-10)
#define max_v 54
#define inf 1000000000
int res[max_v][max_v],mf,f,s,t,mat[55][55];
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
    memset(mat,0,sizeof(mat));
    int mf=0,u,v,w,n,ct=0,m,x;
    cin>>n>>m>>x;


    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        res[u][v]=w;
    }
    s=1,t=n;
        while(1){
            f=0;
            queue<int>q;
            q.push(s);
            vector<int>dist(max_v,inf);
            dist[s]=0;
            p.assign(n+1,-1);
            while(!q.empty()){
                u=q.front();
                q.pop();
                if(u==t)break;
                for(v=1;v<=n;v++){
                    if(res[u][v]>0 && dist[v]==inf){
                        dist[v]=dist[u]+1;;
                        q.push(v);
                        p[v]=u;
                    }
                }
            }
            augment(t,inf);
            if(f==0)break;
            mf+=f;

        }

}
