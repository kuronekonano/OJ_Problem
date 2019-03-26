#include<stdio.h>
int main()
{
    int i,a[105],j,n=0,flag=0;
    while(scanf("%d",&a[++n]))//循环输入到数组a中，并且每次输入n的数量先加再赋值
    {
        if(a[n]==-1)//当a[n]=-1输入时，终止循环
        {
            return 0;
        }
        flag=0;//初始化计数器
        if(a[n]==0)//若输入的数发现为0时开始统计0之前输入到数组a中的各个值
        {
            for(i=1;i<=n-1;i++)//双重循环遍历数组，每次选取一个数，向前一个数开始比较
            {
                for(j=i+1;j<=n-1;j++)//注意这里要用n-1，因为第n位是0
                {
                    if(a[i]==2*a[j]||a[j]==2*a[i])
                    {
                        flag++;//计数器统计符合2倍的次数
                    }
                }
            }
            printf("%d\n",flag);
            n=0;
        }
    }
    return 0;
}
