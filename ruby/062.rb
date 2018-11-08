# 062
# Unique Paths
# 2015-12-16
#####################################################
# @param {Integer} m
# @param {Integer} n
# @return {Integer}
def unique_paths(m, n)
  t = [1]*n
  (m-1).times do
    1.upto(n-1) do |i|
      t[i] += t[i-1]
    end
  end
  t[n-1]
end

#####################################################
m = 3
n = 7
r = unique_paths(m, n)
puts r

