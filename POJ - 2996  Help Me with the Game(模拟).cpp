#include <algorithm>
#include <stdio.h> ///ģ�⣬�������̣����������ϸ�����������λ�ã�������ͬ��ɫ�����д�С�����д�С�������
#include <string.h> ///������ͬ��ɫ�����дӴ�С���д�С�������
using namespace std;
struct point {
  int x;
  char y;
} P[10], p[10], k, q, r[2], n[2], b[2], K, Q, R[2], N[2],
    B[2];                  /// ÿ������λ�ã��Լ���Ӧ��ɫ
bool CMP(point a, point b) /// �������˳������
{
  if (a.x == b.x)
    return a.y < b.y;
  return a.x < b.x;
}
bool cmp(point a, point b) /// �������˳������
{
  if (a.x == b.x)
    return a.y < b.y;
  return a.x > b.x;
}
int main() {
  char ma[40][40];
  while (scanf("%s", ma[0]) != EOF) {
    for (int i = 1; i < 17; i++) {
      scanf("%s", ma[i]);
    }
    int rr = 0, nn = 0, bb = 0, RR = 0, NN = 0, BB = 0, KK = 0, kk = 0, QQ = 0,
        qq = 0, PP = 0, pp = 0;     /// ��ʼ���������ӳ��ֱ�־�ͳ�������
    for (int i = 1; i < 17; i += 2) /// ������λ
    {
      for (int j = 2; j < 33; j += 4) {
        if (ma[i][j] == ':' || ma[i][j] == '.')
          continue;                                  /// δ��������
        else if (ma[i][j] >= 'a' && ma[i][j] <= 'z') /// ����
        {
          if (ma[i][j] == 'k') {
            kk++;
            k.x = 9 - (i + 1) / 2;
            k.y = 'a' + (j + 2) / 4 - 1;
          }
          if (ma[i][j] == 'q') {
            qq++;
            q.x = 9 - (i + 1) / 2;
            q.y = 'a' + (j + 2) / 4 - 1;
          }
          if (ma[i][j] == 'r') {
            r[rr].x = 9 - (i + 1) / 2;
            r[rr].y = 'a' + (j + 2) / 4 - 1;
            rr++;
          }
          if (ma[i][j] == 'b') {
            b[bb].x = 9 - (i + 1) / 2;
            b[bb].y = 'a' + (j + 2) / 4 - 1;
            bb++;
          }
          if (ma[i][j] == 'n') {
            n[nn].x = 9 - (i + 1) / 2;
            n[nn].y = 'a' + (j + 2) / 4 - 1;
            nn++;
          }
          if (ma[i][j] == 'p') /// ʿ��
          {
            p[pp].x = 9 - (i + 1) / 2;
            p[pp].y = 'a' + (j + 2) / 4 - 1;
            pp++;
          }
        } else /// ����
        {
          if (ma[i][j] == 'K') {
            KK++;
            K.x = 9 - (i + 1) / 2;
            K.y = 'a' + ((j / 2) + 1) / 2 - 1;
          }
          if (ma[i][j] == 'Q') {
            QQ++;
            Q.x = 9 - (i + 1) / 2;
            Q.y = 'a' + ((j / 2) + 1) / 2 - 1;
          }
          if (ma[i][j] == 'R') {
            R[RR].x = 9 - (i + 1) / 2;
            R[RR].y = 'a' + ((j / 2) + 1) / 2 - 1;
            RR++;
          }
          if (ma[i][j] == 'B') {
            B[BB].x = 9 - (i + 1) / 2;
            B[BB].y = 'a' + ((j / 2) + 1) / 2 - 1;
            BB++;
          }
          if (ma[i][j] == 'N') {
            N[NN].x = 9 - (i + 1) / 2;
            N[NN].y = 'a' + ((j / 2) + 1) / 2 - 1;
            NN++;
          }
          if (ma[i][j] == 'P') {
            P[PP].x = 9 - (i + 1) / 2;
            P[PP].y = 'a' + ((j / 2) + 1) / 2 - 1;
            PP++;
          }
        }
      }
    }
    sort(n, n + nn, cmp); /// ������ɫ���˳������
    sort(b, b + bb, cmp);
    sort(r, r + rr, cmp);
    sort(p, p + pp, cmp);
    sort(N, N + NN, CMP);
    sort(B, B + BB, CMP);
    sort(R, R + RR, CMP);
    sort(P, P + PP, CMP);
    printf("White: ");
    if (KK)
      printf("K%c%d", K.y, K.x); /// �����ҽ���һ������˲����������
    if (QQ)
      printf(",Q%c%d", Q.y, Q.x);
    if (RR)
      for (int i = 0; i < RR; i++)
        printf(",R%c%d", R[i].y, R[i].x);
    if (BB)
      for (int i = 0; i < BB; i++)
        printf(",B%c%d", B[i].y, B[i].x);
    if (NN)
      for (int i = 0; i < NN; i++)
        printf(",N%c%d", N[i].y, N[i].x);
    if (PP)
      for (int i = 0; i < PP; i++)
        printf(",%c%d", P[i].y, P[i].x);
    printf("\n");
    printf("Black: ");
    if (kk)
      printf("K%c%d", k.y, k.x);
    if (qq)
      printf(",Q%c%d", q.y, q.x);
    if (rr)
      for (int i = 0; i < rr; i++)
        printf(",R%c%d", r[i].y, r[i].x);
    if (bb)
      for (int i = 0; i < bb; i++)
        printf(",B%c%d", b[i].y, b[i].x);
    if (nn)
      for (int i = 0; i < nn; i++)
        printf(",N%c%d", n[i].y, n[i].x);
    if (pp)
      for (int i = 0; i < pp; i++)
        printf(",%c%d", p[i].y, p[i].x);
    printf("\n");
  }
}
