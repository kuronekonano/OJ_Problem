#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        double a=log(n)/log(2);
        double b=ceil(log(n)/log(2));
        if(a-b==0)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        if(n&1) printf("%d = %d + %d\n",n,n/2,n/2+1);///奇数n可以直接除2输出n/2+1和n/2
        else
        {
            int k=0x7fffffff,f=0;
            for(int i=2; i<=sqrt(n); i++)
            {
                if(n%i)continue;///不是因子的数忽略
                int odd=i,even=n/i;///取因子
                if(!(odd&1)&&!(even&1))continue;///不是一奇一偶忽略
                if(!(odd&1))swap(odd,even);///确定因子odd为奇数，even为偶数
                f=1;
                odd=odd>even*2?even*2:odd;
                k=min(k,odd);
            }
            if(!f)///除了上述2的次方数无解外，可能还有数无解，这里做一个标记
            {
                printf("IMPOSSIBLE\n");
                continue;
            }
            int aa=(n*2/k+1-k)/2;///计算首项
            printf("%d = ",n);
            for(int i=aa; i<aa+k; i++)
            {
                printf("%d",i);
                if(i!=aa+k-1)printf(" + ");
                else printf("\n");
            }
        }
    }
}
///由求和公式可得，n=((a+b)*k)/2,k为数列长度，a为最左边的首项，b为末项
///一个数n可以分成两个数的乘积，这两个因数就是n1个n2相加，那么这两个n1和n2都可能为项数k，题目要求选取最小的一个
///唯有两个因子是一奇一偶时才有解，奇数项时，有偶数个奇数以及奇数个数+1个偶数，当项数为偶数时，不存在，因此将项数变为偶数*2可以构造出连续加和
///不断取寻找可以整除的因子，并且符合一奇一偶的条件，然后在满足条件的因子中取较小的项数，最后得到项数可以根据公式逆推除首项为a，末项b=a+k-1
///2*n=(a+b)*k     2*n/k=a+a+k-1   2*n/k=2*a+k-1     (2*n/k+1-k)/2=a
///直接输出范围a到b的值即可
