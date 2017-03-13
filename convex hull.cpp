/*#include<bits/stdc++.h>
using namespace std;
struct point
{
    float x,y;
}pivot;
struct vec{
    float x,y;
};

vec tovec(point a,point b)//Turn two points into a vector
{
    struct vec v;
    v.x=b.x-a.x;
    v.y=b.y-a.y;
    return v;
}

float cross(vec a,vec b)//To find cross product of two vectors
{
    return (a.x*b.y-a.y*b.x);
}


float dot(vec a,vec b)//To find dot product of two vectors
{
    return a.x*b.x+a.y*b.y;
}


bool ccw(point p,point q,point r)//rotation of point r with respect to point p and q
{
    return cross(tovec(p,q),tovec(p,r))>0;
}


bool collinear(point p,point q,point r)//
{
    return cross(tovec(p,q),tovec(p,r))>0;
}
*/


#include<bits/stdc++.h>

using namespace std;

struct Point
{
        long x;
        long y;
        Point(){}
        Point(int a,int b){x=a;y=b;}
};

Point p0;
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return square of distance between p1 and p2
long long  dist(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *) vp1;
    Point *p2 = (Point *) vp2;

    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

// Prints convex hull of a set of n points.
double convexHull(Point points[], int n)
{
    // Find the bottommost point
    long long  ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        long long y = points[i].y;

        // Pick the bottom-most or chose the left most point in case of tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    // Sort n-1 points with respect to the first point.  A point p1 comes
    // before p2 in sorted ouput if p2 has larger polar angle (in
    // counterclockwise direction) than p1
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // Create an empty stack and push first three points to it.
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < n; i++)
    {
        // Keep removing top while the angle formed by points next-to-top,
        // top, and points[i] makes a non-left turn
        while (orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // Now stack has the output points, print contents of stack
    Point ff,ll,cur;
    ff=S.top();
    cur=ff;
    double d=0;
    while (!S.empty())
    {
        Point p = S.top();
        //cout << "(" << p.x << ", " << p.y << ")" << endl;
        d+=pow(dist(cur,p),0.5);
        cur=p;
        S.pop();
    }
    return d+pow(dist(cur,ff),0.5);
}

int main()
{
    int t,n;
    cin>>t;
    Point pt[1000001];
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)scanf("%lld%lld",&pt[i].x,&pt[i].y);
        //cout<<convexHull(pt, n)<<endl;
        printf("%0.6lf\n",convexHull(pt, n));
    }
    return 0;
}
