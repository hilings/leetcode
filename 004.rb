# 004
# Median of Two Sorted Arrays
#####################################################
def median(a)
  b = a.sort
  len = b.size
  c = len / 2
  if len % 2 == 1
    b[c]
  else
    (b[c-1] + b[c]) / 2.0
  end
end

# @param {Integer[]} nums1 (Array A)
# @param {Integer[]} nums2 (Array B)
# @return {Float}

def find_median_sorted_arrays(nums1, nums2)
  puts nums1.to_s
  puts nums2.to_s
  len1 = nums1.size
  len2 = nums2.size
  return find_median_sorted_arrays(nums2, nums1) if len1 > len2

  c = len2 / 2
  if len1 == 0
    if len2 % 2 == 1
      nums2[c]
    else
      median([nums2[c-1], nums2[c]])
    end
  elsif len1 == 1
    if len2 == 1
      median([nums1[0], nums2[0]])
    elsif len2 % 2 == 1
      median([nums1[0], nums2[c], nums2[c-1], nums2[c+1]])
    else
      median([nums1[0], nums2[c-1], nums2[c]])
    end
  elsif len1 == 2
    if len2 == 2
      median([nums1[0], nums1[1], nums2[0], nums2[1]])
    elsif len2 % 2 == 1
      median([[nums1[0], nums2[c-1]].max, nums2[c], [nums1[1], nums2[c+1]].min])
    else
      median([[nums1[0], nums2[c-2]].max, nums2[c-1], nums2[c], [nums1[1], nums2[c+1]].min])
    end
  else
    h = len1 / 2
    if nums1[h] > nums2[c]
      find_median_sorted_arrays(nums1[0..h], nums2[len1-h-1..-1])
    else
      h -= 1 if len1 % 2 == 0
      find_median_sorted_arrays(nums1[h..-1], nums2[0...-h])
    end
  end
end

#####################################################

a = [];
b = [2];
#a = [2, 2, 2, 2];
#b = [2, 2, 2];
#a = [1, 2, 4, 8, 9, 10];
#b = [3, 5, 6, 7 ];

puts a.to_s
puts b.to_s

puts find_median_sorted_arrays(a, b)

