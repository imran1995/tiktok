//Finding LONGEST COMMON SUBSTRING using suffix trie
//Of Any number of string

#include<bits/stdc++.h>
using namespace std;
int k;
struct node
{
    int ct,str_num;
    node *next[27+1];
    node()
    {
        ct=0;
        str_num=0;
        for(k=0;k<26;k++){
            next[k]=NULL;
        }
    }
}*root;
/*void del(node *cur)
{
    for(i=0;i<26;i++){
        if(cur->next[i])del(cur->next);
    }
    delete(cur);
}*/

void insert1(string str,int low,int len,int val)//For string 1;
{
    int i;
    node *cur=root;
    for(i=0;i<len-low;i++){
        int id=str[i+low]-'a';
        if(cur->next[id]==NULL){
            cur->next[id]=new node();
        }
        cur=cur->next[id];
        cur->ct=(i+1);
        cur->str_num=1;
    }
}
int insert2(string str,int low,int len,int val)//For string 2
{
    int i;
    node *cur=root;
    for(i=0;i<len-low;i++){
        int id=str[i+low]-'a';
        if(cur->next[id]==NULL){
            return cur->ct;
        }
        if(cur->next[id]->str_num<val-1)return cur->ct;
        cur=cur->next[id];
        cur->str_num=val;
    }
    return cur->ct;
}
int main()
{
    int n,i,j,len,foul,mx=0;
    cin>>n;
    root=new node();
    string s;
    if(n==1){
        cin>>s;
        printf("%d",s.size());
        return 0;
    }
    for(i=1;i<=n;i++){
        cin>>s;
        len=s.size();
        if(i==1){
            for(j=0;j<len;j++){
                insert1(s,j,len,i);
            }
        }
        else if(i<n){
            for(j=0;j<len;j++){
                foul=insert2(s,j,len,i);
            }
        }
        else{
            for(j=0;j<len;j++){
                foul=insert2(s,j,len,i);
                if(foul>mx)mx=foul;
            }
        }
    }

    /*len=s.size();
    for(i=0;i<len;i++){
        insert1(s,i,len);
    }
    string s1;
    cin>>s1;
    int mx=0,val;
    len=s1.size();
    /*for(i=0;i<s1.size();i++){
        val=insert2(s1,i,len);
        if(mx<val)mx=val;
    }*/
    cout<<mx<<endl;
    return 0;
}



