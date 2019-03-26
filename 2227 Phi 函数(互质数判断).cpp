#include<stdio.h>
int a[1008];
int gcd(int a,int b)
{
    while(b!=0)
    {
        int c=b;///c作为后项的临时存储
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
            if(gcd(i,j)==1)///公约数只有1的两数为互质数
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
