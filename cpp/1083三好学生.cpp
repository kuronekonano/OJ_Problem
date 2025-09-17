#include <stdio.h>
using namespace std;

int main() {
    int t, n, m, i, j, mark, flag1, flag2;
    scanf( "%d", &t );  // 有T组数据
    while ( t-- ) {
        scanf( "%d%d", &n, &m );    // 输入学生数量和课程数量
        flag2 = 0;                  // 初始化三好学生数量计数器
        for ( i = 1; i <= n; i++ )  // 输入每个学生的分数
        {
            flag1 = 0;                  // 初始化高于80分科目计数器
            for ( j = 1; j <= m; j++ )  // 输入的课程数
            {
                scanf( "%d", &mark );  // 输入学生分数
                if ( mark > 80 ) {
                    flag1++;
                }
            }
            if ( flag1 > 3 )  // 若达到3门课程优秀则三好学生计数器增加
            {
                flag2++;
            }
        }
        printf( "%d\n", flag2 );
    }
    return 0;
}
