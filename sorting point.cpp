#include<bits/stdc++.h>
using namespace std;
#define eps pow(10,-9)
struct point{
    int x,y;
    point(){x=0;
    y=0;}
    bool operator < (point other)const{
        if(fabs(x-other.x)>eps)return x>other.x;
        //if(fabs(x-other.x)<=eps)return y<other.y;

    }
};

int main()
{
    vector<point>p;
    struct point po;
    struct point p1,p2;
    //p1.x=4,p1.y=3,p2.x=5,p2.y=5;
    //printf("%d",p2>p1);
    int n;
    int x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        po.x=x;
        po.y=y;
        p.push_back(po);
    }
    sort(p.begin(),p.end());
    for(int i=0;i<n;i++){
        printf(" %d %d\n",p[i].x,p[i].y);
    }
    return 0;
}
