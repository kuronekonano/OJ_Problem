#include<stdio.h>///�������������ֱ���f(0),f(1),f(2)�Ľ����f(x)=a*x^2+b*x+c
int main()///���a,b,c��Ȼ��x����3,4,5�����ǽ��
{
    int a,b,c,x1,x2;
    while(scanf("%d%d%d",&c,&x1,&x2)!=EOF)
    {
        a=((x2-c)-2*(x1-c))/2;
        b=x1-c-a;
        printf("%d %d %d\n",a*9+b*3+c,a*16+b*4+c,a*25+b*5+c);
    }
}
