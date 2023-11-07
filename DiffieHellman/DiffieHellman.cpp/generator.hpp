#ifndef generator_hpp
#define generator_hpp

#include "include.hpp"

class Generator {
  public:
    Generator(cuint64, cuint64);
    inline ~Generator() {}
    cuint64 getGroup() const;
    cuint64 getGener() const;

  private:
    void genGroup();
    void genGener();
    uint64 min;
    uint64 max;
    uint64 group;
    uint64 gener;
};

#endif