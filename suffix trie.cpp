#include<bits/stdc++.h>
using namespace std;
int k,t;
struct node
{
    bool em;
    node *next[27];
    node()
    {
        for(k=0;k<26;k++){
            next[k]=NULL;
        }
        em=false;
    }
}*root;
/*void del(node *cur)
{
    for(int i=0;i<26;i++){
        if(cur->next[i])del(cur->next);
    }
    delete(cur);
}*/

void insert1(string str)
{
    int len=str.size(),i;
    node *cur=root;
    for(i=0;i<len;i++){
       int id=str[i]-'a';
       cout<<id;
       if(cur->next[id]==NULL){//inside this , doing anything is not acceptable.But why?????
          t=6;
           //printf("dsd ");
           // cur->next[id]=new node();
        }
        //cur=cur->next[id];
    }
    //cur->em=true;
}
bool search1(string str)
{
    int len=str.size(),i;
    node *cur=root;
    for(i=0;i<len;i++){
        int id=str[i]-'a';
        if(cur->next[id]==NULL)return false;
        cur=cur->next[id];
    }
    return true;
}
int main()
{
    string s,p;
    cin>>s;
    insert1(s);
    if(t==6)cout<<t;
    //cout<<search1(p);
    return 0;
}
