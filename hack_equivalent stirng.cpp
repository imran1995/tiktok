#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int po[2002][2002],nd[2001],ncr[2001][2001];




int main()
{
    int t,ct=0;
    ll val;
    cin>>t;
    for(int i=1;i<2001;i++){
       po[i][1]=i;
       po[i][0]=1;

       ncr[i][0]=1;
       ncr[i][i]=1;
       ncr[i][1]=i;
    }
    po[0][0]=1;
    for(int i=1;i<2001;i++){
        for(int j=1;j<2001;j++){
            val=(po[i][j-1]*i)%mod;
            po[i][j]=val;
        }
    }
    ncr[0][0]=1;
    for(int i=2;i<=2000;i++){
        for(int j=2;j<i;j++){
            ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
        }
    }

    nd[0]=1;
    for(int i=1;i<=2000;i++){
        val=(nd[i-1]*2)%mod;
        nd[i]=val;
    }


    int id,n,m;
    while(t--){
        cin>>m>>n;
        if(n%2)id=n/2;
        else id=n/2+1;
        ll ans=0;
        //cout<<id<<endl;

        for(int i=n;i>=1;i--){
            if(n-i<m)ans=(ncr[n][i]+ans)%mod;
            //cout<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
}
