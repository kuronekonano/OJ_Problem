#include <iostream>
#include <stdio.h> ///string.find()����Ӧ��
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
        maxi = i;           /// ���λ��
        maxn = v[i].size(); /// �������
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
      if (v[maxi].find(v[i]) != string::npos)
        sum++; /// string��find����Ӧ�ã��ж�v[i]�Ƿ���v[maxi]���Ӵ����Ƿ��ص�ַ�����򷵻�string::npos
    if (sum == n)
      cout << v[maxi] << endl;
    else
      cout << "No" << endl;
  }
}
// #include <stdio.h>
// #include <string.h>
// char S[1200010];///���ַ�������
// char
// *t[1100010],*s;///ÿ���ַ��������ַ���s�е�λ�ã���*t��ʾ����Ϊ��Ŷ�ܶ���ַ���������������ʾÿһ���ַ�����λ�ã��൱��ģ���˶�ά���飬ֻ����ÿ�����ֳ��ȿɱ�
// int main()
//{
//     int T,n;
//     scanf("%d",&T);
//     while(T--)
//     {
//         scanf("%d",&n);
//         int maxlen=0;
//         int p=1;//��¼���
//         s=S;///ָ��ӳ��������������(�׵�ַ)��ʼ��ŵ�һ����
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%s",s);///���ַ������룬��s����һ�ξ��뽫������ַ���ռ��
//             t[i]=s;///��¼��i���ַ�����S�ܴ��еĿ�ʼλ�ã�Ҳ���Ǹ��ַ�����ͷָ��
//             if(strlen(s)>maxlen){
//                 maxlen=strlen(s);
//                 p=i;
//             }
//             s+=strlen(s)+2;///ָ������ƶ���Ϊ��ֹ�ַ����غϣ�Ӧ��һ�ξ����ٿ�ʼ�洢��һ���ַ���
//         }
//         int ans=0;
//         for(int i=1;i<=n;i++)///��������ͷָ�룬Ҳ���������ַ�����ʼ��λ��
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
