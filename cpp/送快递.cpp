#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct ems {
    char name[ 20 ];
    char food[ 20 ];
    int  st;
    int  send;
    int  get;
    int  fin;
} box[ 1005 ];
bool cmp( ems a, ems b ) {
    if ( a.fin == b.fin ) {
        return ( strcmp( a.food, b.food ) < 0 );
    }
    return a.fin < b.fin;
}
int main() {
    int n, i;
    while ( scanf( "%d", &n ) != EOF ) {
        for ( i = 0; i < n; i++ ) {
            scanf( "%s %s %d %d %d", box[ i ].name, box[ i ].food, &box[ i ].st, &box[ i ].send, &box[ i ].get );
        }
        for ( i = 0; i < n; i++ ) {
            box[ i ].fin = box[ i ].st + box[ i ].send + box[ i ].get;
        }
        sort( box, box + n, cmp );
        for ( i = 0; i < n; i++ ) {
            printf( "%s %s\n", box[ i ].name, box[ i ].food );
        }
    }
    return 0;
}
