#include <stdio.h> ///要找前缀后缀相同的，即利用KMP中NEXT数组里子串的重复性质来实现
#include <string.h> ///NEXT数组中，最后一位字符的next值表示从头到中间某一位，和中间某一位到末尾字符串相等
char S
    [400005]; /// 这就是模式串中前缀和后缀的最长相等位置，然后在前缀和后缀中继续找next值，即前缀和后缀的相等的前缀和后缀，这样递归下去可以得到所有的前缀和后缀的前缀和后缀的相等串
int next[400005];
void kmp_pre(char x[], int m) {
  int i, j;
  j = next[0] = -1;
  i = 0;
  while (i < m) {
    while (j != -1 && x[i] != x[j])
      j = next[j];
    next[++i] = ++j;
  }
}
void print_back(int x) {
  if (next[x] == 0)
    return;
  print_back(next[x]);
  printf("%d ", next[x]);
}
int main() {
  while (scanf("%s", S) != EOF) {
    int len = strlen(S);
    if (len == 1) {
      printf("1\n");
      continue;
    }
    kmp_pre(S, len);
    print_back(
        len); /// 注意next数组中每一位表示此之前一位是否和前缀相等，也就说如果是len-1位的next值其实表示的是len-2位字符是否和前缀中的字符相等
    printf(
        "%d\n",
        len); /// 因此要使后缀(最末尾位的字符)和前缀相等，应该使用next中len位置的的值，表示跳到
  }
}
/*
——    ——                主传的前缀和后缀的前缀和后缀相等
————————      ————————  主串的前缀和后缀相等
——————————————————————  主串
假设黑色线来代表字符串str，其长度是len，红色线的长度代表next[len]，
根据next数组定义易得前缀的next[len]长度的子串和后缀next[len]长度的子串完全相同（也就是两条线所对应的位置）。
我们再求出next[len]位置处的next值，也就是图中蓝线对应的长度。
同样可以得到两个蓝线对应的子串肯定完全相同，又由于第二段蓝线属于左侧红线的后缀，
所以又能得到它肯定也是整个字符串的后缀。
所以对于这道题，求出len处的next值，并递归的向下求出所有的next值，得到的就是答案。
*/
