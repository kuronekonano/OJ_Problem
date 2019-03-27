#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long t,n,i;
    scanf("%lld",&t);
    while(t--)
    {
        bool flag=false;
        scanf("%lld",&n);
        if(n<0)
            flag=true;
        long long temp=abs(n),ans=0,sum=0;
        while(temp>0)///调转，记位数
        {
            ans=ans*10+temp%10;
            temp/=10;
            sum++;
        }
        temp=ans;
        long long num=0;
        while(temp>0)///调转后位数
        {
            temp/=10;
            num++;
        }
        if(num<sum)///补零
        {
            for(i=0;i<sum-num;i++)
                ans*=10;
        }
        printf("%lld\n",flag?0-ans:ans);
    }
}
