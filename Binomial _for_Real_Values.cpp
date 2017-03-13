#include<bits/stdc++.h>
using namespace std;

float f(float n,int k)
{
    if(k==0)return 1;
    else return n*f(n-1,k-1);

}

int main()
{
    int k;
    float n;
    cin>>n>>k;
    cout<<f(n,k)<<endl;
    float val=1;
    for(int i=0;i<k;i++){
        val*=(n-i);
    }
    cout<<val;
}
