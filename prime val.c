#include<stdio.h>
int ara[26];
int main()
{
    int m,i,j,n,ct=0;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){
        scanf("%d",&ara[i]);
    }
    for(i=0;i<m;i++){
        ct+=n/ara[i];
        if(i!=0){
            for(j=0;j<i;j++){
                ct-=n/(ara[i]*ara[j]);
            }
        }
    }

    printf("%d",ct);
    return 0;
}
