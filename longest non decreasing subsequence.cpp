#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int ara[1000],n;
int par[1000],idx=0;

int main()
{
    int i,j;
    memset(dp,1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
        dp[i]=1;
    }
    int mx=0;
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(ara[j]<ara[i]){
                if(dp[j]+1>=dp[i]){//It will be >= if asked for last but maximum subs
                    dp[i]=dp[j]+1;
                    par[i]=j;
                }
            }
        }
        if(mx<=dp[i]){//here also <=
            mx=dp[i];
            idx=i;
        }
    }

    printf("%d \n",mx);
    int cnt=0;
    i=idx;
    vector<int>v;
    while(cnt<mx){
        v.push_back(ara[i]);
        i=par[i];
        cnt++;
    }
    for(i=mx-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
}
