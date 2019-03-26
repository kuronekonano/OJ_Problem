#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int i,z,w,maxn=0,k,sum;
        for(i=1; i<=7; i++)
        {
            scanf("%d%d",&z,&w);///早晚工作时长
            sum=z+w-8;///求和
            if(maxn<sum)///找最大值
            {
                maxn=sum;
                k=i;///记录天数
            }
        }
        printf("%d\n",k);///输出天数
    }
}
