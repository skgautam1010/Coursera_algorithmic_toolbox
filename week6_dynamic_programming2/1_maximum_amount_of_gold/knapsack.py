# Uses python3
import sys

def optimal_weight(W, w):
    n=len(w)
    weights=[[None]*(n+1) for i in range(W+1)]
    for i in range(n+1):
        for j in range(W+1):
            if i==0 or j==0:
                weights[i][j]=0
            elif w[i-1]<=j:
                weights[i][j]=max(w[i-1]+weights[i-1][j-w[i-1]],weights[i-1][j])
            else:
                weights[i][j]=weights[i-1][j]
    return weights[n][W]


if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
