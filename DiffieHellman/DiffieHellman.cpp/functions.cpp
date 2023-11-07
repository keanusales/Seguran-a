#ifndef functions_cpp
#define functions_cpp

#include "hellman.hpp"

__attribute__((constructor))
void genSeed() {
  const auto time = system_clock::now();
  srand(time.time_since_epoch().count());
}

cuint64 random(cuint64 min, cuint64 max) {
  uint64 choice = rand();
  choice %= (max - min);
  choice += min;
  return choice;
}

cuint64 modpow(uint64 a, uint64 n, cuint64 p) {
  uint64 r = 1;
  while (n > 0) {
    if (n % 2) r = (r * a) % p;
    a = (a * a) % p;
    n = (n / 2);
  }
  return (r % p);
}

#endif