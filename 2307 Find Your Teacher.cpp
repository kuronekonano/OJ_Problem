#include<stdio.h>///�����֤һ�������������⣬��Ϊ�����������Ǻܴ����Ա���������
#include<string.h>///Ƕ��������for
int main()
{
    int t,i,j,k;
    bool wap[55][55];
    scanf("%d",&t);
    while(t--)
    {
        memset(wap,false,sizeof(wap));///���һ��Ҫ�ǵ��������
        int n,m,x,y;
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            wap[x][y]=true;///��������й�ϵ
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                {
                    if(wap[i][j]==true&&wap[j][k]==true)
                    {
                        wap[i][k]=true;///������ϵ
                    }
                }
            }
        }
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//                printf("%d",wap[i][j]);
//            printf("\n");
//        }
        if(wap[1][n]==true)
        {
            printf("^_^\n");
        }
        else
            printf("T_T\n");
    }
    return 0;
}
