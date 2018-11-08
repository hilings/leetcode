# 063
# Unique Paths II
# 2015-12-17
#####################################################
# @param {Integer[][]} obstacle_grid
# @return {Integer}
def unique_paths_with_obstacles(obstacle_grid)
  m = obstacle_grid.size
  n = obstacle_grid.first.size

  t = [1] + [0]*(n-1)

  0.upto(m-1) do |i|
    t[0] = 0 if obstacle_grid[i][0] == 1
    1.upto(n-1) do |j|
      t[j] = obstacle_grid[i][j] == 1 ? 0 : t[j-1]+t[j]
    end
    print t
    puts
  end

  t[n-1]
end

#####################################################
obstacle_grid = [
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
r = unique_paths_with_obstacles(obstacle_grid)
puts r

