# 022
# Generate Parentheses
# 2015-04-29
#####################################################
# @param {Integer} n
# @return {String[]}
def generate_parenthesis(n)
  v = []
  return v if n == 0
  v.push("(")
  while v.first.size < 2*n
    s = v.shift
    l = r = 0
    s.each_char do |c|
      if c == "("
        l+=1
      else
        r+=1
      end
    end

    if l<n
      v.push(s+"(")
    end
    if l>r
      v.push(s+")")
    end
  end
  v
end

#####################################################

n = 4
v = generate_parenthesis(n)
puts v
puts v.size


