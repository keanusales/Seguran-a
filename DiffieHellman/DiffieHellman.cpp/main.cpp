#ifndef main_cpp
#define main_cpp

#include "diffiehellman.cpp"

int main() {
  system("cls||clear");
  Generator generator(1000, 10000);
  generator.genGroup();
  generator.genGen();
  cuint group = generator.getGroup();
  cuint gen = generator.getGen();
  cout << "Grupo encontrado: " << group << "\n";
  cout << "Gerador encontrado: " << gen << "\n";
  DiffieHellman A(group, gen), B(group, gen);
  A.setSecret(); B.setSecret();
  cuint sendtoB = A.getSend();
  cuint sendtoA = B.getSend();
  cout << "Valor que A envia a B: " << sendtoB << "\n";
  cout << "Valor que B envia a A: " << sendtoA << "\n";
  A.setKey(sendtoA);
  B.setKey(sendtoB);
  cout << "Chave de A: " << A.getKey() << "\n";
  cout << "Chave de B: " << B.getKey() << "\n";
  return 0;
}

#endif