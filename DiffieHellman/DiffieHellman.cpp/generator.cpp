#ifndef generator_cpp
#define generator_cpp

#include "functions.cpp"

Generator::Generator(cuint min, cuint max) {
  this -> min = min;
  this -> max = max;
}

void Generator::genGroup() {
  udeque queue;
  for (uint elem = min; elem <= max; elem++) {
    bool isPrime = 1;
    cuint sqrtelem = floor(sqrt(elem));
    for (uint pow = 2; pow <= sqrtelem; pow++) {
      if (elem % pow == 0) {isPrime = 0; break;}
    }
    if (isPrime) queue.push_back(elem);
  }
  cuint choice = random(0, queue.size());
  this -> group = queue[choice];
}

void Generator::genGen() {
  cuint order = (group - 1);
  udeque queue;
  for (uint elem = 2; elem < group; elem++) {
    bool isGen = 1;
    for (uint pow = 1; pow < order; pow++) {
      cuint res = modpow(elem, pow, group);
      if (res == 1) {isGen = 0; break;}
    }
    if (isGen) queue.push_back(elem);
  }
  cuint choice = random(0, queue.size());
  this -> gen = queue[choice];
}

cuint Generator::getGroup() const {
  return this -> group;
}

cuint Generator::getGen() const {
  return this -> gen;
}

#endif