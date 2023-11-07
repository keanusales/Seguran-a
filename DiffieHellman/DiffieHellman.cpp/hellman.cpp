#ifndef hellman_cpp
#define hellman_cpp

#include "generator.cpp"

Hellman::Hellman(cuint64 group, cuint64 gener) {
  this -> group = group;
  this -> gener = gener;
  setSecret();
}

void Hellman::setSecret() {
  this -> secKey = random(1, group);
  this -> pubKey = modpow(gener, secKey, group);
}

void Hellman::setKey(cuint64 recieved) {
  this -> key = modpow(recieved, secKey, group);
}

cuint64 Hellman::getPub() const {
  return this -> pubKey;
}

cuint64 Hellman::getKey() const {
  return this -> key;
}

#endif