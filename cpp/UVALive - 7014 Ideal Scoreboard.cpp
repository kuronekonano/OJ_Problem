#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct prom {
  int tt, hh, mm, ss;
  char pp[2], out[35];
} sss[5008];
bool cmp(prom a, prom b) {
  if (a.hh == b.hh) {
    if (a.mm == b.mm) {
      return a.ss < b.ss;
    }
    return a.mm < b.mm;
  }
  return a.hh < b.hh;
}
int main() {
  int t, p, s;
  int team[160], pro[20];
  bool tp[160][20];
  while (scanf("%d%d%d", &t, &p, &s) != EOF) {
    if (!t && !p && !s)
      return 0;
    memset(pro, 0, sizeof(pro));   /// ÿ������AC��������
    memset(team, 0, sizeof(team)); /// ÿ������AC��Ŀ����
    memset(tp, false, sizeof(tp)); /// ÿ��ÿ��AC״̬�ж�
    int tmax = 0, pmax = 0, tmin = t, pmin = p;
    bool flag = false, flag2 = false;
    int sth, stm, sts, eh, em, es;
    for (int i = 0; i < s; i++) {
      scanf("%d", &sss[i].tt);
      scanf("%s", sss[i].pp);
      scanf("%d:%d:%d", &sss[i].hh, &sss[i].mm, &sss[i].ss);
      gets(sss[i].out);
    }
    sort(sss, sss + s, cmp); /// ������ʱ�䲻һ����˳��Ҫ�����һһ�ж�
    for (int i = 0; i < s; i++) {
      if (sss[i].out[1] == 'Y') {
        if (!team[sss[i].tt])
          tmin--; /// �Ƿ����ж�������
        if (!pro[sss[i].pp[0] - 'A'])
          pmin--; /// �Ƿ������ⶼ��A
        if (!tp[sss[i].tt][sss[i].pp[0] -
                           'A']) /// �Ѿ�A����������ֽ��ˣ���ʱ�ǲ����ظ�������
        {
          team[sss[i].tt]++;         /// ÿ�Ӽ���
          pro[sss[i].pp[0] - 'A']++; /// ÿ�⼸��
          if (pro[sss[i].pp[0] - 'A'] > pmax)
            pmax = pro[sss[i].pp[0] - 'A']; /// �����ж�����ĳ��
          if (team[sss[i].tt] > tmax)
            tmax = team[sss[i].tt]; /// ��AK
        }
        tp[sss[i].tt][sss[i].pp[0] - 'A'] = true;
      }
      //            printf("-------> pmax=%d tmax=%d pmin=%d
      //            tmin=%d\n",pmax,tmax,pmin,tmin);
      if (!flag && tmin == 0 && pmin == 0 && pmax != t &&
          tmax != p) /// �ж��Ƿ���Ͽ�ʼʱ��
      {
        sth = sss[i].hh, stm = sss[i].mm,
        sts =
            sss[i]
                .ss; /// pmax��Ϊ�������������Ŀ����������t��д��ĳ��ʱ��˵�����ⱻ������д����
        flag = true; /// tmax��Ϊд����Ŀ���Ķӣ�����p�ⱻд��ʱ��˵������AK
      }
      if (flag && (pmax == t || tmax == p) &&
          !flag2) /// �ж�����״̬�Ƿ��ƻ�,��Ϊpmin��tminһ���ﵽ�������Ͳ����ܱ��ƻ���һֱ�Դ��ڣ���˲��ÿ���
      {
        eh = sss[i].hh, em = sss[i].mm, es = sss[i].ss;
        flag2 = true;
      }
    }
    if (flag) /// ��ʼ����ʱ���
    {
      printf("%02d:%02d:%02d", sth, stm, sts);
    }
    if (flag2) /// ��������ʱ���
    {
      printf(" %02d:%02d:%02d\n", eh, em, es);
    }
    if (!flag) /// û�п�ʼʱ���û�н���ʱ��
    {
      printf("--:--:-- --:--:--\n");
    }
    if (!flag2 && flag) /// ��ʼʱ��֪��������û�н���ʱ���
    {
      printf(" --:--:--\n");
    }
  }
}
