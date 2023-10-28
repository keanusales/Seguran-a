#ifndef diffiehellman_hpp
#define diffiehellman_hpp

#include "generator.hpp"

class DiffieHellman {
  public:
    DiffieHellman(cuint, cuint);
    ~DiffieHellman() {}
    void setSecret();
    void setKey(cuint);
    cuint getSend() const;
    cuint getKey() const;

  private:
    uint group;
    uint gen;
    uint secret;
    uint tosend;
    uint key;
};

#endif