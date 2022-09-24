class Solution {
public:
int getNumber(int row, int col)
{
    int sum = 0;
    while (row)
    {
        sum += row % 10;
        row /= 10;
    }
    while (col)
    {
        sum += col % 10;
        col /= 10;
    }
    return sum;
}
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
    int count=0;
    int number = getNumber(row, col);
    if (col >= 0 && col < cols && row >= 0 && row < rows && number <= threshold && !visited[row * cols + col])
    {
        visited[row * cols + col] = true;
        count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
            + movingCountCore(threshold, rows, cols, row + 1, col, visited)
            + movingCountCore(threshold, rows, cols, row, col - 1, visited)
            + movingCountCore(threshold, rows, cols, row, col + 1, visited);
    }
    return count;
}
    int movingCount(int threshold, int rows, int cols)
{
    bool* visited = new bool[rows * cols];
    int count = 0;
    memset(visited, 0, rows * cols);
    if (threshold<0||rows < 0 || cols < 0)
        return 0;
    count = movingCountCore(threshold, rows, cols, 0, 0, visited);
    return count;

}
};