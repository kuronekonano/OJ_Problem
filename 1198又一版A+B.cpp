#include<stdio.h>
int main()
{
    int m,a,b;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0)
            return 0;
        scanf("%d%d",&a,&b);
        a=a+b;///ֱ�Ӽ���A+B
        int c[100000],flag=0;
        while(a)///����ת��ѭ��
        {
            c[flag++]=a%m;///��ģ���̣��洢λ���ǵ��Ŵ��
            a/=m;
        }
        for(int i=flag-1;i>=0;i--)
        {
            printf("%d",c[i]);
        }
        printf("\n");
    }
    return 0;
}
