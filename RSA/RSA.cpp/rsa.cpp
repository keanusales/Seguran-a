#ifndef rsa_cpp
#define rsa_cpp

#include "generator.cpp"

RSA::RSA(cuint min, cuint max) {
  Generator gen(min, max);
  this -> pNum = gen.getPnum();
  this -> qNum = gen.getQnum();
  setNnum(); setEnum();
}

void RSA::setNnum() {
  this -> nNum = (pNum * qNum);
  this -> phi = (pNum - 1) * (qNum - 1);
}

void RSA::setEnum() {
  this -> eNum = randgcd(phi);
  this -> dNum = inverse(eNum, phi);
}

chave RSA::getPublicKey() const {
  return {0, eNum, nNum};
}

cuint64 RSA::decript(cuint64 message) const {
  return modpow(message, dNum, nNum);
}

// Não é do RSA
cuint64 encriptMess(chave mess) {
  return modpow(mess.message, mess.eNum, mess.nNum);
}

#endif