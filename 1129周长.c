#include<stdio.h>
int main()
{
    int a,i;
    while(scanf("%d",&a)!=EOF)
    {
        int b=0;//��ʼ��b
        if(a<3)
        {
            printf("0\n");//С��3���ܳ��������ж����
        }
        else
        {
            for(i=3;i<=a;i++)
            {
                if(a%i==0)
                {
                    b++;//��b����
                }
            }
            printf("%d\n",b);
        }
    }
    return 0;
}
