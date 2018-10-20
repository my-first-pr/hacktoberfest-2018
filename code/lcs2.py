#Uses python3

import sys

def lcs2(a, b):
    n,m=len(a),len(b)
    
    dp = [[0 for x in range(n+1)] for x in range(m+1)]
    for i in range(m):
        for j in range(n):
            if b[i]==a[j]:
                dp[i+1][j+1]=dp[i][j]+1
            else:
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])
                
    return dp[m][n]

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))

    n = data[0]
    data = data[1:]
    a = data[:n]

    data = data[n:]
    m = data[0]
    data = data[1:]
    b = data[:m]
    print(lcs2(a, b))
#ayush saini
