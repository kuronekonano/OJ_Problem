#include <algorithm>
#include <math.h>
#include <stdio.h>
#define Pi acos( -1 )
using namespace std;
double cal( int r, int R, int x1, int x2, int y1, int y2 ) {
    double dis = sqrt( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 ) );
    if ( R < r )
        swap( r, R );
    if ( R + r <= dis )
        return 0;        /// 相离
    if ( dis <= R - r )  /// 内含
    {
        return Pi * r * r;
    }
    if ( dis > R - r && dis < R + r )  /// 相交
    {
        double S1 = Pi * r * r * 2 * acos( ( r * r + dis * dis - R * R ) / ( 2 * r * dis ) ) / ( 2 * Pi );  /// 余弦定理，三角形三边算cos值
        double S2 = Pi * R * R * 2 * acos( ( R * R + dis * dis - r * r ) / ( 2 * R * dis ) ) / ( 2 * Pi );
        double S3 = sin( acos( ( R * R + dis * dis - r * r ) / ( 2 * R * dis ) ) ) * R * dis;  /// 菱形面积，垂直的对角线长度除2,垂直于圆心距的对角线用sin值来求长度
        return S1 + S2 - S3;                                                                   /// 两扇形面积减去多算的菱形面积(容斥原理)
    }
}
int main() {
    int cas = 0, i, r, R, x1, x2, y1, y2, t;
    scanf( "%d", &t );
    while ( t-- ) {
        cas++;
        scanf( "%d%d%d%d%d%d", &r, &R, &x1, &y1, &x2, &y2 );
        double area = cal( R, R, x1, x2, y1, y2 ) - 2 * cal( r, R, x1, x2, y1, y2 ) + cal( r, r, x1, x2, y1, y2 );  /// 容斥原理
        printf( "Case #%d: %.6lf\n", cas, area );
    }
}
/// 两环相交面积=两大圆相交面积-2*一大圆与一小圆相交面积+两小圆相交面积
