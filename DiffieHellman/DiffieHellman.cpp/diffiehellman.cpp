#ifndef diffiehellman_cpp
#define diffiehellman_cpp

#include "generator.cpp"

DiffieHellman::DiffieHellman(cuint group, cuint gen) {
  this -> group = group;
  this -> gen = gen;
}

void DiffieHellman::setSecret() {
  this -> secret = random(1, group);
  this -> tosend = modpow(gen, secret, group);
}

void DiffieHellman::setKey(cuint recieved) {
  this -> key = modpow(recieved, secret, group);
}

cuint DiffieHellman::getSend() const {
  return this -> tosend;
}

cuint DiffieHellman::getKey() const {
  return this -> key;
}

#endif