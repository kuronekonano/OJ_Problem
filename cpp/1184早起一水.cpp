#include <algorithm>  //贪心，找最优解
#include <stdio.h>
using namespace std;
struct water  // 定义结构体，每个人的编号与接水时间打包匹配
{
    int id;
    int time;
} man[ 100005 ];
bool cmp( water a, water b )  // 若时间相同，谁编号靠前谁排前面
{
    if ( a.time == b.time ) {
        return a.id < b.id;
    }
    return a.time < b.time;
}
int main() {
    int n, i;
    while ( scanf( "%d", &n ) != EOF )  // n个人
    {
        for ( i = 0; i < n; i++ )  // 每人的接水时间
        {
            scanf( "%d", &man[ i ].time );
            man[ i ].id = i + 1;  // 编号，因为要sort所以从0开始赋值，又因为编号无0，因此每个人的编号是数组位置加1
        }
        sort( man, man + n, cmp );  // 结构体sort排序，目的是让需要时间少的人先接水
        long long waitsum = 0;      // 每个人等待时长总和
        long long first   = 0;      // 第i个人等待的时长
        for ( i = 0; i < n; i++ )   // 因为是每个人的平均最短时长，因此每人的等待时长是前面所有人的时长之和
        {
            waitsum = waitsum + first;                                   // 第一个人，也就是正在接水的人等待的时长，加入到最终总和中
            first   = first + man[ i ].time;                             // 每个人等待的时长，相当于前面的前面的人的时长加上前面的人的时长
            printf( "%d%c", man[ i ].id, ( i == n - 1 ) ? '\n' : ' ' );  // 输出排序后序列
        }
        printf( "%.2f\n",
                waitsum * 1.00 / n );  // 因为是long long
                                       // 型的，要保留两位小小数无法强制转换，这里可以除1.00，再求平均值
    }
    return 0;
}
