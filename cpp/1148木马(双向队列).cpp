#include <stdio.h>  ///正常的方法
#include <string.h>
int main() {
    char a[ 100009 ];
    while ( gets( a ) != NULL ) {
        int n;
        scanf( "%d", &n );
        getchar();  /// 记得接住那个n的回车，否则下一轮GG
        int flag = strlen( a );
        n        = n % flag;
        for ( int i = flag - n; i < flag; i++ ) {
            putchar( a[ i ] );
        }
        for ( int i = 0; i < flag - n; i++ ) {
            putchar( a[ i ] );
        }
        puts( "" );  /// puts()换行方法
    }
    return 0;
}
// #include<stdio.h>
// #include<queue>///单项队列
// #include<string.h>
// #include<deque>//双向队列
// using namespace std;//木马逆时针转圈
// int main()
//{
//     queue<char>q;//由上次的转圈自杀的问题，可以得出用队列完成循环
//     int n,i;
//     char a[100005];
//     while(scanf("%s",a)!=EOF)
//     {
//         while(!q.empty())//清空队列
//         {
//             q.pop();
//         }
//         n=strlen(a);
//         for(i=n-1;i>=0;i--)//入列
//         {
//             q.push(a[i]);
//         }
//         int t;
//         char flag;
//         scanf("%d",&t);
//         int
//         m=t%n;///因为非常大的变换次数，注意很多情况下旋转的次数与总数成倍数时，是等效的，因此必须要求余实现简化，否则会超时
//         if(t%n==0)
//         {
//             m=n;
//         }
//         for(i=1;i<=m;i++)
//         {
//             flag=q.front();//旋转
//             q.pop();
//             q.push(flag);
//             //q.push(q.front());//更为简略的旋转，不需要中间变量
//             //q.pop();
//         }
//         i=0;
//         while(!q.empty())//不能用for的出队列，因为要弹射到空栈为止
//         {
//             a[i]=q.front();//为完成逆序的输出，这里因为不是双向队列，所以单向出来的顺序刚好相反
//             i++;//实现正常顺序，只有通过放入数组中逆序输出
//             q.pop();
//         }
//         int j;
//         for(j=i-1;j>=0;j--)
//         {
//             printf("%c",a[j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }
// #include<stdio.h>///双向队列
// #include<deque>
// #include<string.h>
// using namespace std;
// int main()
//{
//     deque<char>q;
//     char a[100005];
//     int i;
//     while(scanf("%s",a)!=EOF)
//     {
//         while(!q.empty())
//         {
//             q.pop_back();
//         }
//         int n=strlen(a);
//         for(i=n-1; i>=0; i--)
//         {
//             q.push_front(a[i]);
//         }
//         int flag;
//         scanf("%d",&flag);
//         int t=flag%n;
//         if(flag%n==0)
//         {
//             t=n;
//         }
//         for(i=1;i<=t;i++)
//         {
//             q.push_front(q.back());
//             q.pop_back();
//         }
//         while(!q.empty())
//         {
//             printf("%c",q.front());
//             q.pop_front();
//         }
//         printf("\n");
//     }
//     return 0;
// }
