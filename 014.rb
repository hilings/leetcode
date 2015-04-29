# 014
# Longest Common Prefix
# 2014-04-20
#####################################################
# @param {String[]} strs
# @return {String}
def longest_common_prefix(strs)
  return "" if strs.size == 0
  prefix = ""
  for i in 0...strs[0].size
    c = strs[0][i]
    for j in 0...strs.size
      if i >= strs[j].size or strs[j][i] != c
        return prefix
      end
    end
    prefix += c
  end
  prefix
end

#####################################################

strs = ["abc", "abd", "abe"]
puts strs
puts longest_common_prefix(strs)

