#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int i,z,w,maxn=0,k,sum;
        for(i=1; i<=7; i++)
        {
            scanf("%d%d",&z,&w);///������ʱ��
            sum=z+w-8;///���
            if(maxn<sum)///�����ֵ
            {
                maxn=sum;
                k=i;///��¼����
            }
        }
        printf("%d\n",k);///�������
    }
}
