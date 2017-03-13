#include<bits/stdc++.h>
using namespace std;
#define MAX 5000004
bool is_prime[MAX];

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
    int n;
    cin>>n;
    memset(is_prime,true,sizeof(is_prime));
    f(n);
    for(int i=1;i<=n;i++){
        if(is_prime[i]!=false)printf("%d ",i);
    }
}
