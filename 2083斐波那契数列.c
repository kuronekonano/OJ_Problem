#include<stdio.h>
int main()
{
    int f1,f2,sum,n,i,flag;
    while(scanf("%d%d%d",&f1,&f2,&n)!=EOF)
    {
            flag=2;
            for(i=f1+f2;i<=n;i++)
        {
            sum=f1+f2;
            if(i==sum)
            {   flag++;
                f1=f2;
                f2=sum;}
        }
        printf("%d\n",flag);
    }
    return 0;
}
