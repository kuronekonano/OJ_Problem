#include <stdio.h> ///并查集优化子串查找
#include <string.h>
int z[508];
char a[508][2008];
int find(int x) {
  int r = x, k;
  while (z[r] != r) {
    k = r;
    r = z[r];
    z[k] = z[r];
  }
  return r;
}
void join(int x, int y) {
  int aa = find(x), bb = find(y);
  if (aa != bb) {
    if (strlen(a[x]) < strlen(a[y])) {
      z[x] = y;
    } else
      z[y] = x;
  }
}
int main() {
  int t, i, j, n, cas = 0;
  scanf("%d", &t);
  while (t--) {
    cas++;
    int ans = -1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
      z[i] = i;
    for (i = 1; i <= n; i++) {
      scanf("%s", a[i]);
      bool flag = false;
      for (j = i - 1; j >= 1; j--) {
        if (find(i) == find(j))
          continue;
        if (strstr(a[i], a[j]) == NULL) {
          flag = true;
          break;
        } else
          join(i, j);
      }
      if (flag)
        ans = i;
    }
    printf("Case #%d: %d\n", cas, ans);
  }
}
// #include<stdio.h>
// #include<string.h>
// int next[508][2008];
// char a[508][2008];
// int z[508];
// int finds(int x)
//{
//     int r=x,k;
//     while(r!=z[r])
//     {
//         k=r;
//         r=z[r];
//         z[k]=z[r];
//     }
//     return r;
// }
// void join(int x,int y)
//{
//     int aa=finds(x),bb=finds(y);
//     if(aa!=bb)
//     {
//         if(strlen(a[x])<strlen(a[y]))
//         {
//             z[x]=y;
//         }
//         else
//         {
//             z[y]=x;
//         }
//     }
// }
// void getnext(char b[],int lenb,int num)
//{
//     for(int i=1; i<lenb; i++)
//     {
//         int j=next[num][i];
//         while(j&&b[i]!=b[j])
//         {
//             j=next[num][j];
//         }
//         next[num][i+1]=(b[i]==b[j])?(j+1):0;
//     }
// }
// bool kmp(int lena,int lenb,char a[],char b[],int num)
//{
//     int j=0;
//     for(int i=0; i<lena; i++)
//     {
//         while(j&&a[i]!=b[j])
//         {
//             j=next[num][j];
//         }
//         if(a[i]==b[j])
//         {
//             j++;
//         }
//         if(j>=lenb)
//         {
//             return true;
//         }
//     }
//     return false;
// }
// int main()
//{
//     int t,n;
//     int i,j,cas=0;;
//     scanf("%d",&t);
//     while(t--)
//     {
//         memset(next,0,sizeof(next));
//         cas++;
//         int ans=-1;
//         scanf("%d",&n);
//         for(i=1;i<=n;i++)z[i]=i;///初始化并查集
//         scanf("%s",&a[1]);
//         getnext(a[1],strlen(a[1]),1);
//         for(i=2; i<=n; i++)
//         {
//             scanf("%s",&a[i]);
//             int len=strlen(a[i]);
//             getnext(a[i],len,i);
//             bool flag=false;
//             for(int j=i-1;j>0;j--){
//                 if(finds(i)==finds(j))
//                     continue;
//                 int lenj=strlen(a[j]);
//                 if(kmp(len,lenj,a[i],a[j],j)==false)
//                 {
//                     flag=true;
//                     break;
//                 }
//                 else join(i,j);
//             }
//             if(flag==true)ans=i;
//         }
//         printf("Case #%d: %d\n",cas,ans);
//     }
// }
