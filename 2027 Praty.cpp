#include <iterator>
#include <map>
#include <stdio.h> ///map find����СӦ��
#include <string.h>
using namespace std;
int main() {
  map<string, bool> q;
  char str[105];
  while (scanf("%s", str) != EOF) {
    if (strcmp(str, "END") == 0) {
      break;
    }
    q[str] = true;
  }
  while (scanf("%s", str) != EOF) {
    if (strcmp(str, "END") == 0) {
      return 0;
    }
    map<string, bool>::iterator that = q.find(str); /// find����ʹ�ã�����������
    if (that ==
        q.end()) /// �Ƚϣ����find�ķ���ֵ������map��end����˵�����ҵ��ˣ�����˵��δ���ҵ�
    {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }
  return 0;
}

// #include<stdio.h>
// #include<string.h>
// int tree[150000][26];
// bool vis[150000];
// int tot;
// int insert(char *str,int rt)
//{
//     for(int i=0; str[i]; i++)
//     {
//         int x=str[i]-'a';
//         if(tree[rt][x]==0)
//         {
//             tree[rt][x]=++tot;
//         }
//         rt=tree[rt][x];
//     }
//     vis[rt]=true;
// }
// bool find(char *str,int rt)
//{
//     for(int i=0; str[i]; i++)
//     {
//         int x=str[i]-'a';
//         if(tree[rt][x]==0)
//         {
//             return false;
//         }
//         rt=tree[rt][x];
//     }
//     return vis[rt];
// }
// int main()
//{
//     tot=0;
//     int rt=++tot;
//     char str1[106];
//     memset(tree[rt],0,sizeof(tree[rt]));
//     while(scanf("%s",str1)!=EOF)
//     {
//         if(strcmp(str1,"END")==0)
//         {
//             break;
//         }
//         insert(str1,rt);
//     }
//     while(scanf("%s",str1)!=EOF)
//     {
//         if(strcmp(str1,"END")==0)
//         {
//             return 0;
//         }
//         if(find(str1,rt))
//         {
//             printf("Yes\n");
//         }
//         else
//         {
//             printf("No\n");
//         }
//     }
//     return 0;
// }
