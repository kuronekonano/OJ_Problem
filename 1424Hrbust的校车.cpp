#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)///��������ۣ�ȫ������г�����
    {
        if(n==0&&m!=0)///û�д��� ֻ��С���ǲ������ϳ���
        {
            printf("Impossible\n");
            continue;
        }
        else if(n!=0&&m!=0)///�д�����С��������
        {
            if(n>m)
            {
                printf("%d %d\n",n,n+m-1);///���˶���С��
            }
            else
            {
                printf("%d %d\n",m,n+m-1);///�������
            }
        }
        else if(n!=0&&m==0)///ֻ�д���
        {
            printf("%d %d\n",n,n);
        }
        else
        {
            printf("0 0\n");///��û��
        }
    }
    return 0;
}
