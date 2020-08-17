#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;


int compute_min_refills(int dist, int tank, int n,vector<int> &stops) {
    int numRefills = 0;
    int currentRefill = 0;
    int lastRefill = 0;
    
    if ((stops[currentRefill] + tank) >= dist) {
        return numRefills;
    }

    while (currentRefill <= n) {
        lastRefill = currentRefill; 
        while ((currentRefill <= n) && ((stops[currentRefill + 1] - stops[lastRefill]) <= tank)) {
            currentRefill = currentRefill + 1;
            //cout << currentRefill << Stops[currentRefill] << "\t"; //printing to check 
        }
        if (currentRefill == lastRefill || stops[lastRefill]+tank>dist) {
            //cout << "-1";
            return -1;
        }
        if (currentRefill <= n) {
            //cout << numRefills;
            numRefills = numRefills + 1;
        }
        if ((stops[currentRefill] + tank) >= dist) {
            //cout << "Not bullshit" << Stops[currentRefill + 1];
            return ++numRefills;
        }
    }
    return numRefills; 
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m,n,stops) << "\n";

    return 0;
}
