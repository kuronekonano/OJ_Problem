//#include<stdio.h>//ǿ��ת��д��
//int main()
//{
//     double a;//���ʹ��double�����о�����ʧ�����ܴ洢����12=11.99999999����������
//     while(scanf("%lf",&a)!=EOF)
//     {
//         a=a*100;
//         a=(int)a/100.00;
//         printf("%.2f\n",(double)a);
//     }
//     return 0;
//}
#include<stdio.h>
int main()
{
    float a;
    int b;
    while(scanf("%f",&a)!=EOF)
    {
        b=a*100;
        a=b/100.00;
        printf("%.2f\n",a);
    }
    return 0;
}
