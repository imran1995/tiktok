
//Finding longest palindrome without deleting  character

#include<bits/stdc++.h>
using namespace std;
string s;
int siz;
int dp[10000][10000];
int f(int i,int j,int carry)
{
    if(i==j)return 1;
    if(i+1==j){
        if(s[i]==s[j])return 2;
        else return 1-carry;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    if(s[i]==s[j]){
            carry+=2;
            ans=2+f(i+1,j-1,carry);
            ans=max(ans,f(i,j-1,0));
            ans=max(ans,f(i+1,j,0));
    }
    else{
        ans=max(f(i+1,j,0),f(i,j-1,0))-carry;
    }
    return dp[i][j]=ans;
}

int main()
{
    cin>>s;
    siz=s.size();
    memset(dp,-1,sizeof(dp));
    cout<<f(0,s.size()-1,0);

    return 0;
}
