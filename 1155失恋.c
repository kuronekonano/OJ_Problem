#include<stdio.h>
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if((m%4==0&&m%100!=0)||(m%400==0))//�����Ǳ��������Ҳ���100������������ ����Ҳ���İ�����
        {
            if(n==1||n==3||n==5||n==7||n==8||n==10||n==12)
            {
                printf("31\n");
            }
            else if(n==2)
            {
                printf("29\n");
            }
            else if(n==4||n==6||n==9||n==11)
            {
                printf("30\n");
            }
        }
        else
        {
            if(n==1||n==3||n==5||n==7||n==8||n==10||n==12)
            {
                printf("31\n");
            }
            else if(n==2)
            {
                printf("28\n");
            }
            else if(n==4||n==6||n==9||n==11)
            {
                printf("30\n");
            }
        }

    }
    return 0;
}
