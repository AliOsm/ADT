def gcd a, b
  if b == 0
    a
  else
    gcd b, a % b
  end
end

a, b = gets.split.map(&:to_i)
puts gcd a, b
