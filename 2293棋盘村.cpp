#include<stdio.h>
#include<string.h>
int main()
{
    long long a[105][105];
    int j,i,n,m,t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&x,&y);
        memset(a,0,sizeof(a));
        for(i=0,j=0; i<=n; i++)//处理边界问题，在边界每个点都1种方式到达，特殊情况是当不可走的点在边界时，这个点之后的点全部不能到达
        {
            if((i==x&&j==y)||
                    (i==x+1&&j==y+2)||
                    (i==x+2&&j==y+1)||
                    (i==x+1&&j==y-2)||
                    (i==x+2&&j==y-1)||
                    (i==x-1&&j==y-2)||
                    (i==x-1&&j==y+2)||
                    (i==x-2&&j==y+1)||
                    (i==x-2&&j==y-1))
            {
                break;
            }
            else
            {
                a[i][j]=1;
            }
        }
        for(i=0,j=0; j<=m; j++)//处理横竖两个边界
        {
            if((i==x&&j==y)||
                    (i==x+1&&j==y+2)||
                    (i==x+2&&j==y+1)||
                    (i==x+1&&j==y-2)||
                    (i==x+2&&j==y-1)||
                    (i==x-1&&j==y-2)||
                    (i==x-1&&j==y+2)||
                    (i==x-2&&j==y+1)||
                    (i==x-2&&j==y-1))
            {
                break;//遇到不可走的点，直接停止赋值
            }
            else
            {
                a[i][j]=1;
            }
        }
        for(i=0; i<=n; i++)//计算列阵
        {
            for(j=0; j<=m; j++)//当遇到这些点时，因为不能走，所以到达这个点的方式为0
            {
                if((i==x&&j==y)||
                        (i==x+1&&j==y+2)||
                        (i==x+2&&j==y+1)||
                        (i==x+1&&j==y-2)||
                        (i==x+2&&j==y-1)||
                        (i==x-1&&j==y-2)||
                        (i==x-1&&j==y+2)||
                        (i==x-2&&j==y+1)||
                        (i==x-2&&j==y-1))
                {
                    a[i][j]=0;
                }
                else if(i!=0&&j!=0)//能走的点则可以求和递归计算到达下个点的方式数量
                {
                    a[i][j]=a[i-1][j]+a[i][j-1];
                }
            }
        }
        printf("%lld\n",a[n][m]);//到达终点的方式数量
//        for(i=0; i<=n; i++)//棋盘阵
//        {
//            for(j=0; j<=m; j++)
//            {
//                printf("%6lld",a[i][j]);
//            }
//            printf("\n");
//        }
    }
    return 0;
}

