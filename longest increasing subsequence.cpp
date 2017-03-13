#include<bits/stdc++.h>
using namespace std;
#define MAX 500010
int a[MAX],dp[MAX];


int ceil(int l,int r,int val)
{
    while(r-l>1){
        int m=l+(r-l)/2;
        if(a[m]>=val)r=m;
        else l=m;
    }
    return r;
}

int lcs(int s)
{
    memset(dp,0,sizeof(dp));
    dp[0]=a[0];
    int len=1;
    for(int i=1;i<s;i++){
        if(dp[0]>a[i])dp[0]=a[i];
        else if(a[i]>dp[len-1])dp[len++]=a[i];
        else dp[ceil(-1,len-1,a[i])]=a[i];
    }
    return len ;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    cout<<lcs(n);
    return main();
}
