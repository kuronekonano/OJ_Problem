#include<stdio.h>
int main()
{
    int t,i;
    char a[101];//��������Ҫ���ڹ涨���飬��Ϊ����\0������\0����һ���ַ�������
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s",a);//�ַ������鸳ֵ����Ҫ��&
        printf("%s\n",a);
    }
    return 0;
}
