#ifndef functions_cpp
#define functions_cpp

#include "elgamal.hpp"

ostream &operator<<(ostream &out, encripted &temp) {
  out << "(" << temp.c1 << ", " << temp.c2 << ")";
  return out;
}

ostream &operator<<(ostream &out, publicKey &temp) {
  out << "\nMensagem: " << temp.message;
  out << "\nGrupo: " << temp.group;
  out << "\nGerador: " << temp.gener;
  out << "\nChave: " << temp.pubKey;
  return out;
}

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

cuint64 inverse(cuint64 num, cuint64 group) {
  int64 x = 1, y = 0, g = num;
  int64 r = 0, s = 1, t = group;
  int64 q, u, v, w;
  while (t > 0) {
    q = (g / t);
    u = x - (q * r);
    v = y - (q * s);
    w = g - (q * t);
    x = r, y = s, g = t;
    r = u, s = v, t = w;
  }
  if (x < 0) x += group;
  return x;
}

#endif