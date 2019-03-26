#include<stdio.h>//·Æ²¨ÄÇÇÐÊýÁÐ
int main()
{
    int a,b,c[45],i;
    while(scanf("%d",&a)!=EOF)
    {
        if(a==0)
        {
            return 0;
        }
        else if(a==1)
        {
            printf("1\n");
        }
        else if(a==2)
        {
            printf("2\n");
        }
        else
        {
            c[1]=1;
            c[2]=2;
            for(i=3;i<=a;i++)
            {
                c[i]=c[i-1]+c[i-2];
            }
            printf("%d\n",c[a]);
        }
    }
    return 0;
}
