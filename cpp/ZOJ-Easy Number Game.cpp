#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    long long t, n, m, tmp;
    scanf( "%lld", &t );
    while ( t-- ) {
        priority_queue< long long, vector< long long > > Q;
        while ( !Q.empty() )
            Q.pop();
        priority_queue< long long, vector< long long >, greater< long long > > q;
        while ( !q.empty() )
            q.pop();
        scanf( "%lld%lld", &n, &m );
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%lld", &tmp );
            q.push( tmp );
            Q.push( tmp );
        }
        long long ans = 0;
        while ( Q.size() > m * 2 )
            Q.pop();
        while ( m-- ) {
            ans += q.top() * Q.top();
            q.pop();
            Q.pop();
        }
        printf( "%lld\n", ans );
    }
}
