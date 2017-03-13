#include<bits/stdc++.h>
using namespace std;

struct node{
	int l;
	int r;
	int i;
	node(){}
	node(int a,int b,int c){l=a;r=b;i=c;}
};

int ans;
struct node p[50005];
int a[100007];
int mod;
int cnt[100007];
int ff[50007],mx=0;

bool cmp(node x, node y)
{
	if(x.l/mod==y.l/mod) {
		return x.r < y.r;
	}

	return x.l/mod<y.l/mod;

}

void up(int pos)
{

    cnt[a[pos]]++;
    if(cnt[a[pos]]==1)ans++;
    return;
}

void rem(int pos)
{
    cnt[a[pos]]--;
    if(cnt[a[pos]]==0)ans--;
    return;
}


int main()
{
    int t,ct=0,n,q,curl,curr,u,v,l,r;
    cin>>t;

    while(t--){
        memset(cnt,0,sizeof(cnt));

        //cin>>n>>q;
        scanf("%d %d",&n,&q);
        mod=sqrt(n);

        ans=0,curl=0,curr=-1;

        for(int i=0;i<n;i++)cin>>a[i];

        for(int i=0;i<q;i++){
            //cin>>u>>v;
            scanf("%d",&u);
            scanf("%d",&v);

           // pt.l=u,pt.r=v,pt.i=i;
            p[i].l=u-1;
            p[i].r=v-1;
            p[i].i=i;
        }

        sort(p,p+q,cmp);

        printf("Case %d:\n",++ct);

        for(int i=0;i<q;i++){

            mx=0;
            int x = p[i].l;
			int y = p[i].r;

			while(curl<x) {
				rem(curl);
				curl++;
			}


			while(curl>x) {
				curl--;
				up(curl);

			}

			while(curr<y) {
				curr++;
				up(curr);

			}

			while(curr>y) {
				rem(curr);
				curr--;
			}

			ff[p[i].i]=ans;
			cout<<curl<<" # "<<curr<<endl;

        }
        for(int i=0;i<q;i++){
            cout<<ff[i]<<endl;
        }

        for(int i=0;i<q;i++)cout<<p[i].l<<" "<<p[i].r<<" "<<p[i].i<<endl;

    }
}
