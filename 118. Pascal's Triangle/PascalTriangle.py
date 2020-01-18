class Solution:
    def generate(num_rows):
        triangle = []

        for row_num in range(num_rows):
            row = [None for _ in range(row_num+1)]
            row[0], row[-1] = 1, 1
            for j in range(1, len(row)-1):
                row[j] = triangle[row_num-1][j-1] + triangle[row_num-1][j]
                print(row)
            triangle.append(row)

        return triangle


list_res = Solution.generate(5)
print(list_res)
triangle = []
for row_num in range(5):
    row = [1 for _ in range(5+1)]
    print(row)
    row[0], row[-1] = 1, 1
    # for j in range(1, len(row)-1):
    #     row[j] = triangle[row_num-1][j-1] + triangle[row_num-1][j]
    #     print(row)
    #     triangle.append(row)
