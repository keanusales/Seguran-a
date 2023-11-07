#ifndef main_cpp
#define main_cpp

#include "hellman.cpp"

int main() {
  system("cls||clear");
  Generator gen(50000, 100000);
  cuint64 group = gen.getGroup();
  cuint64 gener = gen.getGener();
  cout << "Grupo encontrado: " << group << "\n";
  cout << "Gerador encontrado: " << gener << "\n";
  Hellman A(group, gener), B(group, gener);
  cuint64 sendtoB = A.getPub();
  cuint64 sendtoA = B.getPub();
  cout << "Valor que A envia a B: " << sendtoB << "\n";
  cout << "Valor que B envia a A: " << sendtoA << "\n";
  A.setKey(sendtoA);
  B.setKey(sendtoB);
  cout << "Chave de A: " << A.getKey() << "\n";
  cout << "Chave de B: " << B.getKey() << "\n";
  return 0;
}

#endif