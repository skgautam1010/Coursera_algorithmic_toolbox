# python3
import sys


def compute_min_refills(distance, tank, stops):
    numrefill=0
    currentrefill=0
    while currentrefill<=tank:
        lastrefill=currentrefill
        while(currentrefill<=tank and (stops[currentrefill+1]-stops[lastrefill])<=distance):
            currentrefill=currentrefill+1
        if currentrefill==lastrefill:
            return -1
        if currentrefill<=tank:
            numrefill=numrefill+1
    return numrefill

if __name__ == '__main__':
    d, m, _, *stops = map(int, sys.stdin.read().split())
    print(compute_min_refills(d, m, stops))
