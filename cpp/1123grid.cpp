#include <stdio.h>
#include <string.h>
int main() {
    int n, m, j, i;
    while ( scanf( "%d%d", &n, &m ) != EOF )  // 递归算法，输入方格大小
    {
        if ( m == 0 && n == 0 )  // 同时为零时则结束，单个为零时输出1种走法
        {
            return 0;
        }
        int a[ n + 5 ][ m + 5 ];        // 设定二维数组，保存每个坐标走的步数
        memset( a, 0, sizeof( a ) );    // 清空数组
        for ( i = 1; i <= n + 1; i++ )  // 循环两次以遍历判断每个坐标的步骤数量
        {
            for ( j = 1; j <= m + 1; j++ ) {
                if ( i == 1 || j == 1 )  // 边界都为1步
                {
                    a[ i ][ j ] = 1;
                }
                else {
                    a[ i ][ j ] = a[ i - 1 ][ j ] + a[ i ][ j - 1 ];  // 中间都为上方坐标加上左方坐标和
                }
            }
        }
        printf( "%d\n", a[ n + 1 ][ m + 1 ] );  // 输出最后一个坐标目的地的步骤数和
    }
    return 0;
}  // 还有一种排列组合的乘法方法
// # include<cstdio>//走格子
// int main()
//{
//     int m,n,i,a,b;
//     while(scanf("%d%d",&m,&n)!=EOF)//排列组合
//     {
//         a=1;b=1;
//         if(m==0&&n==0) break;
//         for(i=m+1;i<m+n+1;i++)//输入的m和n要以坐标点来计算，分别加1，共（n+1）*（m+1）个点，i表示最终走的步骤数，一定等于m+n步，边长之和，纵向横向分别走的
//             a=a*i;//走向下一步时，为前一步的乘积
//         for(i=1;i<n+1;i++)
//             b=b*i;
//         printf("%d\n",a/b);
//     }
// }
