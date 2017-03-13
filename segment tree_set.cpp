#include<bits/stdc++.h>
using namespace std;
#define MAX 10010

multiset<int> tree[MAX];

void add(int id,int l,int r,int i,int k)
{
    tree[id].insert(k);
    if(r==l)return;
    int mid=(l+r)/2;
    if(mid>i)add(id*2,l,mid,i,k);
    else add(id*2+1,mid+1,r,i,k);
    return;
}

int ask(int id,int l,int r,int i,int j,int k)
{
    if(i>r || j<l)return 0;
    if(i<=l && j>=r)return tree[id].count(k);
    int mid=(l+r)/2;
    return ask(id*2,l,mid,i,j,k)+ask(id*2+1,mid+1,r,i,j,k);
}




int main()
{
    int n,u,v,k;
    char ch;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ch;
        if(ch=='A'){
            cin>>u>>v;

            add(1,1,n+1,u,v);

        }
        else {
            cin>>u>>v>>k;

            printf("The ans is %d\n",ask(1,1,n+1,u,v,k));
        }
    }
    cout<<tree[1].count(2)<<endl;


}


