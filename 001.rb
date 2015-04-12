# 002
# Two Sum
#####################################################
# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]} two integers in an array, ie: [index1, index2]

# sort, then scan from two ends
def two_sum(numbers, target)
  b = numbers.sort
  i = 0
  j = numbers.size - 1
  while i < j do
    if b[i] + b[j] < target
      i += 1
    elsif b[i] + b[j] > target
      j -= 1
    else
      index1 = numbers.index(b[i]) + 1
      index2 = numbers.rindex(b[j]) + 1
      index1, index2 = index2, index1 if index1 > index2
      return [index1, index2]
    end
  end
end

# find index within array
def two_sum2(numbers, target)
  numbers.each_index do |index1|
    index2 = numbers.rindex(target-numbers[index1])
    return [index1+1, index2+1] if index2 and index1 < index2
  end
end

# hash
def two_sum3(numbers, target)
  h = Hash[numbers.map.with_index{|value, index| [value, index]}]
  numbers.each_index do |index1|
    index2 = h[target-numbers[index1]]
    return [index1 + 1, index2 + 1] if index2 and index1 < index2
  end
end

numbers = [4, 2, 1, 8]
numbers = [4, 3, 8]
numbers = [0, 1, 3, 0]
puts numbers.join(' ')

target = 0

puts two_sum3(numbers, target).join(' ')
