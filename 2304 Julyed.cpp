#include<stdio.h>
int main()
{
    int x,y,z,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(x+z-y<=10)
        {
            printf("memeda\n");
        }
        else if(x+z-y>=30)
        {
            printf("QAQ\n");
        }
        else
        {
            printf("%d\n",x+z-y);
        }
    }
    return 0;
}
