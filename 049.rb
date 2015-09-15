# 049
# Group Anagrams
# 2015-09-10
#####################################################
# @param {String[]} strs
# @return {String[][]}
def group_anagrams(strs)
  dict = {}
  strs.each do |word|
    key = word.chars.sort.join
    dict[key] ||= []
    dict[key] << word
  end
  dict.each do |key, value|
    dict[key] = value.sort
  end
  dict.values
end

#####################################################

strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

puts group_anagrams(strs).inspect

