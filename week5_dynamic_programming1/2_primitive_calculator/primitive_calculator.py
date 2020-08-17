# Uses python3
import sys

def optimal_sequence(n):
    sequence = []
    while n >= 1:
        sequence.append(n)
        #if (n-1)%3==0 or (n-1)%2==0:
         #   n=n-1
        if n%3!=0 and n%2!=0:
            n=n-1
        elif n % 3 == 0 and n%2==0:
            n = n // 3
        elif n % 2 == 0 :
            n = n // 2
        elif n%3==0:
            n=n//3
    return reversed(sequence)

#input = sys.stdin.read()
n = int(input())
sequence = list(optimal_sequence(n))
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
