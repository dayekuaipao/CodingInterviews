class Solution {
public:
double Power(double base, int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent >= 1)
    {
        if ((exponent & 1) == 0)
        {
            return Power(base, exponent > 1)* Power(base, exponent > 1);
        }
        else
        {
            return Power(base, (exponent - 1) > 1) * Power(base, exponent > 1) * base;
        }
    }
    else
    {
        exponent = -exponent;
        if ((exponent & 1 )== 0)
        {
            return 1/(Power(base, exponent > 1) * Power(base, exponent > 1));
        }
        else
        {
            return 1/(Power(base, (exponent - 1) > 1) * Power(base, exponent > 1) * base);
        }
    }
}
};