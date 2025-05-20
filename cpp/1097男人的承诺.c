#include<stdio.h>
int main()
{
    int t,i;
    char a[101];//开的数组要大于规定数组，因为存在\0，并且\0算是一个字符！！！
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s",a);//字符串数组赋值不需要加&
        printf("%s\n",a);
    }
    return 0;
}
