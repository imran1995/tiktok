#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return(b!=0)?gcd(b,a%b):a;
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<f(n,m);
}
