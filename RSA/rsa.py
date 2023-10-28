from os import system
from funcs import *

class Generator:
  __slots__ = "min", "max", "pNum", "qNum"

  def __init__(self, min: int, max: int):
    self.min, self.max = min, max
    self.genPnum(); self.genQnum()

  def genPnum(self):
    min, max = self.min, self.max
    self.pNum = genPrime(min, max)

  def genQnum(self):
    min, max = self.min, (self.pNum - 1)
    self.qNum = genPrime(min, max)

class RSA:
  __slots__ = ("pNum", "qNum", "nNum",
      "phi", "eNum", "dNum")

  def __init__(self, min: int, max: int):
    gen = Generator(min, max)
    self.pNum, self.qNum = gen.pNum, gen.qNum
    self.setNnum(); self.setEnum()

  def setNnum(self):
    self.nNum = self.pNum * self.qNum
    self.phi = (self.pNum - 1) * (self.qNum - 1)

  def setEnum(self):
    self.eNum = randgcd(1, self.phi)
    self.dNum = inverse(self.eNum, self.phi)

  def encript(self, message: int):
    return modpow(message, self.eNum, self.nNum)

  def decript(self, message: int):
    return modpow(message, self.dNum, self.nNum)

system("cls||clear")
if __name__ == "__main__":
  rsa = RSA(1000, 5000)
  message = int(input("Mensagem: "))
  message = rsa.encript(message)
  print(f"Encriptada: {message}")
  message = rsa.decript(message)
  print(f"Decriptada: {message}")