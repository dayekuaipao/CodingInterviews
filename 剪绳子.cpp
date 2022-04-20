class Solution {
public:
    int cutRope(int number) {
        vector<int> products;
        products.resize(number+1);
        if (number < 2)
            return 0;
        if (number == 2)
            return 1;
        if (number == 3)
            return 2;
        int max = 0;
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;
        for (int i = 4; i <= number; ++i)
        {
            for (int j = 0; j <= number / 2; ++j)
            {
                if (max < products[j] * products[i - j])
                {
                    max = products[j] * products[i - j];
                }
            }
            products[i] = max;
        }
        max = products[number];
        return max;
    }
};