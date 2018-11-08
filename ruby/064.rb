# 064
# Minimum Path Sum
# 2015-12-17
#####################################################
# @param {Integer[][]} grid
# @return {Integer}
def min_path_sum(grid)
  m = grid.size
  n = grid[0].size

  t = [grid[0][0]]
  1.upto(n-1) do |j|
    t.push(t[j-1]+grid[0][j])
  end
  print t
  puts

  1.upto(m-1) do |i|
    t[0] = t[0]+grid[i][0]
    1.upto(n-1) do |j|
      t[j] = [t[j-1],t[j]].min + grid[i][j]
    end
    print t
    puts 
  end
  t[n-1]
end

#####################################################
grid = [
  [1,2,3],
  [4,5,6]
]

r = min_path_sum(grid)
puts r

