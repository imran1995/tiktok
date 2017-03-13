#include<bits/stdc++.h>
using namespace std;
#define MAX 100010


int a[MAX];
int main()
{
    int t,ct=0,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);

        int minima=a[0];
        int maxima=a[0];
        int minilen=1;
        int maxilen=1;

        for(int i=1;i<n;i++){
            int l=0;

            if(a[i]==maxima){
                maxilen++;
                l=1;
            }
            if(minima==a[i]){
                minilen++;
                l=1;
            }

            if(a[i]>minima){
                if(minilen+1>maxilen){
                    maxilen=minilen+1;
                    maxima=a[i];
                }
                else if(minilen+1==maxilen)maxima=max(a[i],maxima);
            }
            if(a[i]<maxima){
                if(maxilen+1>minilen){
                minilen=maxilen+1;
                minima=a[i];
                }
                else if(minilen==1+maxilen)minima=min(a[i],minima);
            }
        }

        cout<<max(maxilen,minilen)<<endl;

    }
}
