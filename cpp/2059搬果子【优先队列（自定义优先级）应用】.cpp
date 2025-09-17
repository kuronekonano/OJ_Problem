#include <queue>    ///用了vector容器竟然不需要他的头文件？
#include <stdio.h>  ///优先队列例
using namespace std;
int main() {
    int a, i, n;
    while ( scanf( "%d", &n ) != EOF )  /// 注意，如果下方最右边使用了>>会报错，不能粘起来，要用空格分开
    {
        priority_queue< int, vector< int >, greater< int > > q;  /// 优先队列自定义优先级，原优先级是从大到小，数值越大优先级越大
        for ( i = 0; i < n; i++ )                                /// 这里用greater是从小到大的优先级，less是从大到小
        {
            scanf( "%d", &a );
            q.push( a );  /// 入列
        }
        int sum = 0, small, smaller;  /// 优先队列，优先级高的先出队列
        while ( q.size() > 1 )        /// 模拟搬果子过程
        {
            small = q.top();            /// 选取队列中最小的
            q.pop();                    /// 出列
            smaller = small + q.top();  /// 选取出列后最小的，相加，相当于两个最小的合成一堆
            q.pop();                    /// 已经合成的两堆出列
            sum = sum + smaller;
            q.push( smaller );  /// 新的一堆入列，并重新找整个队列中最小的,避免了合成一堆后出现比单独一堆更大的情况
        }
        printf( "%d\n", sum );
    }
    return 0;
}
