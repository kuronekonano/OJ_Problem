#include<stdio.h>
int main()
{
    int n,i,j,s,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        y=n;
        for(i=1;i<=n;i++)//��i��
        {
            s=10+2*(i-1);//��s��i���
            for(j=y-1;j>0;j--)//ÿ������ո���
            {
                printf(" ");
            }
            for(x=1;x<=s;x++)//���x��i
            {
                printf("i");
            }
            printf("\n");
            y--;
        }
    }
    return 0;
}
