// Integer solution

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        if (x % 10 == 0 && x != 0) return false;

        int reversed = 0;
        while (x > reversed) {
            reversed = (reversed * 10) + (x % 10);  // Moving first digit to the left, adding last digit of x
            x /= 10;  // Removing digits on the right
        }

        return (x == reversed || x == reversed / 10);
    }
};

// String reverse solution

class Solution {
public:
    bool isPalindrome(int x) {
        string input = std::to_string(x);

        reverse(input.begin(), input.end());

        return (input == std::to_string(x));

    }
};