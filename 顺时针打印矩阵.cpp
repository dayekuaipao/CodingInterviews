class Solution {
public:
void printCircle(const vector<vector<int> >& matrix, vector<int>& m,int startx, int endx,int starty,int endy)
{
    for (int i = startx; i <= endy; ++i)
    {
        m.push_back(matrix[startx][i]);
    }
    if (endx>startx)
    {
        for (int i = startx+1; i <= endx; ++i)
        {
            m.push_back(matrix[i][endy]);
        }
    }
    if (endx > startx && endy > starty)
    {
        for (int i = endy - 1; i >= starty; --i)
        {
            m.push_back(matrix[endx][i]);
        }
    }
    if (endx > startx + 1&& endy > starty)
    {
        for (int i = endx - 1; i > startx; --i)
        {
            m.push_back(matrix[i][starty]);
        }
    }
}
vector<int> printMatrix(vector<vector<int> > matrix)
{
    vector<int> m;
    int startx = 0,starty=0,endx=matrix.size()-1,endy=matrix[0].size()-1;
    while (startx <= endx && starty <= endy)
    {
        printCircle(matrix,m, startx, endx, starty, endy);
        ++startx;
        --endx;
        ++starty;
        --endy;
    }
    return m;
}
};
