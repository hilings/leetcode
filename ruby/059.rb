# 059
# Spiral Matrix II
# 2015-12-16
#####################################################
# @param {Integer} n
# @return {Integer[][]}
def generate_matrix(n)
  m = Array.new(n) {Array.new(n)}
  fill(m, 0, n-1, 0)
  m
end
def fill(m, p, q, count)
  if p == q
    m[p][p] = count+=1
    return
  end
  return if p > q
  p.upto(q-1).each {|i| m[p][i] = count+=1}
  p.upto(q-1).each {|i| m[i][q] = count+=1}
  q.downto(p+1).each {|i| m[q][i] = count+=1}
  q.downto(p+1).each {|i| m[i][p] = count+=1}
  fill(m, p+1, q-1, count)
end

#####################################################

n = 3
m = generate_matrix(n)
m.each do |v|
  print v
  puts
end

