#ifndef functions_cpp
#define functions_cpp

#include "rsa.hpp"

ostream &operator<<(ostream &out, chave &temp) {
  out << "\nMensagem: " << temp.message;
  out << "\nNumero N: " << temp.nNum;
  out << "\nChave: " << temp.eNum;
  return out;
}

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

cuint genPrime(cuint min, cuint max) {
  udeque queue;
  for (uint elem = min; elem <= max; elem++) {
    bool isPrime = 1;
    cuint sqrtelem = floor(sqrt(elem));
    for (uint pow = 2; pow <= sqrtelem; pow++) {
      if (elem % pow == 0) {isPrime = 0; break;}
    }
    if (isPrime) queue.push_back(elem);
  }
  return queue[random(0, queue.size())];
}

cuint64 randgcd(cuint64 max) {
  u64deque queue;
  for (uint64 elem = 2; elem < max; elem++) {
    uint64 a = max, b = elem, temp;
    while (b > 0) {
      temp = b;
      b = a % b;
      a = temp;
    }
    if (a == 1) queue.push_back(elem);
  }
  return queue[random(0, queue.size())];
}

cuint64 inverse(cuint64 eNum, cuint64 phi) {
  int64 x = 1, y = 0, g = eNum;
  int64 r = 0, s = 1, t = phi;
  int64 q, u, v, w;
  while (t > 0) {
    q = floor(g/t);
    u = x - q * r;
    v = y - q * s;
    w = g - q * t;
    x = r, y = s, g = t;
    r = u, s = v, t = w;
  }
  if (x < 0) x += phi;
  return x;
}

cuint64 modpow(uint64 a, uint64 n, cuint64 p) {
  uint64 r = 1;
  while (n > 0) {
    if (n % 2) r = (r * a) % p;
    a = (a * a) % p;
    n = floor(n/2);
  }
  return (r % p);
}

#endif