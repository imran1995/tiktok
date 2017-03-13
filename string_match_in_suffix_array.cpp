#include<bits/stdc++.h>
using namespace std;
#define max_n 100004
#define  pi pair<int,int>
int n,m;
int ra [max_n],tempra[max_n],sa[max_n],tempsa[max_n],c[max_n],phi[max_n],plcp[max_n],lcp[max_n];
char T[max_n],P[max_n];


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


pi strMatch()                             //Function for finding matching string
{
    int l=0,h=n-1,mid=l;
    //P[m++]='$';
    while(l<h){                              //For finding lower occurrence  of string P;
        mid=(l+h)/2;
        int res=strncmp(T+sa[mid],P,m);
        if(res>=0)h=mid;
        else l=mid+1;

    }
    if(strncmp(T+sa[l],P,m)!=0)return pi(-1,-1);
    pi ans;

    ans.first=l;
    l=0,h=n-1,mid=l;

    while(l<h){                         //For finding higher occurrence of string P;
        mid=(l+h)/2;
        int res=strncmp(T+sa[mid],P,m);
        if(res>0)h=mid;
        else l=mid+1;
    }

    if(strncmp(T+sa[h],P,m)!=0)h--;
    ans.second=h;
    return ans;
}


int CmLcp(int s)                             //Finding longest common prefix
{
    int i,l=0;
    phi[sa[0]]=-1;
    for(i=1;i<n;i++){
        phi[sa[i]]=sa[i-1];
        //cout<<phi[sa[i]]<<" ";
    }

    for(i=0;i<n;i++){
        //cout<<l<<endl;
        if(phi[i]==-1){
            plcp[i]=0;
            //cout<<l<<endl;
            continue;

        }
        while(T[i+l]==T[phi[i]+l])l++;
        //cout<<l<<endl;
        plcp[i]=l;
        s=max(s,l);
        l=max(0,l-1);
    }
    for(i=0;i<n;i++)lcp[i]=plcp[sa[i]];

    return s;
}


int main()
{
    n=(int)strlen(gets(T));
    T[n++]='$';
    constructSa();
    for(int i=0;i<n;i++)printf("%2d\t%s\n",sa[i],T+sa[i]);



    while(m=(int)strlen(gets(P))){                  //Part of string matching
        pi pos=strMatch();
        //cout<<pos.first<<" "<<pos.second<<endl;
        //cout<<T<<" "<<P<<endl;
        if(pos.first!=-1&& pos.second!=-1){
            printf("%s is found in the range of SA[%d %d] of %s\n",P,pos.first,pos.second,T);
            printf("They ara:\n");
            for(int i=pos.first;i<=pos.second;i++){
                printf(" %s\n",T+sa[i]);
            }
        }
        else printf("%s is not found\n",P);
    }

    //cout<<CmLcp(0)<<endl;


}

