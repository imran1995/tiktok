#include<bits/stdc++.h>
using namespace std;
#define MAX 300000
int par[MAX];
int find(int r)
{
    if(par[r]==r)return r;
    return find(par[r]);
}
void union(int a,int b)
{
    int x=find(a),y=find(b);
    if(x==y)return;
    else par[y]=x;
    return;
}
