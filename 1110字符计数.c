#include<stdio.h>
#include<string.h>
int main()
{
    char c[21];
    while(scanf("%s",&c)!=EOF)
    {
        printf("%d\n",strlen(c));//strlen���������ַ����ļ��������Լǿո�
    }
    return 0;
}
