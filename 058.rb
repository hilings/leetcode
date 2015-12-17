# 058
# Length of Last Word
# 2015-12-15
#####################################################
# @param {String} s
# @return {Integer}
def length_of_last_word(s)
  s2 = s.rstrip
  return s2.size-1-(s2.rindex(' ') || -1)
end

#####################################################

s = "asdf asdf "
puts length_of_last_word(s)

