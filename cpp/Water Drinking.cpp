#include <stdio.h>
#include <string.h>
int main() {
    int i, n, a, b, first;
    int link[ 100008 ],
        head[ 100008 ];                 /// 骆驼排队喝水，那么最短的那排的最后一个编号是什么
    while ( scanf( "%d", &n ) != EOF )  /// 有n只骆驼
    {
        first = 0;                          /// 一开始有0个队伍
        memset( link, 0, sizeof( link ) );  /// 清空连接数组
        for ( i = 0; i < n; i++ ) {
            scanf( "%d%d", &a, &b );  /// 输入两两之间的关系
            if ( a == 0 )
                head[ first++ ] = b;  /// 当关系是与0相接时，说明是那一排的第一个，或是说，出现了新的一排，head根节点数组增加一位，表示多了一列队伍
            else
                link[ a ] = b;  /// 否则只是普通的两两之间连接关系(排队)
        }
        bool flag = true;                  /// 未找到队尾时标记为TRUE
        int  fin  = n;                     /// 这里的最后结果，初始化为总共有几只骆驼，那么最后那只骆驼的编号就是目前的最大值，要求的是最小值，此处只是为防止有相同长度的队伍情况
        while ( flag )                     /// 只要未找到就继续找
        {                                  /// 这个循环每次所有队伍只向后遍历一个骆驼，最短的队伍就是最先更新到队尾的队伍
            for ( i = 0; i < first; i++ )  /// 所有队列，共有first个队伍
            {
                if ( link[ head[ i ] ] == 0 )  /// 如果当前连接数组中，正在遍历的那个编号后面连接的是0，说明他是最后一个，他后面没有骆驼
                {
                    fin  = fin > head[ i ] ? head[ i ] : fin;  /// 更新最后结果的编号，找最小的
                    flag = false;                              /// 找到队尾
                }  /// 此时找到了所有队伍中其中一个最短的还不能break，还要继续遍历完所有队伍，后面可能有队伍一也达到队尾了
                head[ i ] = link[ head[ i ] ];  /// 更新head根节点记录的当前遍历的每一行的骆驼编号
            }
        }
        printf( "%d\n", fin );  /// 输出最后结果
    }
    return 0;
}
