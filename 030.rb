# 000
# Substring with Concatenation of All Words
# 2015-05-09
#####################################################
# @param {String} s
# @param {String[]} words
# @return {Integer[]}
def find_substring(s, words)
  v = []
  num = words.size
  return v if num == 0
  size = words.first.size
  return v if size == 0

  len = s.size
  sublen = size * num
  dict = Hash.new(0)
  words.each do |word|
    dict[word]+=1
  end
  dict.each do |key, value|
    puts "#{key} -> #{value}"
  end

  for j in (0...size)
    tdict = Hash.new(0)
    i = j
    while i <= len - size
      word = s[i,size]
      if dict.has_key?(word)
        tdict[word] += 1
        while tdict[word] > dict[word]
          tdict[s[j,size]] -= 1
          j += size
        end

        if i - j == sublen - size
          v.push(j)
          tdict[s[j,size]] -= 1
          j += size
        end
      else
        j = i + size
        tdict.clear
      end
      i += size
    end
  end
  v
end

#####################################################

s = "barfoothefoobarman"
words = ["foo", "bar", "the"]

print find_substring(s, words)
puts

