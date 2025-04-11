#include <string>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; ++num) {
            if (isSymmetric(num)) {
                ++count;
            }
        }
        return count;
    }

private:
    bool isSymmetric(int num) {
        string s = to_string(num);
        int n = s.size();
        if (n % 2 != 0) {
            return false;
        }
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n/2; ++i) {
            sum1 += s[i] - '0';
        }
        for (int i = n/2; i < n; ++i) {
            sum2 += s[i] - '0';
        }
        return sum1 == sum2;
    }
};