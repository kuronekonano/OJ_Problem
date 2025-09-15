// #include<stdio.h>
// #include<string.h>
// #include<queue>
// using namespace std;
// bool vis[2002][2002];
// int walkx[]= {1,2,1,2,-1,-2,-1,-2};
// int walky[]= {-2,-1,2,1,2,1,-2,-1};
// struct point
//{
//     int x,y,num;
// };
// int main()
//{
//     queue<point>q;
//     int llst=0;
//     int last=0;
//     for(int i=0; i<=10; i++)
//     {
//         int n=i;
//         memset(vis,false,sizeof(vis));
//         while(!q.empty())q.pop();
//         point st;
//         st.x=1000;
//         st.y=1000;
//         st.num=0;
//         vis[st.x][st.y]=true;
//         int sum=0;
//         q.push(st);
//         while(!q.empty())
//         {
//             point top=q.front();
//             q.pop();
//             sum++;
//             for(int i=0; i<8; i++)
//             {
//                 point tmp;
//                 tmp.x=top.x+walkx[i];
//                 tmp.y=top.y+walky[i];
//                 tmp.num=top.num+1;
//                 if(tmp.x>=0&&tmp.x<2000&&tmp.y<2000&&tmp.x>=0&&!vis[tmp.x][tmp.y]&&tmp.num<=n)
//                 {
//                     vis[tmp.x][tmp.y]=true;
//                     q.push(tmp);
//                 }
//             }
//         }
////        for(int k=0; k<=100; k++)
////        {
////            for(int j=0; j<=100; j++)
////                printf("%d",vis[k][j]);
////            printf("\n");
////        }
//        printf("%d------->%d-------->%d-------->%d\n",i,sum,sum-last,sum-last-llst);
//        llst=sum-last;
//        last=sum;
////        printf("======%d\n",llst);
//    }
//
//}
#include <stdio.h>
#define ULL unsigned long long
int main() {
    ULL n, t;
    ULL a[] = { 1, 9, 41, 109, 205 };
    scanf( "%llu", &t );
    while ( t-- ) {
        scanf( "%llu", &n );
        if ( n < 5 ) {
            printf( "%llu\n", a[ n ] );
            continue;
        }
        else {
            n -= 4;
            ULL ans = ( 240 + 28 * n ) / 2 * ( n - 1 ) + 325;
            printf( "%llu\n", ans );
        }
    }
}
/*
0------->1-------->1-------->1
1------->9-------->8-------->7
2------->41-------->32-------->24
3------->109-------->68-------->36
4------->205-------->96-------->28
5------->325-------->120-------->24
6------->473-------->148-------->28
7------->649-------->176-------->28
8------->853-------->204-------->28
9------->1085-------->232-------->28
10------->1345-------->260-------->28
*/
