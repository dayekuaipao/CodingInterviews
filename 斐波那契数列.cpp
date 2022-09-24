class Solution {
public:
    int Fibonacci(int n) {
        int f1 = 0;
        int f2 = 1;
        if (n == 0)
            return f1;
        if (n == 1)
            return f2;
        else
        {
            for (int i = 2; i <= n; ++i)
            {
                int tmp = f1;
                f1 = f2;
                f2 = tmp + f2;
            }
        }
        return f2;
    }
};