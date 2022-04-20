class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> vec;
        if(!str.empty())
        {
            PermutationCore(str, 0, vec);
        }
        return vec;
    }
    void PermutationCore(string str,int begin,vector<string>& vec)
    {
        if (begin == str.length() - 1)
        {
            vec.push_back(str);
        }
        else
        {
            for (int i = begin; i < str.length(); ++i)
            {
                if (begin == i || str[begin] != str[i])
                {
                    swap(str[begin], str[i]);
                    PermutationCore(str, begin + 1, vec);
                }
            }
        }
    }
};