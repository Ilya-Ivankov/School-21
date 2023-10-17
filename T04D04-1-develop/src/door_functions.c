#include <math.h>
#include <stdio.h>

double agnesi(double num);

double bernulli(double num);

double hyper(double num);

int main(void) {
  double startNum = -M_PI;
  double step = M_PI / 20.5;

  for (int i = 0; i < 42; i++) {
    printf("%.7lf | %.7lf | ", startNum, agnesi(startNum));

    double bernulliRes = bernulli(startNum);

    if (isnan(bernulliRes)) {
      printf("- | ");
    } else {
      printf("%.7lf | ", bernulliRes);
    }

    printf("%.7lf\n", hyper(startNum));

    startNum += step;
  }

  return 0;
}

double agnesi(double num) {
  double res = 1 / (1 + num * num);
  return res;
}

double bernulli(double num) {
  double res = sqrt(sqrt(1 + 4 * num * num) - num * num - 1);
  return res;
}

double hyper(double num) {
  double res = 1 / (num * num);
  return res;
}