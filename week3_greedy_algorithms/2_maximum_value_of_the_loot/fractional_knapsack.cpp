#include <iostream>
#include <vector>

using std::vector;
using namespace std;


int get_max_index (vector<int> weights, vector<int> values) {
    int max_i = 0; 
    double max = 0; 

    for (int i = 0; i < weights.size(); i++) { // iterating through the weights
        if (weights[i] != 0 && (double)values[i]/weights[i] > max) { 
            max = (double)values[i]/weights[i]; 
            max_i = i; 
        }
    }
    return max_i;
}


double get_optimal_value(int capacity, vector<int> values, vector<int> weights,int n) {
  double value = 0.0;
  double temp=0;
 vector<int>sorted;
  for(int i=0;i<weights.size();i++)
  {
      if (capacity==0) return value;
      int index = get_max_index(weights, values);
      int a= min(capacity,weights[index]);
      value=value+(a*(double)values[index]/weights[index]);
      weights[index]=weights[index]-a;
      //arr[i]=arr[i]+a;
      capacity=capacity-a;

    
    
  }  

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, values, weights,n);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
