#include <math.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>  ///abs函数是在这个头文件里的
using namespace std;
struct num {
    long long n, i;
    bool      vis;
    bool      operator()( const num& a, const num& b )  /// 重载运算符
    {
        return a.n > b.n;
    }
} a[ 200005 ];
int main() {
    priority_queue< num, vector< num >, num > q;
    int                                       n, m, i, sumv;
    long long                                 x;
    while ( scanf( "%d%d%lld", &n, &m, &x ) != EOF ) {
        while ( !q.empty() )
            q.pop();
        sumv = 0;
        for ( i = 0; i < n; i++ ) {
            scanf( "%lld", &a[ i ].n );
            a[ i ].i = i;
            if ( a[ i ].n < 0 ) {
                a[ i ].vis = true;
                a[ i ].n   = abs( a[ i ].n );
                sumv++;
            }
            else
                a[ i ].vis = false;
            q.push( a[ i ] );
        }
        if ( sumv % 2 == 0 ) {
            int visi = -1;
            num temp = q.top();
            q.pop();
            while ( m != 0 ) {
                temp.n -= x;
                a[ temp.i ].n = temp.n;
                m--;
                if ( temp.n <= 0 ) {
                    visi          = temp.i;
                    temp.n        = abs( temp.n );
                    a[ temp.i ].n = temp.n;
                    q.push( temp );
                    while ( m != 0 ) {
                        temp = q.top();
                        q.pop();
                        temp.n += x;
                        a[ temp.i ].n = temp.n;
                        m--;
                        q.push( temp );
                    }
                }
            }
            for ( i = 0; i < n; i++ ) {
                if ( a[ i ].vis )
                    a[ i ].n *= -1;
                if ( i == visi )
                    a[ i ].n *= -1;
                printf( "%lld%c", a[ i ].n, i == n - 1 ? '\n' : ' ' );
            }
        }
        else {
            num temp;
            while ( m != 0 ) {
                temp = q.top();
                q.pop();
                temp.n += x;
                a[ temp.i ].n = temp.n;
                m--;
                q.push( temp );
            }
            for ( i = 0; i < n; i++ ) {
                if ( a[ i ].vis )
                    a[ i ].n *= -1;
                printf( "%lld%c", a[ i ].n, i == n - 1 ? '\n' : ' ' );
            }
        }
    }
}
