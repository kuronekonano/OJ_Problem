#include <queue>
#include <stdio.h>
using namespace std;
int main() {
    priority_queue< int >                                q;  /// 俩优先队列
    priority_queue< int, vector< int >, greater< int > > p;
    int                                                  a, n;
    while ( scanf( "%d", &n ) != EOF ) {
        while ( !q.empty() || !p.empty() ) {
            q.pop();
            p.pop();
        }
        for ( int i = 0; i < n; i++ ) {
            scanf( "%d", &a );
            q.push( a );
            p.push( a );
        }
        int first;
        while ( q.size() != 1 ) {
            first = q.top();
            q.pop();
            first = q.top() * first + 1;
            q.pop();
            q.push( first );
        }
        int minn = q.top();
        while ( p.size() != 1 ) {
            first = p.top();
            p.pop();
            first = p.top() * first + 1;
            p.pop();
            p.push( first );
        }
        int maxn = p.top();
        printf( "%d\n", maxn - minn );
    }
    return 0;
}
