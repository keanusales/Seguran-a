from math import sqrt, floor
from random import choice

def genPrime(min: int, max: int):
  def generator():
    for elem in range(min, max + 1):
      isPrime = True
      sqem = floor(sqrt(elem))
      for fact in range(2, sqem + 1):
        if not elem % fact:
          isPrime = False; break
      if isPrime: yield elem
  return choice([*generator()])

def randgcd(min: int, max: int):
  def generator():
    for elem in range(min + 1, max):
      a, b = max, elem
      while (b > 0):
        temp = b
        b = a % b
        a = temp
      if a == 1: yield elem
  return choice([*generator()])

def inverse(eNum: int, phi: int):
  x, y, g = 1, 0, eNum
  r, s, t = 0, 1, phi
  while (t > 0):
    q = g // t
    u = x - q * r
    v = y - q * s
    w = g - q * t
    x, y, g = r, s, t
    r, s, t = u, v, w
  if x < 0: x += phi
  return x

def modpow(a: int, n: int, p: int):
  r = 1
  while (n > 0):
    if (n % 2): r = (r * a) % p
    a = (a * a) % p
    n = n // 2
  return (r % p)