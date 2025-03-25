#include<stdio.h>
int main()
{
    int t,i;
    char x,y;
    scanf("%d",&t);
    for(i=t;i>0;i--)
    {
       getchar();
       scanf("%c %c",&x,&y);
       if(x==y)
        printf("6\n");
       else
        printf("5\n");
    }
    return 0;
}

