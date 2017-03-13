#include<bits/stdc++.h>
using namespace std;
#define max_n 100004
int n;
int ra [max_n],tempra[max_n],sa[max_n],tempsa[max_n],c[max_n],phi[max_n],plcp[max_n],lcp[max_n];
char T[max_n];

void countingSort(int k)
{
    int i,sum,maxi=max(300,n);
    memset(c,0,sizeof(c));
    for(i=0;i<n;i++){
        c[i+k<n?ra[i+k]:0]++;
    }
    sum=0;
    for(i=0;i<maxi;i++){
        int t=c[i];
        c[i]=sum;
        sum+=t;
    }
    for(i=0;i<n;i++){
        tempsa[c[sa[i]+k<n?ra[sa[i]+k]:0]++]=sa[i];
    }
    for(i=0;i<n;i++){
        sa[i]=tempsa[i];
    }
}
void constructSa(void)
{
    int i,k,r;
    for(i=0;i<n;i++){
        ra[i]=T[i];
        sa[i]=i;
    }
    for(k=1;k<n;k<<=1)
    {
        countingSort(k);
        countingSort(0);
        tempra[sa[0]]=0;
        r=0;
        for(i=1;i<n;i++){
            tempra[sa[i]]=(ra[sa[i]]==ra[sa[i-1]]&&ra[sa[i]+k]==ra[sa[i-1]+k])?r:++r;
        }
        for(i=0;i<n;i++){
            ra[i]=tempra[i];
        }
        if(ra[sa[n-1]]==n-1)break;
    }
}


void lcpp()
{
    int i,l;
    phi[sa[0]]=-1;
    for(i=1;i<n;i++){
        phi[sa[i]]=sa[i-1];

    }
    for(i=l=0;i<n;i++){
        if(phi[i]==-1){
            plcp[i]=0;
            continue;
        }
        while(T[i+l]==T[phi[i]+l])l++;
        plcp[i]=l;
        l=max(l-1,0);
    }
    for(int i=0;i<n;i++)lcp[i]=plcp[sa[i]];
}

int main()
{
    int t;
    cin>>t;
    long long k;
    while(t--){
        n=(int)strlen(gets(T));
        T[n++]='$';
        constructSa();
        lcpp();

        for(int i=0;i<n;i++)cout<<plcp[i]<<" ";

    }
    return 0;
}
