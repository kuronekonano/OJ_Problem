#include<stdio.h>///距离之和为偶数就后动的赢，反之先动的赢
#include<math.h>
int main()
{
    char a[10][10];
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        for(i=1;i<=4;i++)
        {
            scanf("%s",a[i]);
        }
        int rj,ri,bj,bi;
        for(i=1;i<=4;i++)
        {
            for(j=0;j<8;j++)
            {
                if(a[i][j]=='.')
                {
                    rj=j;
                    ri=i;
                    break;
                }
            }
        }
        for(i=1;i<=4;i++)
        {
            for(j=0;j<8;j++)
            {
                if(a[i][j]=='*')
                {
                    bj=j;
                    bi=i;
                    break;
                }
            }
        }
        int disi=fabs(bi-ri);
        int disj=fabs(bj-rj);
        if((disi+disj)%2==0)
        {
            printf("Black win\n");
        }
        else
        {
            printf("Red win\n");
        }
    }
    return 0;
}
