#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s[20];//����һ���õ�strtlo�������⣬����ǰ�һ��ԭ����a���Ƶ����ֱ��ʮ���ƣ���ȻҲ����strtol��ֻ���baseֵ���ԭ����a���Ϳ��԰��ַ��������ʮ����
    int a,t;
    while(scanf("%d%s",&a,&s)!=EOF)
    {
        t=strtol(s,NULL,a);
        printf("%ld\n",t);
    }
    return 0;
}
