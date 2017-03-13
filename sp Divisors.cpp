#include<bits/stdc++.h>
using namespace std;
#define MAX 50004
#define mod 1000000007
bool is_prime[MAX];
vector<int>p;
long long int a[50002];
void f(int n)
{
    is_prime[1]=false;
    is_prime[2]=true;
    for(int i=4;i<=n;i+=2){
        is_prime[i]=0;
    }
    int k;
    for(int i=3;i<=(int)sqrt(n);i+=2){
       k=i;
        if(is_prime[i]!=false){
            //is_prime[i]=true;
            for(int j=i+i;j<=n;j+=k)is_prime[j]=false;
        }
    }
}

int main()
{
    int n,t,ct=0,l;

    memset(is_prime,true,sizeof(is_prime));
    f(50000);
    for(int i=1;i<=50000;i++){
        if(is_prime[i]!=false)p.push_back(i);
    }
    long long int len=p.size(),val,tem;
    a[1]=1;
    a[0]=0;
    int cnt[50001];
    memset(cnt,0,sizeof(cnt));

    for(int i=2;i<=500;i++){
        l=i;
        tem=1,val=0;
        int k=0;
        while(k<len && l>1){
            if(l%p[k]==0){
                 val++;
                 l/=p[k];

            }
            else{

                cnt[p[k]]+=val;

                val=0;
                k++;
            }

        }
        val=i;
        long long int tt=1;
        int j=0;
        while(p[j]<=val){//(int j=0;j<len;j++){

            tt=tt*(cnt[j]+1);
            tt=tt%mod;
            j++;
        }
        a[i]=tt;

    }


    cin>>t;
    while(t--){
        cin>>n;
        cout<<a[n]<<endl;
    }


}
