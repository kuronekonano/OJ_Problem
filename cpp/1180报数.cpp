#include <iostream>
#include <queue>
#include <stdio.h>  //用不了printf和scanf，并且无法用二维字符数组入队列，不知道为啥
using namespace std;
int main() {
    queue< string > q;  // 队列
    int             n, m, d;
    string          a[ 108 ];           // 二维数组，string型一维不需要设定长度，二维设定的是有多少个这样的字符串
    while ( scanf( "%d", &n ) != EOF )  // 人数
    {
        while ( !q.empty() ) {
            q.pop();
        }
        for ( int i = 1; i <= n; i++ ) {
            cin >> a[ i ];
            q.push( a[ i ] );  // 进队列
        }
        scanf( "%d,%d", &m, &d );      // 从第m个人开始,每个数到d的人出列
        for ( int i = 1; i < m; i++ )  // 找到第m个人，因此要开始旋转，把队首调整到m个人
        {
            q.push( q.front() );  // 简化无中间变量的旋转
            q.pop();
        }
        while ( !q.empty() )  // 当不为空时继续游戏
        {
            for ( int i = 1; i < d; i++ )  // 旋转次数小于d，因为第d个人是出列的
            {
                q.push( q.front() );  // 不需要中间变量直接完成转圈变换
                q.pop();
            }
            cout << q.front() << endl;  // 输出的是出列的顺序，每一次的第d个人
            q.pop();                    // 输出后弹出最后的胜者
        }
    }
    return 0;
}
