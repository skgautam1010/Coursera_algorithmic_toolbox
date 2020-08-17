#include <iostream>

long long int pisanoperiod(long long int m)
{
    long long int previous=0;
    long long int current=1;
    for(long long int i=0;i<=m*m;i++)
    {
        long long temp_prev=previous;
        previous=current;
        current=(previous+current)%m;
        if(previous==0 && current==1)
        {
            return i+1;
        }
    }
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    n=n%pisanoperiod(m);

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long int get_fibonacci_huge_fast(long long int n,long long int m){
    long long int arr[n];
    for (int i = 2; i <=n; i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    long long int temp=arr[n];
    return temp%m;
    
}

int main() {
    long long int n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
