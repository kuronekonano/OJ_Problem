#include<stdio.h>
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        printf("%X\n",a+b);//%x���ʮ�����ƣ�%d���ʮ���ƣ�%o����˽���
    }
    return 0;
}
