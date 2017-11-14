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

a = gets.chomp.to_i
b = gets.chomp.to_i
puts lcm a, b
