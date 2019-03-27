#include<stdio.h>
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        printf("Case #%d:\n",cas++);///通分一下第三个条件，得到(A^2+B^2)/A*B<=(C^2+D^2)/C*D
        if(a==b)///这个不等式在A------------B这段中，任取两个数，是必定比A/B+B/A小的，除非取到A和B就刚好等于，因此不会有大于A/B+B/A的数，刚好等于的也就是A B本身
        {
            printf("1\n%lld %lld\n",a,b);
        }
        else///所以固定的，直接输出就好，注意是10^18，要用long long 存储
        {
            printf("2\n%lld %lld\n%lld %lld\n",a,b,b,a);
        }
    }
    return 0;
}
