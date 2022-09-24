class Solution {
public:
    int jumpFloor(int number) {
        int f1 = 1;
        int f2 = 1;
        if (number == 0)
            return f1;
        if (number == 1)
            return f2;
        else
        {
            for (int i = 2; i <= number; ++i)
            {
                int tmp = f1;
                f1 = f2;
                f2 = tmp + f2;
            }
        }
        return f2;
    }
};