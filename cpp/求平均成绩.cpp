#include <stdio.h>
int main() {
    int    i, j, n, m, flag, good;
    double add, sum, stu[ 58 ][ 8 ], mark1[ 58 ], mark2[ 8 ];
    while ( scanf( "%d%d", &n, &m ) != EOF ) {
        for ( i = 1; i <= n; i++ ) {
            for ( j = 1; j <= m; j++ ) {
                scanf( "%lf", &stu[ i ][ j ] );  // 输入每个学生每门课程分数
            }
        }
        for ( i = 1; i <= n; i++ ) {
            sum = 0;
            for ( j = 1; j <= m; j++ ) {
                sum = sum + stu[ i ][ j ];  // 每个学生总分
            }
            mark1[ i ] = sum / m;  // 每个学生平均分
        }
        for ( j = 1; j <= m; j++ ) {
            add = 0;
            for ( i = 1; i <= n; i++ ) {
                add = add + stu[ i ][ j ];  // 每门课程全部总分
            }
            mark2[ j ] = add / n;  // 每门课程平均分
        }
        good = 0;
        for ( i = 1; i <= n; i++ ) {
            flag = 0;
            for ( j = 1; j <= m; j++ ) {
                if ( stu[ i ][ j ] >= mark2[ j ] )  // 遍历所有学生所有成绩，并与对应平均每科成绩比较
                    flag++;                         // 若成绩大于或等于平均成绩则计数
            }
            good = good + flag / m;  // 优秀学生数量，将计数器除以课程数，若每科都优秀，则结果为1，,并计入好学生总数中，
        }
        for ( i = 1; i <= n; i++ ) {
            if ( i == 1 ) {
                printf( "%.2f", mark1[ i ] );  // 输出每个学生平均成绩
            }
            else {
                printf( " %.2f", mark1[ i ] );
            }
        }
        printf( "\n" );
        for ( i = 1; i <= m; i++ )  // 输出每门课程平均成绩
        {
            if ( i == 1 ) {
                printf( "%.2f", mark2[ i ] );
            }
            else {
                printf( " %.2f", mark2[ i ] );
            }
        }
        printf( "\n" );
        printf( "%d\n\n", good );
    }
    return 0;
}
