// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (0 == n) {
    return 1;
  } else {
    return value * pown(value, n - 1);
  }
}

uint64_t fact(uint16_t n) {
  if (0 == n) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double summa = 1.0;
  for (int i = 1; i <= count; i++) {
    summa += calcItem(x, i);
  }
  return summa;
}

double sinn(double x, uint16_t count) {
  double summa = 0.0;
  while (count > 0) {
    summa += pown(-1, count - 1) * calcItem(x, 2 * count - 1);
    --count;
  }
  return summa;
}

double cosn(double x, uint16_t count) {
  double summa = 0.0;
  while (count > 0) {
    summa += pown(-1, count - 1) * calcItem(x, 2 * count - 2);
    --count;
  }
  return summa;
}
