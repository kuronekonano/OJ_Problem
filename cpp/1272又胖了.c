//#include<stdio.h>//强制转换写法
//int main()
//{
//     double a;//如果使用double型则有精度损失，可能存储的是12=11.99999999·····
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
