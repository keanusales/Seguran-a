#ifndef main_cpp
#define main_cpp

#include "rsa.cpp"

int main() {
  system("cls||clear");
  RSA A(10000, 50000);
  chave mess = A.getPublicKey();
  mess.message = 9876; // Modifico do meu lado
  cout << "A tornou publico:" << mess << "\n";
  cuint64 encript = encriptMess(mess);
  cout << "Encript Message: " << encript << "\n";
  cuint64 decript = A.decript(encript);
  cout << "Decript Message: " << decript << "\n";
  return 0;
}

#endif