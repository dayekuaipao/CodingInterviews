class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> stackInt;
        int j = 0;
        for (int i = 0; i < popV.size(); ++i)
        {
            if (stackInt.empty() || popV[i] != stackInt.top())
            {
                bool flag = false;
                while(j < pushV.size() )
                {
                     
                    if (pushV[j] == popV[i])
                    {
                        break;
                    }          
                    else
                    {
                        stackInt.push(pushV[j]);
                        ++j;
                    }
                }
                if (j == pushV.size())
                {
                    return false;
                }
                else
                {
                    ++j;
                }
            }
            else if (popV[i] == stackInt.top())
            {
                stackInt.pop();
            }      
        }
        return true;
    }
};