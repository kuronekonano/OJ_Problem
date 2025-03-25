#include <stdio.h>
#include <string.h>
int main() {
  char a[45][45], b[105];
  int x, y, i, j;
  while (scanf("%d%d", &x, &y) != EOF) {
    memset(a, ' ', sizeof(a));
    scanf("%s", b);
    int n = strlen(b);
    int k = 0;
    bool flag = false;
    if (y < 0)
      y = 0;
    if (x < 0)
      x = 0;
    for (i = y; i < 30; i++) {
      for (j = 0; j < 40; j++) {
        if (i == y) {
          if (k == 0) {
            j = x;
          }
          a[i][j] = b[k];
          if (k == n - 1) {
            flag = true;
            break;
          }
          k++;
        }
      }
      if (flag) {
        break;
      }
    }
    for (i = 0; i < 30; i++) {
      for (j = 0; j < 40; j++) {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}

// #include<stdio.h>
// #include<string.h>
// int main()
//{
//     char a[45][45],b[105];
//     int x,y,i,j;
//     while(scanf("%d%d",&x,&y)!=EOF)
//     {
//         memset(a,' ',sizeof(a));
//         scanf("%s",b);
//         int n=strlen(b);
//         int k=0;
//         bool flag=false;
//         if(y<0)y=0;
//         if(x<0)x=0;
//         for(i=y; i<30; i++)
//         {
//             for(j=0; j<40; j++)
//             {
//                 if(k==0)
//                 {
//                     j=x;
//                 }
//                 a[i][j]=b[k];
//                 if(k==n-1)
//                 {
//                     flag=true;
//                     break;
//                 }
//                 k++;
//             }
//             if(flag)
//             {
//                 break;
//             }
//         }
//         int s=0;
//         for(i=0; i<30; i++)
//         {
//             for(j=0; j<40; j++)
//             {
//                 printf("%c",a[i][j]);
//             }
//             printf("%d\n",s++);
//         }
//         printf("=================\n");
//     }
//     return 0;
// }
