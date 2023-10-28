#ifndef rsa_hpp
#define rsa_hpp

#include "generator.hpp"

struct chave {
  uint64 message;
  cuint64 eNum, nNum;
};

class RSA {
  public:
    RSA(cuint, cuint);
    ~RSA() {}
    chave getPublicKey() const;
    cuint64 decript(cuint64) const;

  private:
    void setNnum();
    void setEnum();
    uint pNum;
    uint qNum;
    uint64 nNum;
    uint64 phi;
    uint64 eNum;
    uint64 dNum;
};

#endif