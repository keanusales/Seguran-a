#ifndef generator_hpp
#define generator_hpp

#include "include.hpp"

class Generator {
  public:
    Generator(cuint, cuint);
    ~Generator() {}
    void genGroup();
    void genGen();
    cuint getGroup() const;
    cuint getGen() const;

  private:
    uint min;
    uint max;
    uint group;
    uint gen;
};

#endif