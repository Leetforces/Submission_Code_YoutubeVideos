int getSum(vector<int> &bit, int index)
{
    int sum = 0; // Iniialize result
    index = index + 1;
    while (index > 0)
    {
        sum += bit[index];
        index -= index & (-index); // go to parent (index=index&(index-1)) remove last set bits
    }
    return sum;
}
int rangeSum(vector<int> &bit, int i, int j)
{
    return getSum(bit, j) - getSum(bit, i - 1);
}
void updateBIT(vector<int> &bit, int n, int index, int val)
{
    index = index + 1; // 1 based indexing
    while (index <= n)
    {
        bit[index] += val;
        index += index & (-index); // go to next with adding mask of last set bit of index
    }
}
vector<int> constructbit(vector<int> &arr, int n)
{
    vector<int> bit(n + 1); // 1 based indexing
    for (int i = 0; i < n; i++)
        updateBIT(bit, n, i, arr[i]);
    return bit;
}

