def gcd a, b # Geatest Common Divisor
  if b == 0
    a
  else
    gcd b, a % b
  end
end

def lcm a, b
  a / gcd(a, b) * b
end

a, b = gets.split.map(&:to_i)
puts lcm a, b
