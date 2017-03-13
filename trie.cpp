#include<bits/stdc++.h>
using namespace std;
struct node
{
    bool em;
    int i,ct=0;
    node *next[27+1];
    node()
    {
        em=false;
        for(i=0;i<26;i++){
            next[i]=NULL;
        }
    }
}*root;
void del(node *cur)
/*{
    for(i=0;i<26;i++){
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
        if(cur->next[id]==NULL){
            cur->next[id]=new node();
        }
        cur=cur->next[id];
        cur->ct++;
    }
    cur->em=true;
}
int search1(string str)
{
    int len=str.size(),i;
    node *cur=root;
    for(i=0;i<len;i++){
        int id=str[i]-'a';
        if(cur->next[id]==NULL)return false;
        cur=cur->next[id];
    }
    return cur->ct;
}
int main()
{
    int n,i,j;
    cin>>n;
    root=new node();
    for(i=1;i<=n;i++){
        string s;
        cin>>s;
        insert1(s);
    }
    cout<<search1("im");
    return 0;
}


