#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int dp[MAX][MAX],a[MAX],num[MAX];

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i][1]=1;
    }

    for(int p=2;p<=n;p++){
        memset(num,0,sizeof(num));

        for(int i=2;i<=n;i++){
            num[a[i-1]]+=dp[i-1][p-1];
            for(int j=1;j<=a[i]-1;j++)dp[i][p]+=num[j];
        }
    }
    cout<<dp[n][n-k]<<endl;
    return main();

}
