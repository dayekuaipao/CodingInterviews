class Solution {
public:
int partition(vector<int>& vec, int begin, int end)
{
    int pivot = vec[end];
    int i = begin;
    for(int j = begin;j<end;++j)
    {
        if (vec[j] < pivot)
        {
            swap(vec[i], vec[j]);
            ++i;
        }
    }
    swap(vec[i], vec[end]);
    return i;
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> least;
    int pivot = -1;
    int begin = 0;
    int end = input.size() - 1;
    if (k == 0||input.size() <k )
    {
        return least;
    }
    while (pivot != k - 1)
    {
        pivot = partition(input, begin, end);
        if (pivot < k - 1)
        {
            begin = pivot + 1;
        }
        else
        {
            end = pivot - 1;
        }
    }
    least.insert(least.begin(), input.begin(), input.begin() + k);
    return least;
}
};