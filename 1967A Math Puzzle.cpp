#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[25];
    while(scanf("%s",a)!=EOF)
    {
        long n=strtol(a,NULL,12);///ת�� 12���Ƶ�ʮ���ƣ�ͷ�ļ����⣬ֱ��ȡ������
        printf(n%11==0?"YES\n":"NO\n");
    }
    return 0;
}
