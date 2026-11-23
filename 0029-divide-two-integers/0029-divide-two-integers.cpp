class Solution {
public:
    int divide(int dividend, int divisor) {
        // The only case where the quotient overflows 32-bit signed INT_MAX
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine if the final result should be negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to negative to avoid overflow (INT_MIN has no positive counterpart)
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        // Half of INT_MIN (-2^30), used to prevent overflow when doubling
        const int HALF_INT_MIN = -1073741824;
        int quotient = 0;

        // While |dividend| >= |divisor| (in negative space, dividend <= divisor)
        while (dividend <= divisor) {
            int value = divisor;
            int powerOfTwo = -1;

            // Double value and powerOfTwo as long as value * 2 fits and doesn't pass dividend
            while (value >= HALF_INT_MIN && value + value >= dividend) {
                value += value;
                powerOfTwo += powerOfTwo;
            }

            dividend -= value;
            quotient += powerOfTwo;
        }

        // quotient is currently negative (or 0); flip sign if the result should be positive
        return isNegative ? quotient : -quotient;
    }
};