# 071
# Simplify Path
# 2015-12-23
#####################################################
# @param {String} path
# @return {String}
def simplify_path(path)
  v = []
  path.split('/').each do |a|
    if a == '..'
      v.pop
    elsif a != '.' and a != ''
      v.push(a)
    end
  end
  return '/' if v.empty?
  '/'+v.join('/')
end
#####################################################
path = "/..."
r = simplify_path(path)
puts "^"+r+"$"

