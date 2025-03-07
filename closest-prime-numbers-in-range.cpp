class Solution {
private:
    static const int MAX_LIMIT = 1000000;
    static vector<bool> isPrime;
    static vector<int> primes;
    static bool isSieveComputed;

    // Sieve of Eratosthenes to precompute primes
    static void sieve() {
        if (isSieveComputed) return;  // Ensure sieve runs only once

        isPrime.assign(MAX_LIMIT + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int num = 2; num <= MAX_LIMIT; ++num) {
            if (isPrime[num]) {
                primes.push_back(num);
                for (long long multiple = (long long)num * num; multiple <= MAX_LIMIT; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
        isSieveComputed = true;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        sieve();  // Ensure primes are precomputed

        // Use lower_bound to find the first prime >= left
        auto it = lower_bound(primes.begin(), primes.end(), left);

        // If no valid prime in range, return {-1, -1}
        if (it == primes.end() || *it > right) return {-1, -1};

        vector<int> closestPair = {-1, -1};
        int minDifference = INT_MAX;

        // Iterate through primes within [left, right]
        for (; it + 1 != primes.end() && *(it + 1) <= right; ++it) {
            int diff = *(it + 1) - *it;
            if (diff < minDifference) {
                minDifference = diff;
                closestPair = {*it, *(it + 1)};
                if (minDifference == 2) break; // Early exit
            }
        }

        return closestPair;
    }
};
// Static variable definitions
vector<bool> Solution::isPrime;
vector<int> Solution::primes;
bool Solution::isSieveComputed = false;
