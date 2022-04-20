class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty())
        {
            return 0;
        }
        int count = 1;
        int num = numbers[0];
        for (int i = 1; i < numbers.size(); ++i)
        {
            if (count == 0)
            {
                num = numbers[i];
                count = 1;
            }
            else if (numbers[i] == num)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }
            count = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] == num)
            {
                ++count;
            }
            if (count * 2 > numbers.size())
            {
                return num;
            }
        }
        return 0;
    }
};