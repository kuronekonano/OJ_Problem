#include<stdio.h>
int main()
{
    int i,j,n,x;
    int a[50][50];
    while(scanf("%d%d",&n,&x)!=EOF)
    {
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=i;j++)//j�ǿ��Ե���i�ģ��������
            {
                if(j==0||j==i)//��Ե��ĩβʱ��������1
                {
                    a[i][j]=1;
                }
                else
                {
                    a[i][j]=a[i-1][j-1]+a[i-1][j];//ĳ���������Ͻǵ������������Ϸ�����
                }
            }
        }
        printf("%d\n",a[n-1][x-1]);
    }
    return 0;
}
