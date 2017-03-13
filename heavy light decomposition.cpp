#include<bits/stdc++.h>
using namespace std;
#define MAX 30005
vector<int>g[MAX];
int par[MAX],level[MAX],a[MAX],subsize[MAX],ptr=1,chain=1,chainhead[MAX],chainpos[MAX],indchain[MAX],chainbase[MAX],tree[MAX];
int n;
int sp[MAX][32],tt=1;


void build(int id,int s,int e)
{
    if(s>e)return;
    if(s==e){
        tree[id]=chainbase[s];
        return;
    }
    int mid=(s+e)/2;
    build(id*2,s,mid);
    build(id*2+1,mid+1,e);
    tree[id]=tree[id*2]+tree[id*2+1];
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
       //cout<<p<<"#"<<endl;
      return par[p];
  }

void up_tree(int id,int s,int e,int pos,int val)
{

    if(s>pos || e<pos)return;
    if(s==pos && e==pos){
        tree[id]=val;
        return;
    }
    int mid=(s+e)/2;
    up_tree(id*2,s,mid,pos,val);
    up_tree(id*2+1,mid+1,e,pos,val);
    tree[id]=tree[id*2]+tree[id*2+1];
}


int query_tree(int id,int s,int e,int i,int j)
{

    if(i>e || s>j)return 0;
    if(s>=i && e<=j)return tree[id];
    int mid=(s+e)/2;
    return query_tree(id*2,s,mid,i,j)+query_tree(id*2+1,mid+1,e,i,j);

}

int query_up(int u, int v) {
	if(u==v) return query_tree(1,1,ptr-1,chainpos[u],chainpos[u]);
	int uchain, vchain = indchain[v], ans =0;
	while(1){

		uchain = indchain[u];

		if(uchain == vchain) {

			ans+=query_tree(1, 1, ptr-1, chainpos[v], chainpos[u]);
			break;
		}
		ans+=query_tree(1, 1, ptr-1, chainpos[chainhead[uchain]],chainpos[u]);

		u = chainhead[uchain];

		u = sp[u][0];

	}
	return ans;
}


int query(int u,int v)
{
    int s=lca(u,v);
    return query_up(u,s)+query_up(v,s)-query_up(s,s);

}

void dfs(int u)
{
    subsize[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];

        if(par[v]==0){
            par[v]=u;

            level[v]=level[u]+1;
            dfs(v);
            subsize[u]+=subsize[v];
        }
    }
    return;
}


void hld(int cur)
{
    if(chainhead[chain]==-1){
        chainhead[chain]=cur;

    }
    indchain[cur]=chain;
    chainpos[cur]=ptr;
    chainbase[ptr++]=a[cur];


    int sc=30003,mx=-1;
    for(int i=0;i<g[cur].size();i++){
        int v=g[cur][i];
        if(par[cur]!=g[cur][i]){
            if(subsize[sc]<subsize[v]){
                sc=v;
            }
        }
    }

    if(sc!=30003){
        hld(sc);
    }
    for(int i=0;i<g[cur].size();i++){
        if(g[cur][i]!=sc && par[cur]!=g[cur][i]){
            chain++;
            hld(g[cur][i]);
        }
    }


}

int main()
{
    int m,u,v,t,ct=0;
    cin>>t;
    while(t--){
        cin>>n;
        ptr=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            par[i]=0;
            g[i].clear();
            chainhead[i]=-1;
        }

        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            u++;
            v++;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        par[1]=1;
        level[1]=0;
        dfs(1);


        hld(1);

        build(1,1,ptr-1);

        for(int i=1;i<=n;i++){//For finding sparse table
            sp[i][0]=par[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;(1<<j)<=n;j++){
                sp[i][j]=sp[sp[i][j-1]][j-1];/////////
            }
        }

        int q,f;

        cin>>q;
        printf("Case %d:\n",++ct);
        while(q--){
            //cin>>f>>u>>v;
            scanf("%d%d%d",&f,&u,&v);
            if(f==0)printf("%d\n",query(u+1,v+1));
            else up_tree(1,1,ptr-1,chainpos[u+1],v);
        }


    }
}
