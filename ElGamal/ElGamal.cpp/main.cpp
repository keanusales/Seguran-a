#ifndef main_cpp
#define main_cpp

#include "elgamal.cpp"

int main() {
  system("cls||clear");
  ElGamal A(30000, 50000);
  publicKey key = A.getPublicKey();
  key.message = 5863; // Modifico de meu lado
  cout << "A tornou publico:" << key << "\n";
  encripted encript = encriptMess(key);
  cout << "Encriptada: " << encript << "\n";
  cuint64 decript = A.decript(encript);
  cout << "Decriptada: " << decript << "\n";
  return 0;
}

#endif