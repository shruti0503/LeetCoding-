class Solution {
public:
    int mySqrt(long long int N) {
        if (N < 2) return  N; 

       int low = 0, high = N, result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long square = static_cast<long long>(mid) * mid;

        if (square == N) {
            return mid;
        } else if (square < N) {
            result = mid; 
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

      return result;  // Result holds the floor of sqrt(x)
    }
};