#include<stdio.h>
#include<string.h>
long long n,x,a[1050008],i,b[100008];///a数组用于标记出现的数的次数，b数组用于记录输入的数
int main()///a数组的标记同样可以用map实现，并且因为map无大小限制，因此不用考虑异或之后数值大小，但数组的要必须开的更大
{
    while(scanf("%lld%lld",&n,&x)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=0; i<n; i++)
        {
            scanf("%lld",&b[i]);///输入数组中的数
            a[b[i]]++;///计数出现次数
        }
        long long flag=0;///找到的异或组数
        for(i=0; i<n; i++)
        {
            if((x^b[i])!=b[i])
            {
                flag+=a[(x^b[i])];///正常情况，用x异或正在遍历的数，然后检查得数是否在数组b中，并且加上这个结果出现的次数，就是异或对的数量
            }
            else///如果x=0时，会出现两个相同的值异或运算之后等于0，此时因为计数面对的是同一个数字，因此自己不能和自己配对，只能是
                flag+=a[(x^b[i])]-1;///所有相同数的数量里，减去自己(-1),加上的次数才是自己和其他重复数字的配对数量
        }
        printf("%lld\n",flag/2);///因为从头至尾算重复两遍，所以算出来的组数要除2才是正确组数
    }
}
