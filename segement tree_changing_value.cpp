#include<bits/stdc++.h>
#define mx 100001
using namespace std;
int gcd(int a,int b)
{
    return(b!=0)?gcd(b,a%b):a;
}

int tree[mx*3],car[mx*3],cnt[mx*3];

int arr[mx];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=0;
        car[node]=-1;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];
    car[node]=0;
}

void update(int node,int b,int e,int i,int j,int val)
{
    if(j<b || i>e)return;
    if(i<=b && j>=e){
        tree[node]=(e-b+1)*val;
        car[node]=val;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    if(car[node]!=-1){car[left]=car[node];
    car[right]=car[node];
    tree[left]=(mid-b+1)*car[node];
    tree[right]=(e-mid)*car[node];
    car[node]=-1;
    }

    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node]=tree[left]+tree[right];
    return;
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)return 0;
    if(i<=b && j>=e)return tree[node];
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;

    if(car[node]!=-1){car[left]=car[node];
    car[right]=car[node];
    tree[left]=(mid-b+1)*car[node];
    tree[right]=(e-mid)*car[node];
    car[node]=-1;
    }

    int s=query(left,b,mid,i,j);
    int t=query(right,mid+1,e,i,j);
    return s+t;
}


int main()
{
    int t,ct=0,n,q,val,u,v,f;
    cin>>t;
    while(t--){
        printf("Case %d:\n",++ct);
        memset(car,-1,sizeof(car));
        cin>>n>>q;

        init(1,1,n);

        for(int i=0;i<q;i++){


            scanf("%d%d%d",&f,&u,&v);
            if(f==1){
                scanf("%d",&val);
                update(1,1,n,u+1,v+1,val);
            }
            else {
                val=query(1,1,n,u+1,v+1);

                //cout<<val<<endl;
                int ans=gcd(val,v-u+1);
                if(val%(v-u+1)==0)printf("%d\n",val/ans);//<<endl;
                else printf("%d/%d\n",val/ans,(v-u+1)/ans);//<<endl;
            }
        }
    }
}
