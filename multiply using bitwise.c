#include<stdio.h>
int main()
{
    int n,m,sum=0;
    scanf("%d %d",&n,&m);
    while(m!=0){
        if(m&1){
            sum+=n;
        }
        n<<=1;
        m>>=1;

    }
    printf("%d",sum);
    return 0;
}
