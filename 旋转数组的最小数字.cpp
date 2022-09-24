class Solution {
public:
int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.size() == 0)
        return 0;
    vector<int>::iterator begin = rotateArray.begin(), end = rotateArray.end();
    while (begin != end-1)
    {
        vector<int>::iterator mid = (end - begin) / 2 + begin;
        if (*mid > * begin && *mid < *(end-1))
        {
            end = mid;
        }
        if (*mid > * (end - 1) && *mid < *begin)
        {
            begin = mid;
        }
        else
        {
            int min = *begin;
            for (vector<int>::iterator iter = begin+1; iter != end; ++iter)
            {
                if (*iter < min)
                {
                    min = *iter;
                }
            }
            return min;
        }
    }
    return (*begin);
}
};