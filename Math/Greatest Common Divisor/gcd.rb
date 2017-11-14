def gcd a, b
  if b == 0
    a
  else
    gcd b, a % b
  end
end

a = gets.chomp.to_i
b = gets.chomp.to_i
puts gcd a, b
