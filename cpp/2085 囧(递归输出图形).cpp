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
    a[ x + len - 1 ][ y + len - 1 ] = a[ x + len - 1 ][ y ] = a[ x ][ y + len - 1 ] = a[ x ][ y ] = '+';  /// �Ľ�
    for ( int i = y + 1; i < y + len - 1; i++ )
        if ( a[ x ][ i ] != '+' )
            a[ x ][ i ] = '-';  /// �Ϸ��߽�
    for ( int i = x + 1; i <= x + len - 2; i++ )
        a[ i ][ y + len - 1 ] = a[ i ][ y ] = '|';  /// ���ұ߽�
    if ( n == 0 )
        return;
    int midy = y + ( len / 2 ) - 1;
    int midx = x + ( len / 2 ) - 1;
    for ( int i = x + 2, j = midy - 1, k = midy + 2; i <= midx - 1 && j >= y + 1; i++, j--, k++ )
        a[ i ][ j ] = '/', a[ i ][ k ] = '\\';  /// ������
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
                a[ len ][ i ] = '-';  /// �·��߽�
        for ( int i = 1; i <= len; i++ ) {
            for ( int j = 1; j <= len; j++ )
                printf( "%c", a[ i ][ j ] );
            printf( "\n" );
        }
    }
}

/**
#include<stdio.h>///�򵥵ݹ飬�������η������ϰ벿���۾�����ΧһȦ�߿��ǲ���Ҫ�ݹ�ģ������°벿�ֵ����λ����Ҫ�ݹ�
#include<string.h>///ÿ�δ��ݵĲ������������Ͻǵ����꣬���������������εĴ�С(����)�����ɵõ�λ�ú�������Ĺ���
#include<math.h>
char a[800][800];
void digui(int x,int y,int n)
{
    int len=pow(2,n+2);///��n�����εı߳�Ϊ2^(n+2),����һ��������
    a[x][y]='+';///�ĸ��ǵļӺ�
    a[x][y+len-1]='+';
    a[x+len-1][y]='+';
    a[x+len-1][y+len-1]='+';
    for(int i=y+1;i<=y+len-2;i++)///�Ϸ��߽�
    {
        if(a[x][i]!='+')
        {
            a[x][i]='-';
        }
    }
    for(int i=x+1;i<=x+len-2;i++)///���ұ߽�
    {
        a[i][y]='|';
        a[i][y+len-1]='|';
    }
    if(n==0)return;
    int midy=y+(len/2)-1;
    int midx=x+(len/2)-1;
    for(int i=x+2,j=midy-1;i<=midx-1&&j>=y+1;i++,j--)///����
    {
        a[i][j]='/';
    }
    for(int i=x+2,j=midy+2;i<=midx-1&&j<=y+len-3;i++,j++)///����
    {
        a[i][j]='\\';
    }
    int l=pow(2,n+1);
    int nx=x+len/2;///��һ��ͼ�ε����Ͻǵ�����λ��
    int ny=y+l/2;
    digui(nx,ny,n-1);///�ݹ�Ѱ����һ��ͼ��
}
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,' ',sizeof(a));
        digui(1,1,n);///�ݹ鿪ʼ
        int l=pow(2,n+2);
        for(int i=1;i<=l;i++)
        {
            if(a[l][i]!='+')
            {
                a[l][i]='-';
            }
        }///��Ϊ����µı��ǹ��õģ��������ڱ��+�ǵĻ����ϲ���-��
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
