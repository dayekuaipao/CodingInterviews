class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int x = array.size()-1;
        int y = array[0].size()-1;
        int tmpx = 0, tmpy = y;
        while (tmpx <= x && tmpy >= 0)
        {
            if (array[tmpx][tmpy] == target)
            {
                return true;
            }
            if(array[tmpx][tmpy] < target)
            {
                ++tmpx;
            }
            else if(array[tmpx][tmpy] > target)
            {
                --tmpy;
            }
        }
        return false;
    }
};