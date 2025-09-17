#include <stdio.h>
#include <string.h>
bool a[ 10005 ];
void inti() {
    memset( a, true, sizeof( a ) );
    a[ 1 ] = false;  /// 素数筛
    for ( int i = 2; i <= 10000; i++ ) {
        for ( int j = i + i; j <= 10000; j += i ) {
            a[ j ] = false;
        }
    }
}
int main()  /// 注意是不同素数，因此不会出现2+2的情况
{
    int n, sum;
    inti();
    while ( scanf( "%d", &n ) != EOF ) {
        sum = 0;
        for ( int i = 3; i < n / 2; i += 2 )  /// 从3开始遍历，因为输入的是偶数，2是唯一一个偶数素数，只会加上一个偶数才会与得到偶数
        {                                     /// 这显然是不存在的，并且遍历直到n/2-1，排除了两素数相等情况
            if ( a[ i ] && a[ n - i ] )       /// 如果这个数是素数，且与之求和等于n的数也是素数，那么就是一组素数和
                sum++;
        }
        printf( "%d\n", sum );
    }
}
// #include<stdio.h>
// #include<math.h>
// int a[10005];
// int sushu(int n)
//{
//     int j,i,k=0;
//     for(i=2;i<n;i++)
//     {
//         bool flag=true;
//         for(j=2;j<=sqrt(i);j++)
//         {
//             if(i%j==0)
//             {
//                 flag=false;
//             }
//         }
//         if(flag==true)
//         {
//             a[k]=i;
//             k++;
//         }
//     }
//     return k;
// }
// int main()
//{
//     int t,n,j,flag1;
//     while(scanf("%d",&t)!=EOF)
//     {
//         n=sushu(t);
//         flag1=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(a[i]+a[j]==t)
//                 {
//                     flag1++;
//                 }
//             }
//         }
//         printf("%d\n",flag1);
//     }
//     return 0;
// }
