#include <iostream>
#include <vector>

using namespace std;

class MovingAverage {
private:
  vector<int> window;
  int size;
  int index {0};
  int count {0};
public:
    MovingAverage(int n) : size(n), window(n){}
    
    double next(int val) {
      int sum = 0;
      window[index++ % size] = val;
      count++;
      
      if (count < size) {
        for (int i = 0; i < count; i++) {
          sum += window[i];
        }

        return sum / count;
      } else {
        for (int n : window) {
          sum += n;
        }

        return sum / size;
      }
    }
};

int main() {
  // Test Case 1
  vector<int> arr { 1, 3, 5, 7, 9, 11};

  MovingAverage ma(3);
  
  for (int n : arr) {
    cout << ma.next(n) << endl;
  }

  // next(1)  => 1 = 1 / 1
  // next(3)  => 2 = 1+3 / 2
  // next(5)  => 3 = 1+3+5 / 3
  // next(7)  => 5 = 3+5+7 / 3
  // next(9)  => 7 = 5+7+9 / 3
  // next(11) => 9 = 7+9+11 / 3
}