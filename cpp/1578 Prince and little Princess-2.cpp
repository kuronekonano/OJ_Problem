#include <deque>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    int n, i;
    while ( scanf( "%d", &n ) != EOF ) {
        deque< int > q;
        int          temp;
        for ( i = 0; i < n; i++ ) {
            scanf( "%d", &temp );
            q.push_front( temp );
        }
        char com[ 9 ];
        while ( scanf( "%s", com ) != EOF ) {
            if ( strcmp( com, "push" ) == 0 ) {
                scanf( "%d", &temp );
                q.push_front( temp );
            }
            else if ( strcmp( com, "back" ) == 0 ) {
                printf( "%d\n", q.front() );
            }
            else if ( strcmp( com, "pop" ) == 0 ) {
                printf( "%d\n", q.back() );
                q.pop_back();
            }
            else if ( strcmp( com, "empty" ) == 0 ) {
                printf( "%s\n", q.empty() ? "T^T" : "^_^" );
            }
            else {
                break;
            }
        }
    }
}
