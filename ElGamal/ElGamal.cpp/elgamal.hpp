#ifndef elgamal_hpp
#define elgamal_hpp

#include "generator.hpp"

struct encripted {
  cuint64 c1, c2;
};

struct publicKey {
  uint64 message;
  cuint64 group;
  cuint64 gener;
  cuint64 pubKey;
};

class ElGamal {
  public:
    ElGamal(cuint64, cuint64);
    inline ~ElGamal() {}
    publicKey getPublicKey() const;
    cuint64 decript(encripted) const;

  private:
    void setKeys();
    uint64 group;
    uint64 gener;
    uint64 secKey;
    uint64 pubKey;
};

#endif