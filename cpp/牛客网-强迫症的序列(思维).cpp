#include <queue>
#include <stdio.h>
using namespace std;
int main() {
    //    freopen("text.txt","r",stdin);
    priority_queue< int > q;
    int                   t, n, tmp;
    scanf( "%d", &t );
    while ( t-- ) {
        while ( !q.empty() )
            q.pop();
        scanf( "%d", &n );
        int minn = 0x7fffffff, sum = 0;
        for ( int i = 0; i < n; i++ ) {
            scanf( "%d", &tmp );
            if ( tmp < minn )
                minn = tmp;
            q.push( tmp );
        }
        while ( q.top() != minn ) {
            //            printf("%d   %d   %d\n",minn,q.top(),tmp);
            tmp = q.top();
            q.pop();
            int last = q.top();
            if ( last == tmp ) {
                q.push( minn );
                sum += tmp - minn;
                continue;
            }
            sum += tmp - last;
            q.push( last );
        }
        printf( "%d %d\n", sum, minn + sum );
    }
}
