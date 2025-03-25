#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
int qipan[9][9]; // ����
int i, j;
int score = 0; // ����
int juge = 0;  // �ж��Ƿ������ֿ���ӵ�ȫ�ֺ���
void ini()     // ��ʼ��
{
  for (i = 0; i < 9; i++)
    for (j = 0; j < 9; j++) {
      if (i % 2 == 0 && j % 2 == 1)
        qipan[i][j] = 1;
      if (i % 2 == 1 && j % 2 == 0)
        qipan[i][j] = -1;
      if (i % 2 == 1 && j % 2 == 1)
        qipan[i][j] = 0;
    }
}
void dis() {
  int n = 0;
  char s[] = "---";
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      switch (qipan[i][j]) /// ��������
      {
      case 1:
        printf("%4s", s);
        break;
      case -1:
        printf("%4c", '|');
        break;
      case 0:
        printf("%4c", ' ');
        n++;
        break;
      case 2:
        printf("%4d", 2);
        break;
      case 4:
        printf("\033[22;31m%4d\033[0m", 4); // ��ͬ���ֶ�Ӧ��ͬ��ɫ
        break;
      case 8:
        printf("\033[22;32m%4d\033[0m", 8);
        break;
      case 16:
        printf("\033[22;33m%4d\033[0m", 16);
        break;
      case 32:
        printf("\033[22;34m%4d\033[0m", 32);
        break;
      case 64:
        printf("\033[22;35m%4d\033[0m", 64);
        break;
      case 128:
        printf("\033[22;36m%4d\033[0m", 128);
        break;
      case 256:
        printf("\033[22;37m%4d\033[0m", 256);
        break;
      case 512:
        printf("\033[01;33m%4d\033[0m", 512);
        break;
      case 1024:
        printf("\033[01;31m%4d\033[0m", 1024);
        break;
      case 2048:
        printf("\033[01;37m%4d\033[0m", 2048);
        break;
      }
    }
    printf("\n");
  }
  if (n == 25) /// �ո�����һ���ǳ���25�ģ�һ���պ�25˵��û�п�λ����Ϸ����
  {
    system("cls");
    printf("�������շ���Ϊ%d", score);
    getchar();
  } else
    printf("\n ���ķ�����%d", score);
}
void space1(int n) // ���ϻ�����ʱȥ���ո�ĺ���
{
  int z = 0, o, p, q;
  if (n == 1) // ��Ӧ�����ƶ�
  {
    o = 7;
    p = 2;
    q = 1;
  } else // ��Ӧ�����ƶ�
  {
    o = 1;
    p = -2;
    q = 7;
  }
  while (z < 3) // �������Σ���֤ȥ�����ּ��ȫ����λ��
  {
    for (j = o; j != q; j = j - p) {
      if (qipan[j - p][i] == 0 && qipan[j][i] != 0) {
        qipan[j - p][i] = qipan[j][i];
        qipan[j][i] = 0;
        juge = 1; // ���juge������0��˵���������̷������ƶ�
      }
    }
    z++;
  }
}
void space2(int n) // ��Ӧ�����ƶ�ʱ��ȥ����λ�ú���
{
  int z = 0, o, p, q;
  if (n == 1) {
    o = 7;
    p = 2;
    q = 1;
  } else {
    o = 1;
    p = -2;
    q = 7;
  }
  while (z < 3) {
    for (j = o; j != q; j = j - p) {
      if (qipan[i][j - p] == 0 && qipan[i][j] != 0) {
        qipan[i][j - p] = qipan[i][j];
        qipan[i][j] = 0;
        juge = 1;
      }
    }
    z++;
  }
}
void rando() // �������������������2
{
  srand(time(0));
  do {
    i = rand() % 9;
    j = rand() % 9;
  } while (i * j % 2 == 0 || qipan[i][j] != 0);
  qipan[i][j] = 2;
}
void equal(int *a, int *b) // �ϲ���ͬ���ֵĺ���
{
  if (*a != 0 && *a == *b) {
    score += *b; // ��������˺ϲ������������仯
    *b <<= 1;
    *a = 0;
    juge = 1; // ���juge������0��˵���������ƶ�
  }
}
void goup() // �����ƶ��ĺ���
{
  for (i = 1; i < 9; i += 2) {
    space1(1);                         // ȥ����λ��
    equal(&qipan[1][i], &qipan[3][i]); // �������½��кϲ���ͬ����
    equal(&qipan[3][i], &qipan[5][i]);
    equal(&qipan[5][i], &qipan[7][i]);
    space1(1);
  }
}
void godown() {
  for (i = 1; i < 9; i += 2) {
    space1(2);
    equal(&qipan[5][i], &qipan[7][i]);
    equal(&qipan[3][i], &qipan[5][i]);
    equal(&qipan[1][i], &qipan[3][i]);
    space1(2);
  }
}
void goleft() {
  for (i = 1; i < 9; i += 2) {
    space2(1);
    equal(&qipan[i][5], &qipan[i][7]);
    equal(&qipan[i][3], &qipan[i][5]);
    equal(&qipan[i][1], &qipan[i][3]);
    space2(1);
  }
}
void goright() {
  for (i = 1; i < 9; i += 2) {
    space2(2);
    equal(&qipan[i][1], &qipan[i][3]);
    equal(&qipan[i][3], &qipan[i][5]);
    equal(&qipan[i][5], &qipan[i][7]);
    space2(2);
  }
}
int move() {
  juge = 0;
  char key; /// �������
  key =
      getch(); /// �������룬��������,getch()�Ǳ�������õĺ��������������һ�������Ժ��������û�����ĳ���ַ�ʱ�������Զ���ȡ�����谴�س�
  switch (key) {
  case up:
    goup();
    break;
  case down:
    godown();
    break;
  case left:
    goleft();
    break;
  case right:
    goright();
    break;
  }
  if (juge == 1) /// ���Ϊ1����Ϸ����
    return 0;
  else
    return 1;
}
int main() {
  ini();
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++)
      printf("%3d%c", qipan[i][j], j == 8 ? '\n' : ' ');
  }
  rando(); // ��ʼ�����������������
  rando();
  dis();
  while (1) {
    while (move())
      ;
    rando();
    system("cls");
    dis();
  }
  return 0;
}
