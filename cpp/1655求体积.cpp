#include <stdio.h>
#define pi 3.1415926
int main() {
  double h, v;
  while (scanf("%lf", &h) != EOF) {
    v = h * h * h * pi /
        6; // 想象，用极限法，若不知半径r，则设这个圆柱无限细，此时剩余体积为球体体积，半径为h/2，套用球体积公式，化简后得h^3/6*pi
    printf("%.2f\n", v);
  }
}
