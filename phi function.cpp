#include<bits/stdc++.h>
using namespace std;
#define MAX 5000004
bool is_prime[MAX];
vector<int>pr;
void f(int n)
{
    memset(is_prime,true,sizeof(is_prime));
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
    for(int i=2;i<=n;i++){
        if(is_prime[i]!=false)pr.push_back(i);
    }
}

int main()
{
    int n,a;
    cin>>n;
    f(n);
    cin>>a;
    int len=pr.size();
    cout<<len;
    int val=sqrt(a);

    /*int score[5000000];
    score[0]=1,score[1]=0;
    for(int j=2;j<=5000000;j++){
        int ans=j,div=1,i=0;

        while(pr[i]<=val){
            if(j%pr[i]==0){
                ans*=(pr[i]-1);
                div*=pr[i];
            }
            i++;
        }
    }
    cout<<score[a];*/
    return main();

}

