#include <bits/stdc++.h>
using namespace std;
#define mx 100010

int f[mx];

void preKMP(string pattern)
{

    int m = pattern.size(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])break;
            else k = f[k];
        }
        f[i] = k + 1;
    }
}
//check whether target string contains pattern

bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    preKMP(pattern);

    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)return 1;
        }
        else k=f[k];
    }
    return 0;
}



int main()
{

    string s;
    cin>>s;
    preKMP(s);
    for(int i=0;i<s.size();i++)cout<<f[i]<<" ";

}
