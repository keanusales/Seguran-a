#ifndef generator_cpp
#define generator_cpp

#include "functions.cpp"

Generator::Generator(cuint min, cuint max) {
  this -> min = min;
  this -> max = max;
  genPnum(); genQnum();
}

void Generator::genPnum() {
  this -> pnum = genPrime(min, max);
}

void Generator::genQnum() {
  this -> qnum = genPrime(min, pnum - 1);
}

cuint Generator::getPnum() const {
  return this -> pnum;
}

cuint Generator::getQnum() const {
  return this -> qnum;
}

#endif