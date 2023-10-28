#ifndef generator_hpp
#define generator_hpp

#include "include.hpp"

class Generator {
  public:
    Generator(cuint, cuint);
    ~Generator() {}
    cuint getPnum() const;
    cuint getQnum() const;

  private:
    void genPnum();
    void genQnum();
    uint min;
    uint max;
    uint pnum;
    uint qnum;
};

#endif