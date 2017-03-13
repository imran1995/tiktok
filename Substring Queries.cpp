#include<bits/stdc++.h>
using namespace std;
string s,p;
int cnt[100],cn[100003][80];


long long bin(int l,int h,int id)
{
    if(l==h)return l;
    int mid=(l+h)/2;

    for(int i=0;i<80;i++){
        if(cn[mid][i]-cn[id-1][i]<cnt[i])return bin(l+1,h,id);
    }
    return bin(l,mid,id);

}

int main()
{
    int t,ct=0,q;
    cin>>t;
    while(t--){
        cin>>s;
        cin>>q;
        s="0"+s;
        int len=s.size();
        memset(cn,0,sizeof(cn));
        cn[0][s[0]-48]++;
        for(int i=1;i<len;i++){
            for(int j=0;j<80;j++){
                if(j==s[i]-48)cn[i][j]=cn[i-1][j]+1;
                else cn[i][j]=cn[i-1][j];
            }
        }
        long long ans=0;
        for(int j=0;j<q;j++){
            cin>>p;
            ans=0;
            memset(cnt,0,sizeof(cnt));
            for(int i=0;i<p.size();i++)cnt[p[i]-48]++;

            for(int i=1;i<len;i++)ans+=len-bin(i,len,i);

            printf("%lld\n",ans);
        }
    }
}
