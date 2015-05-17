# 038
# Count and Say
# 2015-05-15
#####################################################
# @param {Integer} n
# @return {String}
def count_and_say(n)
  s = "1"
  for i in (1...n)
    puts "#{i}, #{s}"
    tmp = ""
    j = 1
    count = 1
    while j < s.size
      if s[j] == s[j-1]
        count += 1
      else
        tmp += count.to_s + s[j-1]
        count = 1
      end
      j+=1
    end
    tmp += count.to_s + s[j-1]
    s = tmp
  end
  puts "#{n}, #{s}"
  s
end

#####################################################

n = 20
count_and_say(n)

