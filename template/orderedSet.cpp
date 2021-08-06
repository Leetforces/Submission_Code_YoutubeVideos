#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
//find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time
// others operation is same as set
//to make it work for repeated element, Use less_equal instead of less