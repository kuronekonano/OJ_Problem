#include <stdio.h> ///�����ķ���
#include <string.h>
int main() {
  char a[100009];
  while (gets(a) != NULL) {
    int n;
    scanf("%d", &n);
    getchar(); /// �ǵý�ס�Ǹ�n�Ļس���������һ��GG
    int flag = strlen(a);
    n = n % flag;
    for (int i = flag - n; i < flag; i++) {
      putchar(a[i]);
    }
    for (int i = 0; i < flag - n; i++) {
      putchar(a[i]);
    }
    puts(""); /// puts()���з���
  }
  return 0;
}
// #include<stdio.h>
// #include<queue>///�������
// #include<string.h>
// #include<deque>//˫�����
// using namespace std;//ľ����ʱ��תȦ
// int main()
//{
//     queue<char>q;//���ϴε�תȦ��ɱ�����⣬���Եó��ö������ѭ��
//     int n,i;
//     char a[100005];
//     while(scanf("%s",a)!=EOF)
//     {
//         while(!q.empty())//��ն���
//         {
//             q.pop();
//         }
//         n=strlen(a);
//         for(i=n-1;i>=0;i--)//����
//         {
//             q.push(a[i]);
//         }
//         int t;
//         char flag;
//         scanf("%d",&t);
//         int
//         m=t%n;///��Ϊ�ǳ���ı任������ע��ܶ��������ת�Ĵ����������ɱ���ʱ���ǵ�Ч�ģ���˱���Ҫ����ʵ�ּ򻯣�����ᳬʱ
//         if(t%n==0)
//         {
//             m=n;
//         }
//         for(i=1;i<=m;i++)
//         {
//             flag=q.front();//��ת
//             q.pop();
//             q.push(flag);
//             //q.push(q.front());//��Ϊ���Ե���ת������Ҫ�м����
//             //q.pop();
//         }
//         i=0;
//         while(!q.empty())//������for�ĳ����У���ΪҪ���䵽��ջΪֹ
//         {
//             a[i]=q.front();//Ϊ�������������������Ϊ����˫����У����Ե��������˳��պ��෴
//             i++;//ʵ������˳��ֻ��ͨ�������������������
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
// #include<stdio.h>///˫�����
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
