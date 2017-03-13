//Finding Minimum vertex cover for a tree....
//It can be connected...or disconnected...

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100002
int dp[MAXN][5];
#define mod 10007
int par[MAXN];
vector<int>edges[MAXN];
int mat[MAXN][3];

int f(int u,int isGuard)
{
	if(edges[u].size()==0)return 1;
	if(dp[u][isGuard]!=-1) return dp[u][isGuard];
	int sum=0;
	for(int i=0;i<(int)edges[u].size();i++)	{
		int v=edges[u][i];
		if(v!=par[u]){
			par[v]=u;
			if(isGuard==0) sum+=f(v,1);
			else sum+=min(f(v,1),f(v,0));
		}
	}
	return dp[u][isGuard]=sum+isGuard;
}

int main()
{
    int t,ct=0;
    cin>>t;
    while(t--){

    memset(dp,-1,sizeof(dp));
    memset(par,0,sizeof(par));
	int n,u,v,m;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int ans=0;

	printf("%d\n",ans);
    }
}

