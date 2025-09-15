#include <stdio.h>
int num = 0, a[ 108 ], n, b[ 108 ], c[ 108 ];
int find( int tmp, int l, int r ) {
    for ( int i = l; i < r; i++ )
        if ( a[ i ] == tmp )
            return i;
}
int halfpath( int bl, int br, int al, int ar ) {
    // 拿出前序遍历的元素到中序遍历中查询位置
    if ( al == ar )
        return 0;
    int root = find( b[ bl ], al, ar );              // 找出前序遍历中第bl个元素在中序遍历序列中的位置
    int len  = root - al;                            // 中序遍历中第bl个元素的位序差
    halfpath( bl + 1, bl + 1 + len, al, al + len );  // 左子树
    halfpath( bl + 1 + len, br, al + len + 1, ar );  // 右子树
    c[ num++ ] = a[ root ];
}
int main() {
    while ( scanf( "%d", &n ) != EOF ) {
        num = 0;
        for ( int i = 0; i < n; i++ )
            scanf( "%d", &a[ i ] );  // 中序遍历
        for ( int i = 0; i < n; i++ )
            scanf( "%d", &b[ i ] );  // 前序遍历
        halfpath( 0, n, 0, n );
        for ( int i = 0; i < n; i++ )
            printf( "%d ", c[ i ] );
        printf( "\n" );
    }
}
