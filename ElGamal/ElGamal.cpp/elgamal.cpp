#ifndef elgamal_cpp
#define elgamal_cpp

#include "generator.cpp"

ElGamal::ElGamal(cuint64 min, cuint64 max) {
  Generator gen(min, max);
  this -> group = gen.getGroup();
  this -> gener = gen.getGener();
  setKeys();
}

void ElGamal::setKeys() {
  this -> secKey = random(2, group - 1);
  this -> pubKey = modpow(gener, secKey, group);
}

publicKey ElGamal::getPublicKey() const {
  return {0, group, gener, pubKey};
}

cuint64 ElGamal::decript(encripted message) const {
  cuint64 s1 = modpow(message.c1, secKey, group);
  cuint64 inv = inverse(s1, group);
  return (message.c2 * inv) % group;
}

// Não é da classe ElGamal
encripted encriptMess(publicKey input) {
  cuint64 pow = random(2, input.group - 1);
  cuint64 c1 = modpow(input.gener, pow, input.group);
  cuint64 e = modpow(input.pubKey, pow, input.group);
  cuint64 c2 = (input.message * e) % input.group;
  return {c1, c2};
}

#endif