class Solution {
public:
bool Verify(vector<int>::iterator begin, vector<int>::iterator end)
{
    if (begin == end)
        return true;
    int val = *(end);
    vector<int>::iterator iter = begin;
    while (iter < end)
    {
        if ((*iter) > val)
            break;
        ++iter;
    }
    vector<int>::iterator iter2 = iter;
    while (iter2 < end)
    {
        if ((*iter2) < val)
            return false;
        ++iter2;
    }
    bool flag1 = true;
    bool flag2 = true;
    if (iter > begin)
        flag1 = Verify(begin, iter - 1);
    if (end > iter)
        flag2= Verify(iter, end - 1);
    return  flag1 && flag2;
}
bool VerifySquenceOfBST(vector<int> sequence)
{
    if (sequence.empty())
        return false;
    vector<int>::iterator begin = sequence.begin();
    vector<int>::iterator end = sequence.end() - 1;
    return Verify(begin, end);
}
};