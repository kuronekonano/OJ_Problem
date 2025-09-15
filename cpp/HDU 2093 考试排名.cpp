#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct student {
    char name[ 16 ];
    int  num;
    int  sum;
} stu[ 10 ];
bool cmp( student a, student b ) {
    if ( a.num == b.num ) {
        if ( a.sum == b.sum ) {
            return strcmp( a.name, b.name ) < 0;
        }
        return a.sum < b.sum;
    }
    return a.num > b.num;
}
int main() {
    int n, m, i, j, k;
    while ( scanf( "%d %d", &n, &m ) != EOF ) {
        for ( i = 0; i < 6; i++ )  /// 学生数量
        {
            stu[ i ].num = 0;
            stu[ i ].sum = 0;
            scanf( "%s", stu[ i ].name );
            for ( j = 0; j < n; j++ )  /// 题目数量
            {
                char a[ 10 ];
                scanf( "%s", a );
                //                printf("---%s\n",a);
                if ( a[ 0 ] == '0' || a[ 0 ] == '-' )
                    continue;
                stu[ i ].num++;
                int len  = strlen( a );
                int mark = 0;
                for ( k = 0; k < len; )  /// 分数
                {
                    if ( a[ k ] == '(' ) {
                        k++;
                        mark = 0;
                        while ( a[ k ] >= '0' && a[ k ] <= '9' ) {
                            mark = mark * 10 + a[ k ] - '0';
                            k++;
                        }
                        stu[ i ].sum = stu[ i ].sum + mark * m;
                        if ( a[ k ] == ')' )
                            break;
                    }
                    mark = 0;
                    while ( a[ k ] >= '0' && a[ k ] <= '9' && k < len ) {
                        mark = mark * 10 + a[ k ] - '0';
                        k++;
                    }
                    stu[ i ].sum = stu[ i ].sum + mark;
                    //                    printf("-----%d\n",stu[i].sum);
                }
            }
        }
        sort( stu, stu + 6, cmp );
        for ( i = 0; i < 6; i++ ) {
            printf( "%-10s %2d %4d\n", stu[ i ].name, stu[ i ].num, stu[ i ].sum );
        }
    }
}
/*
8 20
Smith	  -1 -16 8 0 0 120 39 0
John	  116 -2 11 0 0 82 55(1) 0
Josephus  72(3) 126 10 -3 0 47 21(2) -2
Bush	  0 -1 -8 0 0 0 0 0
Alice	  -2 67(2) 13 -1 0 133 79(1) -1
Bob	  0 0 57(5) 0 0 168 -7 0
*/
