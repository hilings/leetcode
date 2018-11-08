# 060
# Permutation Sequence
# 2015-12-16
#####################################################
# @param {Integer} n
# @param {Integer} k
# @return {String}
def get_permutation(n, k)
  s = ""
  f = 1
  d = []
  1.upto(n) do |i|
    f *= i
    d.push(i.to_s)
  end
  n.downto(1) do |i|
    f /= i
    q = (k-1) / f
    s += d[q]
    d.delete_at(q)
    k %= f
  end
  s
end

#####################################################
n = 3
k = 6
puts get_permutation(n, k)

