#include<bits/stdc++.h>
using namespace std;
int k;
struct pot
{
    int rept,len;
}point,mx;
struct node
{
    int ct,rept;
    node *next[27+2];
    node()
    {
        ct=0;
        rept=0;
        for(k=0;k<26;k++){
            next[k]=NULL;
        }
    }
}*root;
//void del(node *cur)
/*{
    for(i=0;i<26;i++){
        if(cur->next[i])del(cur->next);
    }
    delete(cur);
}*/

void insert1(string str,int low,int len)
{
    int i;
    node *cur=root;
    for(i=0;i<len-low;i++){
        int id=str[i+low]-'a';
        if(cur->next[id]==NULL){

            cur->next[id]=new node();
        }
        cur=cur->next[id];
        cur->rept++;

        cur->ct=i+1;
        if(cur->rept>mx.rept){
            mx.rept=cur->rept;
            mx.len=cur->ct;
        }
    }
    return;
}
/*int search1(string str)
{
    int len=str.size(),i;
    node *cur=root;
    for(i=0;i<len;i++){
        int id=str[i]-'a';
        if(cur->next[id]==NULL)return false;
        cur=cur->next[id];
    }
    return cur->ct;
}*/
int main()
{
    int n,i,j;
    string s;
    cin>>s;
    n=s.size();
    mx.rept=0;
    for(i=0;i<n;i++){
        insert1(s,i,n);
    }
    cout<<mx.rept<<" "<<mx.len;
    return 0;
}
