#include<stdio.h>
int main()
{
    int y;
    while(scanf("%d",&y)!=EOF)
    {
        printf("%u\n",1+y);//牢记无符号整型输出输入为%u
    }
    return 0;
}
