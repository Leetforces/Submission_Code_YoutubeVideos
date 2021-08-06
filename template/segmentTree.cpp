const int N = 100005;
int arr[N];
int tree[4 * N];
//int lazy[4 * N];
void build(int start, int end, int index)
{
    if (start == end)
        tree[index] = arr[start];
    else
    {
        int mid = start + (end - start) / 2;
        build(start, mid, 2 * index + 1);
        build(mid + 1, end, 2 * index + 2);
        //build logic according to question
        tree[index] = (tree[2 * index + 1]+ tree[2 * index + 2]);
    }
}
int query(int start, int end, int i, int j, int index)
{
    /*
    // if lazy update pending
    if (lazy[index] != 0)
    {
        int inc = lazy[index];
        lazy[index] = 0;
        tree[index] += inc * (end - start + 1);
        if (start != end)
        {
            lazy[2 * index + 1] += inc;
            lazy[2 * index + 2] += inc;
        }
    }
    */
    if (start > j || i > end)
        return 0; // return according to question
    else if (i <= start && j >= end)
        return tree[index];
    else
    {
        int mid = start + (end - start) / 2;
        int left = query(start, mid, i, j, 2 * index + 1);
        int right = query(mid + 1, end, i, j, 2 * index + 2);
        //return According to question
        return (left+ right);
    }
}
void pointUpdate(int start, int end, int i, int value, int index)
{
    if(start==end)
    {
        //according to question
        tree[index]=(tree[index]+value);
    }
    else{
        int mid=start+(end-start)/2;
        if(i<=mid)
        pointUpdate(start,mid,i,value,2*index+1);
        else
        pointUpdate(mid+1,end,i,value,2*index+2);
        //according to question
        tree[index]=(tree[2*index+1]+tree[2*index+2]);
     }
}
/*
void rangeUpdate(int start, int end, int i, int j, int value, int index)
{
    // if lazy update pending
    if (lazy[index] != 0)
    {
        int inc = lazy[index];
        lazy[index] = 0;
        tree[index] += inc * (end - start + 1);
        if (start != end)
        {
            lazy[2 * index + 1] += inc;
            lazy[2 * index + 2] += inc;
        }
    }
    if (start > j || i > end)
        return;
    else if (i <= start && j >= end)
    {
        tree[index] += (end - start + 1) * value;
        if (start != end)
        {
            // set lazy update 
            lazy[2 * index + 1] += value;
            lazy[2 * index + 2] += value;
        }
    }
    else
    {
        int mid = start + (end - start) / 2;
        rangeUpdate(start, mid, i, j, value, 2 * index + 1);
        rangeUpdate(mid + 1, end, i, j, value, 2 * index + 2);
        tree[index]=(tree[2*index+1]+tree[2*index+2]);
    }
}
*/

