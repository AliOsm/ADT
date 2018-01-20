def gcd(a, b): # Greatest Common Divisor
  if b == 0:
    return a
  
  return gcd(b, a % b)

def lcm(a, b):
  return a // gcd(a, b) * b

a, b = map(int, input().split())
print(lcm(a, b))
