# 028
# Implement strStr()
# 2015-05-03
#####################################################
# @param {String} haystack
# @param {String} needle
# @return {Integer}
def str_str(haystack, needle)
  return 0 if needle.size == 0

  for i in (0...haystack.size)
    if haystack[i] != needle[0]
      next
    end

    k = i
    j = 0
    while j < needle.size
      if k == haystack.size
        return -1
      end

      if haystack[k] == needle[j]
        k+=1
        j+=1
      else
        break
      end
    end
    if j == needle.size
      return i
    end
  end
  -1
end

def str_str0(haystack, needle)
  return haystack.index(needle) || -1
end

def str_str2(haystack, needle)  # KMP
  l2 = needle.size
  if l2 == 0
    return 0
  end
  t = [-1]
  for j in (1...l2)
    if t[j-1] > -1 and needle[j-1] == needle[t[j-1]]
      t[j] = t[j-1] + 1
    else
      t[j] = 0
    end
    puts "#{needle[j]} #{t[j]}"
  end

  l1 = haystack.size
  i = 0
  j = 0
  while i + j < l1
    if haystack[i+j] == needle[j]
      if j == l2 - 1
        return i
      else
        j+=1
      end
    else
      if t[j] > -1
        i = i + j - t[j]
        j = t[j]
      else
        i += 1
        j = 0
      end
    end
  end
  -1
end

#####################################################

haystack = "ABC ABCDAB ABCDABCDABDE"
needle = "ABCDABD"
puts str_str2(haystack, needle)

