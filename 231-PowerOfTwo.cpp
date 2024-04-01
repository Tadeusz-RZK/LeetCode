// Version using math library, maximum iteration set to square root of our value

#include <cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        auto maxIter = ceil(sqrt(n));
        
        for (auto i = 0; i <= maxIter; i++) {
            if (n == pow(2, i)) return true;
        }

        return false;
    }
};

// Version using only bitwise operation, to be a power of two, only 1 bit should be set to 1

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int counter = 0;

        while (n > 0) {
            if ( (n & 1) == 1) {  // Check that bit is equal to 1
                counter++;
            }

            n = n >> 1;  // Basically division by 2
        }

        return counter == 1 ? true : false;
    }
};
