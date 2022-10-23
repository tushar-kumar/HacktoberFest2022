def product(mat,n):
 
   
    d1 = 0
    d2 = 0
 
    for i in range(n):
 
        d1 += mat[i][i]
        d2 += mat[i][n - i - 1]
 
   
    return d1 * d2
 
 
# Driven code
if __name__ == '__main__':
    mat = [[5, 8, 1],
        [5, 10, 3],
        [-6, 17, -9]]
 
    n = len(mat)
 
   
    print(product(mat, n))
