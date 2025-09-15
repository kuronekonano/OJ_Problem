#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    int a[ 505 ][ 505 ], i, j, n, dp[ 505 ][ 505 ];
    while ( scanf( "%d", &n ) != EOF ) {
        for ( i = 0; i < n; i++ ) {
            for ( j = 0; j <= i; j++ ) {
                scanf( "%d", &a[ i ][ j ] );
            }
        }
        memset( dp, 0, sizeof( dp ) );
        for ( j = 0; j < n; j++ )  // 最后一行归为dp数组内存储
        {
            dp[ n - 1 ][ j ] = a[ n - 1 ][ j ];
        }
        for ( i = n - 2; i >= 0; i-- ) {
            for ( j = 0; j <= i; j++ ) {
                dp[ i ][ j ] = a[ i ][ j ] + min( dp[ i + 1 ][ j ], dp[ i + 1 ][ j + 1 ] );  // 从倒数第二行开始赋值并求和
            }
        }
        printf( "%d", a[ 0 ][ 0 ] );  // 山顶是肯定要走的
        i = 0;                        // 初始化从0开始，也就是位置位于山顶
        j = 0;
        while ( i < n - 1 )  // 一直计算到n-2行，倒数第二行，因为输出时是当行加一
        {
            if ( dp[ i + 1 ][ j ] < dp[ i + 1 ][ j + 1 ] )  // 根据之前dp数组中累加的路径,通过比较各个位置之间的求和大小，判断最小值，等效到a数组中输出路径
            {
                printf( " %d", a[ i + 1 ][ j ] );
                i = i + 1;  // 每次输出，要记得把坐标移动至那个刚刚输出的位置，便于下一次找新坐标
            }
            else {
                printf( " %d", a[ i + 1 ][ j + 1 ] );
                i = i + 1;
                j = j + 1;
            }
        }
        printf( "\n" );
    }
    return 0;
}
// #include<stdio.h>
// #include<algorithm>
// #include<string.h>
// using namespace std;
// int main()
//{
//     int n,i,j;
//     int a[505][505],dp[505][505];
//     while(scanf("%d",&n)!=EOF)
//     {
//         memset(dp,0,sizeof(dp));
//         for(i=1;i<=n;i++)
//         {
//             for(j=1;j<=i;j++)
//             {
//                 scanf("%d",&a[i][j]);
//                 if(i==n)
//                 {
//                     dp[i][j]=a[i][j];
//                 }
//             }
//         }
//         for(i=n-1;i>=1;i--)
//         {
//             for(j=1;j<=i;j++)
//             {
//                 dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
//             }
//         }
//         printf("%d",a[1][1]);
//         i=1,j=1;
//         while(i<n)
//         {
//             printf(" %d",dp[i+1][j]<dp[i+1][j+1]?a[i+1][j]:a[i+1][j+1]);
//             i=i+1;
//             j=dp[i+1][j]<dp[i+1][j+1]?j:j+1;
//         }
//         printf("\n");
//     }
//     return 0;
// }
