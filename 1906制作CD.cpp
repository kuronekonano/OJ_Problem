#include<stdio.h>
int main()
{
    int t,n,k,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(k==13)//把所有13首歌的碟子当做12首来处理
        {
            k--;
        }
        sum=n/k;
        int s=n%k;
        if(s!=0)
        {
            sum++;
            if(s==13&&n<k||s==13&&k==14)//当余数为13首歌的时候，是可以从前面的碟子中取一首来填上的，除了每张碟能装14首歌的情况
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
