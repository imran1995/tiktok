#include<bits/stdc++.h>
using namespace std;
#define MAX 50010

int n,ara[MAX],tree[MAX];

void update(int idx,int val)
{
    while(idx<=n){
        tree[idx]+=val;
        idx+=idx&(-idx);
    }
    return;
}


void update1(int a,int b,int val)
{
    update(a,val);
    update(b+1,-val);
}

int getsum(int idx)
{
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx&(-idx);
    }
    return sum;
}


void built()
{
    for(int i=0;i<=n;i++)tree[i]=0;

    for(int i=1;i<=n;i++)update(i,ara[i]);
    return;
}





int main()
{
    int m,s,id,val,a,b;

    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&ara[i]);
    built();
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>s;
        if(s==0){
            cin>>a>>b>>val;
            update(a,b,val);
        }
        else{
            cin>>id;
            cout<<getsum(id)-getsum(id-1)<<endl;
        }
    }
}


