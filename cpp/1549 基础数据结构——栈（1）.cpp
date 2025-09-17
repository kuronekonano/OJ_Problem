#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    char a[ 109 ];
    int  i, n;
    while ( gets( a ) ) {
        stack< char > q;
        while ( !q.empty() ) {
            q.pop();
        }
        n         = strlen( a );
        bool flag = true;
        for ( i = 0; i < n; i++ ) {
            if ( a[ i ] == '{' || a[ i ] == '}' || a[ i ] == '(' || a[ i ] == ')' || a[ i ] == '[' || a[ i ] == ']' ) {
                if ( a[ i ] == '(' || a[ i ] == '[' || a[ i ] == '{' ) {
                    q.push( a[ i ] );
                    continue;
                }
                else if ( a[ i ] == ')' && !q.empty() && q.top() == '(' ) {
                    q.pop();
                }
                else if ( a[ i ] == ']' && !q.empty() && q.top() == '[' ) {
                    q.pop();
                }
                else if ( a[ i ] == '}' && !q.empty() && q.top() == '{' ) {
                    q.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        if ( !q.empty() || flag == false ) {
            printf( "no\n" );
        }
        else {
            printf( "yes\n" );
        }
    }
    return 0;
}
