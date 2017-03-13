#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        while(n>1){
            n/=2;
            ans++;
        }
        cout<<ans<<endl;
    }
}
