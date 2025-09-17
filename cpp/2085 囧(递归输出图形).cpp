#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 4 << 9;
int       t, n;
char      a[ maxn ][ maxn ];
void      print( int n, int x, int y ) {
    int len                         = 1 << ( n + 2 );
    a[ x + len - 1 ][ y + len - 1 ] = a[ x + len - 1 ][ y ] = a[ x ][ y + len - 1 ] = a[ x ][ y ] = '+';  /// 四角
    for ( int i = y + 1; i < y + len - 1; i++ )
        if ( a[ x ][ i ] != '+' )
            a[ x ][ i ] = '-';  /// 上方边界
    for ( int i = x + 1; i <= x + len - 2; i++ )
        a[ i ][ y + len - 1 ] = a[ i ][ y ] = '|';  /// 左右边界
    if ( n == 0 )
        return;
    int midy = y + ( len / 2 ) - 1;
    int midx = x + ( len / 2 ) - 1;
    for ( int i = x + 2, j = midy - 1, k = midy + 2; i <= midx - 1 && j >= y + 1; i++, j--, k++ )
        a[ i ][ j ] = '/', a[ i ][ k ] = '\\';  /// 左右眼
    int nx = x + len / 2;
    int ny = y + ( 1 << n );
    print( n - 1, nx, ny );
}
int main() {
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        memset( a, ' ', sizeof a );
        print( n, 1, 1 );
        int len = 1 << ( n + 2 );
        for ( int i = 1; i <= len; i++ )
            if ( a[ len ][ i ] == ' ' )
                a[ len ][ i ] = '-';  /// 下方边界
        for ( int i = 1; i <= len; i++ ) {
            for ( int j = 1; j <= len; j++ )
                printf( "%c", a[ i ][ j ] );
            printf( "\n" );
        }
    }
}

/**
#include<stdio.h>///简单递归，将囧字形分区域，上半部分眼镜和周围一圈边框是不需要递归的，仅有下半部分的嘴巴位置需要递归
#include<string.h>///每次传递的参数是新囧形左上角的坐标，有了这个坐标和新囧形的大小(长宽)，即可得到位置和整个囧的构造
#include<math.h>
char a[800][800];
void digui(int x,int y,int n)
{
    int len=pow(2,n+2);///第n个囧形的边长为2^(n+2),囧是一个正方形
    a[x][y]='+';///四个角的加号
    a[x][y+len-1]='+';
    a[x+len-1][y]='+';
    a[x+len-1][y+len-1]='+';
    for(int i=y+1;i<=y+len-2;i++)///上方边界
    {
        if(a[x][i]!='+')
        {
            a[x][i]='-';
        }
    }
    for(int i=x+1;i<=x+len-2;i++)///左右边界
    {
        a[i][y]='|';
        a[i][y+len-1]='|';
    }
    if(n==0)return;
    int midy=y+(len/2)-1;
    int midx=x+(len/2)-1;
    for(int i=x+2,j=midy-1;i<=midx-1&&j>=y+1;i++,j--)///左眼
    {
        a[i][j]='/';
    }
    for(int i=x+2,j=midy+2;i<=midx-1&&j<=y+len-3;i++,j++)///右眼
    {
        a[i][j]='\\';
    }
    int l=pow(2,n+1);
    int nx=x+len/2;///下一个图形的左上角的坐标位置
    int ny=y+l/2;
    digui(nx,ny,n-1);///递归寻找下一个图形
}
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,' ',sizeof(a));
        digui(1,1,n);///递归开始
        int l=pow(2,n+2);
        for(int i=1;i<=l;i++)
        {
            if(a[l][i]!='+')
            {
                a[l][i]='-';
            }
        }///因为最底下的边是共用的，因此最后在标好+角的基础上补齐-边
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=l;j++)
            {
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
    }
}
**/
