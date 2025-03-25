// #include<stdio.h>//1167
// int main()
//{
//     int wu,yi,wf,ef,yf;
//     int lq;
//     while(scanf("%d",&lq)!=EOF)
//     {
//         wu=lq/50;
//         lq=lq%50;
//         yi=lq/10;
//         lq=lq%10;
//         wf=lq/5;
//         lq=lq%5;
//         ef=lq/2;
//         lq=lq%2;
//         yf=lq/1;
//
//         printf("1. %d\n2. %d\n3. %d\n4. %d\n5. %d\n",wu,yi,wf,ef,yf);
//     }
//     return 0;
// }
#include <stdio.h>
int main() {
  int i, n, t, a[100005];
  int hun, fif, tw, ten, fir, one;
  while (scanf("%d", &n) != EOF) {
    hun = 0;
    fif = 0;
    tw = 0;
    ten = 0;
    fir = 0;
    one = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++) // 不断求模的过程
    {
      hun = hun + a[i] / 100;
      a[i] = a[i] % 100;
      fif = fif + a[i] / 50;
      a[i] = a[i] % 50;
      tw = tw + a[i] / 20;
      a[i] = a[i] % 20;
      ten = ten + a[i] / 10;
      a[i] = a[i] % 10;
      fir = fir + a[i] / 5;
      a[i] = a[i] % 5;
      one = one + a[i] / 1;
    }
    printf("%d %d %d %d %d %d\n", hun, fif, tw, ten, fir, one);
  }
  return 0;
}
