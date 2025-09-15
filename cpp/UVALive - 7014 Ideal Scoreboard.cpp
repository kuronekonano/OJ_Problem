#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct prom {
    int  tt, hh, mm, ss;
    char pp[ 2 ], out[ 35 ];
} sss[ 5008 ];
bool cmp( prom a, prom b ) {
    if ( a.hh == b.hh ) {
        if ( a.mm == b.mm ) {
            return a.ss < b.ss;
        }
        return a.mm < b.mm;
    }
    return a.hh < b.hh;
}
int main() {
    int  t, p, s;
    int  team[ 160 ], pro[ 20 ];
    bool tp[ 160 ][ 20 ];
    while ( scanf( "%d%d%d", &t, &p, &s ) != EOF ) {
        if ( !t && !p && !s )
            return 0;
        memset( pro, 0, sizeof( pro ) );    /// 每个问题AC人数计数
        memset( team, 0, sizeof( team ) );  /// 每个队伍AC题目计数
        memset( tp, false, sizeof( tp ) );  /// 每人每题AC状态判断
        int  tmax = 0, pmax = 0, tmin = t, pmin = p;
        bool flag = false, flag2 = false;
        int  sth, stm, sts, eh, em, es;
        for ( int i = 0; i < s; i++ ) {
            scanf( "%d", &sss[ i ].tt );
            scanf( "%s", sss[ i ].pp );
            scanf( "%d:%d:%d", &sss[ i ].hh, &sss[ i ].mm, &sss[ i ].ss );
            gets( sss[ i ].out );
        }
        sort( sss, sss + s, cmp );  /// 给出的时间不一定按顺序，要排序后一一判断
        for ( int i = 0; i < s; i++ ) {
            if ( sss[ i ].out[ 1 ] == 'Y' ) {
                if ( !team[ sss[ i ].tt ] )
                    tmin--;  /// 是否所有队做出题
                if ( !pro[ sss[ i ].pp[ 0 ] - 'A' ] )
                    pmin--;                                          /// 是否所有题都被A
                if ( !tp[ sss[ i ].tt ][ sss[ i ].pp[ 0 ] - 'A' ] )  /// 已经A过的题可能又交了，这时是不能重复计数的
                {
                    team[ sss[ i ].tt ]++;            /// 每队几题
                    pro[ sss[ i ].pp[ 0 ] - 'A' ]++;  /// 每题几队
                    if ( pro[ sss[ i ].pp[ 0 ] - 'A' ] > pmax )
                        pmax = pro[ sss[ i ].pp[ 0 ] - 'A' ];  /// 防所有队做出某题
                    if ( team[ sss[ i ].tt ] > tmax )
                        tmax = team[ sss[ i ].tt ];  /// 防AK
                }
                tp[ sss[ i ].tt ][ sss[ i ].pp[ 0 ] - 'A' ] = true;
            }
            //            printf("-------> pmax=%d tmax=%d pmin=%d
            //            tmin=%d\n",pmax,tmax,pmin,tmin);
            if ( !flag && tmin == 0 && pmin == 0 && pmax != t && tmax != p )  /// 判断是否符合开始时间
            {
                sth = sss[ i ].hh, stm = sss[ i ].mm,
                sts  = sss[ i ].ss;  /// pmax作为完成人数最多的题目计数，当有t人写完某题时，说明这题被所有人写出来
                flag = true;         /// tmax作为写完题目最多的队，当有p题被写完时，说明有人AK
            }
            if ( flag && ( pmax == t || tmax == p ) && !flag2 )  /// 判断完美状态是否被破坏,因为pmin和tmin一旦达到完美，就不可能被破坏，一直以存在，因此不用考虑
            {
                eh = sss[ i ].hh, em = sss[ i ].mm, es = sss[ i ].ss;
                flag2 = true;
            }
        }
        if ( flag )  /// 开始完美时间点
        {
            printf( "%02d:%02d:%02d", sth, stm, sts );
        }
        if ( flag2 )  /// 结束完美时间点
        {
            printf( " %02d:%02d:%02d\n", eh, em, es );
        }
        if ( !flag )  /// 没有开始时间必没有结束时间
        {
            printf( "--:--:-- --:--:--\n" );
        }
        if ( !flag2 && flag )  /// 开始时间知道结束，没有结束时间点
        {
            printf( " --:--:--\n" );
        }
    }
}
