#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct student {
  char name[15];
  int sum;
  int down;
} a[105];
bool cmp(student a, student b) {
  if (a.sum == b.sum)
    return strcmp(a.name, b.name) < 0;
  return a.sum > b.sum;
}
int main() {
  int t, i, n, len, j, num = 0;
  char b[30];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      a[i].down = 0; /// 卡了好久，说明在结构体里初始化是不行的
      scanf("%s", a[i].name);
      scanf("%s", b);
      for (j = 0; b[j] != '\0'; j++) {

        if (b[j] >= '0' && b[j] <= '9') {
          num = num * 10 + b[j] - '0';
        }
        if (b[j + 1] == '(' || b[j + 1] == '\0') {
          a[i].sum = num;
          num = 0;
        }
        if (b[j + 1] == ')') {
          a[i].down = num;
          num = 0;
          break;
        }
      }
      a[i].sum = a[i].sum - a[i].down;
    }
    sort(a, a + n, cmp);
    for (i = 0; i < n; i++) {
      printf("%-10s %5d\n", a[i].name, a[i].sum);
    }
  }
  return 0;
}

// #include<stdio.h>
// #include<string.h>
// #include<algorithm>
// using namespace std;
// struct student
//{
//     char name[15];
//     int sum;
// } a[105];
// bool cmp(student a,student b)
//{
//     if(a.sum==b.sum)
//         return (strcmp(a.name,b.name)<0);
//     return a.sum>b.sum;
// }
// int main()
//{
//     int t,i,n,len,j,num=0;
//     char b[60];
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d",&n);
//         for(i=0; i<n; i++)
//         {
//             scanf("%s",a[i].name);
//             scanf("%s",b);
//             for(j=0;b[j]!='\0';j++)
//             {
//
//                 if(b[j]>='0'&&b[j]<='9')
//                 {
//                     num=num*10+b[j]-'0';
//                 }
//                 if(b[j+1]=='('||b[j+1]=='\0')
//                 {
//                     a[i].sum=num;
//                     num=0;
//                 }
//                 if(b[j+1]==')')
//                 {
//                     a[i].sum-=num;
//                     num=0;
//                     break;
//                 }
//             }
//         }
//         sort(a,a+n,cmp);
//         for(i=0; i<n; i++)
//         {
//             printf("%-10s %5d\n",a[i].name,a[i].sum);
//         }
//     }
//     return 0;
// }

// #include<stdio.h>///超耐磨凭什么我的就过不了
// #include<string.h>
// #include<algorithm>
// using namespace std;
// struct student
//{
//     char name[15];
//     int sum;
//     int down=0;
// } a[105];
// bool cmp(student a,student b)
//{
//     if(a.sum==b.sum)
//         return (strcmp(a.name,b.name)<0);
//     return a.sum>b.sum;
// }
// int main()
//{
//     int t,i,n,len,j,num=0;
//     char b;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d",&n);
//         for(i=0; i<n; i++)
//         {
//             scanf("%s",a[i].name);
//             scanf("%d",&a[i].sum);
//             scanf("%c",&b);
//             if(b=='(')
//             {
//                 scanf("%d%c",&a[i].down,&b);
//                 a[i].sum=a[i].sum-a[i].down;
//             }
//         }
//         sort(a,a+n,cmp);
//         for(i=0; i<n; i++)
//         {
//             printf("%-10s %5d\n",a[i].name,a[i].sum);
//         }
//     }
//     return 0;
// }
