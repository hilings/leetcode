# 017
# Letter Combinations of a Phone Number
# 2015-04-23
#####################################################
# @param {String} digits
# @return {String[]}
def letter_combinations(digits)
  map = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
  v = []
  for i in 0...digits.size
    d = digits[i].to_i
    letters = map[d]
    num = v.size
    if num == 0
      letters.each_char do |c|
        v.push(c)
      end
    else
      for j in 0...letters.size-1
        for k in 0...num
          v.push(v[k])
        end
      end
      for j in 0...letters.size
        for k in 0...num
          v[num*j+k] += letters[j]
        end
      end
    end
  end
  v
end

#####################################################

digits = "23";

puts letter_combinations(digits).inspect

