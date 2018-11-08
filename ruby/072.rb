#   072
#   Edit Distance
#   2016-01-01
#####################################################
# @param {String} word1
# @param {String} word2
# @return {Integer}
def min_distance(word1, word2)
    return word1.size + word2.size if word1.empty? or word2.empty?
    d = Array.new(word1.size) {Array.new(word2.size)}
    d[0][0] = word1[0] == word2[0] ? 0 : 1

    1.upto(word1.size-1) do |i|
        d[i][0] = (word1[i] == word2[0] and d[i-1][0] == i) ? d[i-1][0] : d[i-1][0]+1
    end
    1.upto(word2.size-1) do |j|
        d[0][j] = (word2[j] == word1[0] and d[0][j-1] == j) ? d[0][j-1] : d[0][j-1]+1
    end
    1.upto(word1.size-1) do |i|
        1.upto(word2.size-1) do |j|
            d[i][j] = [d[i-1][j], d[i][j-1]].min
            if d[i-1][j-1] <= d[i][j]
                d[i][j] = d[i-1][j-1]
                d[i][j] += 1 if word1[i] != word2[j]
            else
                d[i][j] += 1
            end
        end
    end
    0.upto(word1.size-1) do |i|
        0.upto(word2.size-1) do |j|
            print d[i][j], ' '
        end
        puts
    end
    d[word1.size-1][word2.size-1]
end

#####################################################
word1 = "XMJYAUZ"   #6
word2 = "MZJAWXU"
r = min_distance(word1, word2)
puts r

