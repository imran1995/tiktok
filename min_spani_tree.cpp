#include<bits/stdc++.h>
using namespace std;
#define MAXN 405
#define eps pow(10,-9)
int s,s1;

struct edge
{
	int u,v,w;
	edge(){w=0;}
	bool operator <(edge other)const{
        if(fabs(w-other.w)>eps)return w<other.w;
};
vector<int>e;
int pr[MAXN],rel[MAXN];



int find(int r)
{
   return (pr[r]==r)?r:find(pr[r]);
}

void mst(int n)
{

	for(int i=0;i<=n;i++)pr[i]=i;
    sort(e.begin(),e.end());
	int count=0,x,y;
	s=0;
	for(int i=0;i<e.size();i++)
	{
		x=find(e[i].u);
		y=find(e[i].v);
		if(x!=y)
		{
			pr[x]=y;
			rel[e[i].u]=e[i].v;
			rel[e[i].v]=e[i].u;
			count++;
			s+=e[i].w;
			if(count==n-1) break;
		}
	}
	/*for(int i=0;i<=n;i++)pr[i]=i;

	int count1=0;
	s1=0;
	for(int i=e.size()-1;i>=0;i--)
	{
		u=find(e[i].u);
		v=find(e[i].v);
		if(u!=v)
		{
			pr[u]=v;
			count1++;
			s1+=e[i].w;
			if(count1==n-1) break;
		}
	}*/

}

int main(){
	int n,u,v;
	cin>>n;
	struct edge pot;
	for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            scanf("%d",&u);
            pot.u=i,pot.v=j,pot.w=u;
            e.push_back(pot);
        }
	}
	mst(n);
	for(int i=1;i<=n;i++){
        printf("%d ",rel[i]);
	}
	return 0;

}
