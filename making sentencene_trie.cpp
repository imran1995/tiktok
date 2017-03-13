//It contains a dictionary of lowercase words
//There will be a given sentence
//First and Last letter of every words will be fixed
//Make permutation of every words without first and last letter
//Find out The words from the dictionary
//Determine The number of possible sentence
#include<bits/stdc++.h>
using namespace std;
int k;
struct node
{
    int ct;
    node *next[27+1];
    node()
    {
        //em=false;
        ct=0;
        for(k=0;k<26;k++){
            next[k]=NULL;
        }
    }
}*root;
/*void del(node *cur)
{
    for(int i=0;i<26;i++){
        if(cur->next[i]!=NULL)del(cur->next);
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
        //cur->ct++;
    }
    cur->ct++;
}
int search1(vector<char>str)
{
    int len=str.size(),i;
    node *cur=root;
    for(i=0;i<len;i++){
        int id=str[i]-'a';
        if(cur->next[id]==NULL)return 0;
        cur=cur->next[id];
    }
    return cur->ct;
}
int main()
{
    int n,j,i;
    cin>>n;
    root=new node();
    string s;
    for(i=1;i<=n;i++){

        cin>>s;
        sort(++s.begin(),s.end()-1);
        insert1(s);
    }
    /*char ch,cv,cb;
    int st;
    printf("k %d k",st);//problemmmmmmmm............................*/


    vector<char>v;

    int val=0,ans=1;
    while(ch!='\n'){
        //scanf("%c",&ch);
        ch=getchar();
        if(ch==' ' || ch=='\n'){
            sort(++v.begin(),v.end()-1);
            ans*=search1(v);
            v.clear();
        }
        else v.push_back(ch);
    }
    printf("%d",ans);
    return 0;
}
