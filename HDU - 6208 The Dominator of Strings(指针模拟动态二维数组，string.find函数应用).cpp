#include <iostream>
#include <stdio.h> ///string.find()函数应用
#include <string>
using namespace std;
int main() {
  string v[100008];
  int t, n;
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    int maxn = 0, maxi = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i].size() > maxn) {
        maxi = i;           /// 最长串位置
        maxn = v[i].size(); /// 最长串长度
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
      if (v[maxi].find(v[i]) != string::npos)
        sum++; /// string中find函数应用，判断v[i]是否是v[maxi]的子串，是返回地址，否则返回string::npos
    if (sum == n)
      cout << v[maxi] << endl;
    else
      cout << "No" << endl;
  }
}
// #include <stdio.h>
// #include <string.h>
// char S[1200010];///总字符串长度
// char
// *t[1100010],*s;///每个字符串在总字符串s中的位置，用*t表示，因为有哦很多个字符串，因此用数组表示每一个字符串的位置，相当于模拟了二维数组，只不过每个数字长度可变
// int main()
//{
//     int T,n;
//     scanf("%d",&T);
//     while(T--)
//     {
//         scanf("%d",&n);
//         int maxlen=0;
//         int p=1;//记录最长串
//         s=S;///指针从超长数组的数组名(首地址)开始存放第一个串
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%s",s);///新字符串输入，从s往后一段距离将是这个字符串占用
//             t[i]=s;///记录第i个字符串在S总串中的开始位置，也是那个字符串的头指针
//             if(strlen(s)>maxlen){
//                 maxlen=strlen(s);
//                 p=i;
//             }
//             s+=strlen(s)+2;///指针向后移动，为防止字符串重合，应隔一段距离再开始存储下一个字符串
//         }
//         int ans=0;
//         for(int i=1;i<=n;i++)///遍历所有头指针，也就是所有字符串开始的位置
//         {
//             if(strstr(t[p],t[i])!=NULL)
//                 ans++;
//             else break;
//         }
//         if(ans==n)
//         {
//             printf("%s\n",t[p]);
//         }
//         else puts("No");
//     }
//     return 0;
// }
