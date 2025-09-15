#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;

char dm[ 10005 ][ 10005 ];  // 定义两个栈用于存储括号（和{,定义字符串二维数组，相当于有10000个长10000的字符串
int  main() {
    int i, j, b;
    while ( scanf( "%s", dm[ 0 ] ) != EOF )  // 输入字符串，第0个长10000的字符串,第一行字符串不等于Ctrl+Z，原因是待输入完后回车，再输入Ctrl+Z才开始判断是否结束输入
    {
        i = 0;
        while ( 1 )  // while为真时继续循环
        {
            i++;                                     // a[i]自增，相当于输入到第i个长10000的字符串中
            scanf( "%s", dm[ i ] );                  // 输入到第i个长10000的字符串中
            if ( strcmp( dm[ i ], "Ctrl+Z" ) == 0 )  // 对比第i条字符串，当等于Ctrl+Z时结束输入
            {
                break;
            }
        }
        bool          gg = false;
        stack< char > s;  // 声明存放char类型的stack容器,s[2]表示建立了两个char型的栈，其中s[0]表示第一个栈
        while ( !s.empty() )
            s.pop();
        for ( j = 0; j < i; j++ )  // 遍历，到上面输入的第i行字符串为止
        {
            for ( b = 0; dm[ j ][ b ] != '\0'; b++ )  // 遍历第j行字符串中的第b个字符，直到发现结束输入的\0指示符
            {
                if ( dm[ j ][ b ] == '(' || dm[ j ][ b ] == ')' || dm[ j ][ b ] == '{' || dm[ j ][ b ] == '}' ) {
                    if ( dm[ j ][ b ] == '{' ) {
                        s.push( '{' );  // 若发现左花括号
                        continue;
                    }
                    else if ( dm[ j ][ b ] == '(' ) {
                        s.push( '(' );  // 放入第二个栈中以分类，进栈
                        continue;
                    }
                    else if ( dm[ j ][ b ] == '}' && !s.empty() && s.top() == '{' ) {
                        s.pop();  // 从第一个栈中出栈
                        continue;
                    }
                    else if ( dm[ j ][ b ] == ')' && !s.empty() && s.top() == '(' )  // 当发现一个右括号，且第一个栈不为空栈
                    {
                        s.pop();
                        continue;
                    }
                    else
                        gg = true;  // 失败计数变成1
                }
            }
        }
        if ( gg == false )  // 若失败计数为零
        {
            if ( s.empty() )  // 检查两个栈是否为空栈，若为空栈，则匹配成功（为防止有左括号入栈却无右括号出栈的情况）
            {
                printf( "Right\n" );
            }
            else {
                printf( "Wrong\n" );  // 否则匹配失败
            }
        }
        else {
            printf( "Wrong\n" );  // 若之前就有失败计数，则直接为匹配失败
        }
    }
    return 0;
}

// #include<stdio.h>
// #include<stack>
// #include<string.h>
// using namespace std;
//
// char
// dm[10005][10005];//定义两个栈用于存储括号（和{,定义字符串二维数组，相当于有10000个长10000的字符串
// int main()
//{
//     int i,j,gg,b;
//     while(scanf("%s",dm[0])!=EOF)//输入字符串，第0个长10000的字符串,第一行字符串不等于Ctrl+Z，原因是待输入完后回车，再输入Ctrl+Z才开始判断是否结束输入
//     {
//         i=0;
//         while(1)//while为真时继续循环
//         {
//             i++;//a[i]自增，相当于输入到第i个长10000的字符串中
//             scanf("%s",dm[i]);//输入到第i个长10000的字符串中
//             if(strcmp(dm[i],"Ctrl+Z")==0)//对比第i条字符串，当等于Ctrl+Z时结束输入
//             {
//                 break;
//             }
//         }
//         gg=0;
//         stack<char>s[2];//这是参数化模板，声明存放char类型的stack容器,s[2]表示建立了两个char型的栈，其中s[0]表示第一个栈
//         for(j=0;j<i;j++)//遍历，到上面输入的第i行字符串为止
//         {
//             for(b=0;dm[j][b]!='\0';b++)//遍历第j行字符串中的第b个字符，直到发现结束输入的\0指示符
//             {
//                 if(dm[j][b]=='{')
//                 {
//                     s[0].push(dm[j][b]);//若发现左花括号
//                     continue;
//                 }
//                 if(dm[j][b]=='(')
//                 {
//                     s[1].push(dm[j][b]);//放入第二个栈中以分类，进栈
//                     continue;
//                 }
//                 if(dm[j][b]=='}'&&s[0].size()!=0)
//                 {
//                     s[0].pop();//从第一个栈中出栈
//                     continue;
//                 }
//                 if(dm[j][b]==')'&&s[1].size()!=0)//当发现一个右括号，且第一个栈不为空栈
//                 {
//                     s[1].pop();
//                     continue;
//                 }
//                 if(dm[j][b]==')'&&s[1].size()==0)//若等于空栈
//                 {
//                     gg=1;//失败计数变成1
//                     continue;
//                 }
//                 if(dm[j][b]=='}'&&s[0].size()==0)//第二个记录花括号的栈同理
//                 {
//                     gg=1;
//                     continue;
//                 }
//             }
//         }
//         if(gg==0)//若失败计数为零
//             {
//                 if(s[0].size()==0&&s[1].size()==0)//检查两个栈是否为空栈，若为空栈，则匹配成功（为防止有左括号入栈却无右括号出栈的情况）
//                 {
//                     printf("Right\n");
//                 }
//                 else
//                 {
//                     printf("Wrong\n");//否则匹配失败
//                 }
//             }
//             else
//             {
//                 printf("Wrong\n");//若之前就有失败计数，则直接为匹配失败
//             }
//     }
//     return 0;
// }
