#include<stdio.h>
int main()
{
    int i,a,b,c;
    for(i=10000;i<100000;i++)//意思就是万位乘千位等于各位十位的数
    {
        a=i/10000;
        b=i/1000%10;
        c=i%100;
        if(a*b==c)
            printf("%d\n",i);
    }
    return 0;
}
