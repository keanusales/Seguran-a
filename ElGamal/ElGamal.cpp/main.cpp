#ifndef main_cpp
#define main_cpp

#include "elgamal.cpp"

int main() {
  system("cls||clear");
  ElGamal A(50000, 100000);
  publicKey key = A.getPublicKey();
  key.message = 46532; // Modifico de meu lado
  cout << "A tornou publico:" << key << "\n";
  encripted encript = encriptMess(key);
  cout << "Encriptada: " << encript << "\n";
  cuint64 decript = A.decript(encript);
  cout << "Decriptada: " << decript << "\n";
  return 0;
}

#endif