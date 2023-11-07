#ifndef hellman_hpp
#define hellman_hpp

#include "generator.hpp"

class Hellman {
  public:
    Hellman(cuint64, cuint64);
    inline ~Hellman() {}
    void setKey(cuint64);
    cuint64 getPub() const;
    cuint64 getKey() const;

  private:
    void setSecret();
    uint64 group;
    uint64 gener;
    uint64 secKey;
    uint64 pubKey;
    uint64 key;
};

#endif