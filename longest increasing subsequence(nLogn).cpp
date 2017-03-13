#include<bits/stdc++.h>
#define MAX 1000300
using namespace std;

int cnt[MAX],id,k;
int tailTable[MAX],A[MAX];

int CeilIndex(int l, int r, int key)
{
    while(r>l)
    {
        if(l+1==r){
            if(tailTable[l]>key)return l;
            return r;
        }
        int m=(r+l)/2;
        if(tailTable[m]>key)r=m;

        else l=m+1;
    }
    return r;
}

int lcs(int size)
{

    int len;

    //memset(tailTable,0,sizeof(tailTable));

    tailTable[0]= A[0];
    len=1;

    for(int i=1;i<size; i++)
    {

        if (A[i]<tailTable[0]){
             tailTable[0]=A[i];

        }

        else if(A[i]>tailTable[len-1]){
             tailTable[len++]=A[i];

        }

        else {
             int val=CeilIndex(0, len-1, A[i]);
             tailTable[val]=A[i];

        }


    }
    return len;
}

int main()
{
    int t,ct=0,n;


        cin>>n;
        for(int i=0;i<n;i++)cin>>A[i];
        for(int i=0;i<=n;i++){
            tailTable[i]=0;
        }
        cout<<lcs(n);



}
