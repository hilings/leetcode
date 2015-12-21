# 065
# Valid Number
# 2015-12-20
#####################################################
# @param {String} s
# @return {Boolean}
def is_number(s)
    i = 0
    i+=1 while s[i] == ' '
    return false if i == s.size
    i+=1 if s[i] == '+' or s[i] == '-'
    i+=1 while myisdigit(s, i)
    if s[i] == '.'
        return false if not myisdigit(s, i-1) and not myisdigit(s, i+1)
        i+=1
    end
    i+=1 while myisdigit(s, i)
    if s[i] == 'e'
        return false if not myisdigit(s, i-1) and not myisdigit(s, i-2)
        return false if not myisdigit(s, i+1) and not myisdigit(s, i+2)
        i+=1
        i+=1 if (s[i] == '+' or s[i] == '-') and myisdigit(s, i+1)
    end
    i+=1 while myisdigit(s, i)
    i+=1 while s[i] == ' '
    i == s.size
end

def myisdigit(s, i)
  return false if i < 0 or i >= s.size
  Float(s[i]) != nil rescue false
end

#####################################################
s = " 1234 "
r = is_number(s)
puts r

