class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> countMap;
            for (int i = 1; i <= n; ++i) {
                int sum = sumOfDigits(i);
                countMap[sum]++;
            }
            
            int maxCount = 0;
            int result = 0;
            for (const auto& pair : countMap) {
                if (pair.second > maxCount) {
                    maxCount = pair.second;
                    result = 1;
                } else if (pair.second == maxCount) {
                    result++;
                }
            }
            
            return result;
        }
        
    private:
        int sumOfDigits(int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }
    };