#ifndef generator_cpp
#define generator_cpp

#include "functions.cpp"

Generator::Generator(cuint64 min, cuint64 max) {
  this -> min = min;
  this -> max = max;
  genGroup(); genGener();
}

void Generator::genGroup() {
  u64deque queue;
  for (uint64 elem = min; elem <= max; elem++) {
    bool isPrime = 1;
    cuint64 sqrtelem = floor(sqrt(elem));
    for (uint64 pow = 2; pow <= sqrtelem; pow++) {
      if (elem % pow == 0) {isPrime = 0; break;}
    }
    if (isPrime) queue.push_back(elem);
  }
  cuint64 choice = random(0, queue.size());
  this -> group = queue[choice];
}

void Generator::genGener() {
  cuint64 euler = (group - 1);
  u64deque queue;
  for (uint64 elem = 2; elem < group; elem++) {
    bool isGen = 1; uint64 res = 1;
    for (uint64 pow = 1; pow < euler; pow++) {
      res = (res * elem) % group;
      if (res == 1) {isGen = 0; break;}
    }
    if (isGen) queue.push_back(elem);
  }
  cuint64 choice = random(0, queue.size());
  this -> gener = queue[choice];
}

cuint64 Generator::getGroup() const {
  return this -> group;
}

cuint64 Generator::getGener() const {
  return this -> gener;
}

#endif