#include<stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a))//从1到9，除以9都得到0.nnnnnnnn的循环小数
    {
        switch(a)
        {
            case 1:printf("1/9\n");break;
            case 2:printf("2/9\n");break;
            case 3:printf("1/3\n");break;
            case 4:printf("4/9\n");break;
            case 5:printf("5/9\n");break;
            case 6:printf("2/3\n");break;
            case 7:printf("7/9\n");break;
            case 8:printf("8/9\n");break;
            case 9:printf("1\n");break;
            case 0:return 0;
        }
    }
    return 0;
}
