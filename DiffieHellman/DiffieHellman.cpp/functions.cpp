#ifndef functions_cpp
#define functions_cpp

#include "diffiehellman.hpp"

__attribute__((constructor))
void genSeed() {
  const auto time = system_clock::now();
  srand(time.time_since_epoch().count());
}

cuint random(cuint min, cuint max) {
  uint choice = rand();
  choice %= (max - min);
  choice += min;
  return choice;
}

cuint modpow(uint a, uint n, cuint p) {
  uint r = 1;
  while (n > 0) {
    if (n % 2) r = (r * a) % p;
    a = (a * a) % p;
    n = floor(n/2);
  }
  return (r % p);
}

#endif