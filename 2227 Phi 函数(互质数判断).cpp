#include<stdio.h>
int a[1008];
int gcd(int a,int b)
{
    while(b!=0)
    {
        int c=b;///c��Ϊ�������ʱ�洢
        b=a%b;
        a=c;
    }
    return a;
}
void inti()
{
    int i,j;
    for(i=1;i<=1000;i++)
    {
        int flag=0;
        for(j=i;j>=1;j--)
        {
            if(gcd(i,j)==1)///��Լ��ֻ��1������Ϊ������
            {
                flag++;
            }
        }
        a[i]=flag;
    }
}
int main()
{
    int n;
    inti();
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",a[n]);
    }
    return 0;
}
