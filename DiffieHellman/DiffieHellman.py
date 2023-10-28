from random import choice, randint
from math import sqrt, floor
from os import system

class Generator:
  __slots__ = "min", "max", "group", "gen"

  def __init__(self, min: int, max: int):
    self.min, self.max = min, max
    self.genGroup(); self.genGen()
    print(f"Grupo encontrado: {self.group}")
    print(f"Gerador encontrado: {self.gen}")

  def genGroup(self):
    min, max = self.min, self.max
    def generator():
      for elem in range(min, max + 1):
        isPrime, m = True, floor(sqrt(elem))
        for fact in range(2, m + 1):
          if elem % fact == 0:
            isPrime = False; break
        if isPrime: yield elem
    self.group = choice([*generator()])

  def genGen(self):
    G = self.group
    def generator():
      for a in range(2, G):
        isGen = True
        for b in range (1, G - 1):
          if (a ** b) % G == 1:
            isGen = False; break
        if isGen: yield a
    self.gen = choice([*generator()])

class DiffieHellman:
  __slots__ = ("group", "gen", "a",
      "b", "A", "B", "kA", "kB")

  def __init__(self, min: int, max: int):
    gen = Generator(min, max)
    self.group, self.gen = gen.group, gen.gen
    self.coreSideA(); self.coreSideB()
    self.keySideA(); self.keySideB()
    print(f"Número secreto de A: {self.a}")
    print(f"Número que A envia a B: {self.A}")
    print(f"Número secreto de B: {self.b}")
    print(f"Número que B envia a A: {self.B}")
    print(f"Chave descoberta de A: {self.kA}")
    print(f"Chave descoberta de B: {self.kB}")

  def coreSideA(self):
    self.a = randint(1, self.group)
    self.A = self.gen ** self.a % self.group

  def coreSideB(self):
    self.b = randint(1, self.group)
    self.B = self.gen ** self.b % self.group

  def keySideA(self):
    self.kA = self.B ** self.a % self.group

  def keySideB(self):
    self.kB = self.A ** self.b % self.group

system("cls||clear")
if __name__ == "__main__":
  DiffieHellman(20, 1000)