#include <stdio.h>
#include <string.h>
int z[ 60001 ];
int find( int x ) {
    int r = x, t;
    while ( r != z[ r ] )  // 找上级，并压缩路径
    {
        t      = r;       /// 压缩路径步骤
        r      = z[ r ];  /// 上溯步骤
        z[ t ] = z[ r ];  /// 压缩路径步骤
    }
    return r;
}
void join( int a, int b )  // join函数建立各个点之间的从属关系
{
    int fa = find( a ), fb = find( b );  // 查找双方的上级，如果不同则建立从属关系
    if ( fa != fb )                      // 若上级不同
    {
        z[ fa ] = fb;  // 建立从属关系
    }
}
int main() {
    int j, n, m, u, v, i, sum;
    while ( scanf( "%d%d", &n, &m ) != EOF ) {
        for ( i = 0; i < n; i++ )  // 初始化，自己为自己的老大
        {
            z[ i ] = i;
        }
        for ( i = 0; i < m; i++ )  // 输入关系
        {
            scanf( "%d%d", &u, &v );
            join( u, v );
        }
        int boss = find( 0 );
        sum      = 0;
        for ( j = 0; j < n; j++ ) {
            if ( find( j ) == boss )  // 当找到的上级与感染源相等时，感染人数加一
            {
                sum++;
            }
        }
        printf( "%d\n", sum );
    }
    return 0;
}
