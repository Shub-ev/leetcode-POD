/*
 * Implementation of Fenwick Tree (Binary Indexed Tree) in C++
 * 
 * Here we will implement a Fenwick Tree (also known as Binary Indexed Tree) in C++.
 * A Fenwick Tree is a data structure that provides efficient methods for cumulative frequency tables or prefix sums.
 * It allows for both point updates and prefix sum queries in logarithmic time.
*/

#include <iostream>
#include <vector>
using namespace std;

// ============================================================================
// Fenwick Tree (Binary Indexed Tree - BIT)
// ============================================================================
// A Fenwick Tree is a data structure used to efficiently maintain cumulative
// information over an array, most commonly prefix sums.
//
// It supports:
// 1. Point Update:
//      Add a value to a single array element.
//      Time Complexity: O(log n)
//
// 2. Prefix Sum Query:
//      Compute sum of elements from index 0 to index i.
//      Time Complexity: O(log n)
//
// 3. Range Sum Query:
//      Sum of elements in range [l, r].
//      rangeSum(l, r) = prefixSum(r) - prefixSum(l - 1)
//      Time Complexity: O(log n)
//
// ---------------------------------------------------------------------------
// Why not use a normal array?
// ---------------------------------------------------------------------------
// Normal Array:
//      Update      -> O(1)
//      Prefix Sum  -> O(n)
//
// Prefix Sum Array:
//      Prefix Sum  -> O(1)
//      Update      -> O(n)
//
// Fenwick Tree:
//      Update      -> O(log n)
//      Prefix Sum  -> O(log n)
//
// Thus Fenwick Tree is useful when updates and queries occur frequently.
//
// ---------------------------------------------------------------------------
// Internal Representation
// ---------------------------------------------------------------------------
// The tree is stored as a 1-indexed array.
//
// Example:
// Original Array:
//      Index: 0 1 2 3 4 5 6 7
//      Value: 1 2 3 4 5 6 7 8
//
// Fenwick Tree:
//      tree[1]
//      tree[2]
//      tree[3]
//      ...
//
// Each tree node stores the sum of a specific range of elements.
// The range size is determined by:
//      index & (-index)
// which extracts the Least Significant Set Bit (LSSB).
//
// ---------------------------------------------------------------------------
// Meaning of index & (-index)
// ---------------------------------------------------------------------------
// Example:
//      index = 12
//      binary = 1100
//
//      -index = 0100 (two's complement effect)
//
//      index & (-index) = 0100 = 4
//
// This means tree[12] is responsible for a range of size 4.
//
// ---------------------------------------------------------------------------
// Range Covered By Each Node
// ---------------------------------------------------------------------------
// Node i stores:
//      [ i - LSB(i) + 1 , i ]
//
// Example:
//      tree[8]
//      LSB(8) = 8
//      Covers:
//      [1 .. 8]
//
// Example:
//      tree[12]
//      LSB(12) = 4
//      Covers:
//      [9 .. 12]
//
// Example:
//      tree[6]
//      LSB(6) = 2
//      Covers:
//      [5 .. 6]
//
// ---------------------------------------------------------------------------
// Update Operation
// ---------------------------------------------------------------------------
// When arr[index] changes, all Fenwick Tree nodes whose ranges contain that
// index must be updated.
//
// We move upward using:
//      index += index & (-index)
//
// Example:
//      index = 5
//      5 -> 6 -> 8 -> 16 -> ...
//
// Every visited node contains index 5 in its represented range.
//
// Complexity:
//      O(log n)
//
// ---------------------------------------------------------------------------
// Prefix Sum Query
// ---------------------------------------------------------------------------
// To compute prefix sum [0 .. index], we move upward toward the root by
// removing the least significant set bit:
//      index -= index & (-index)
//
// Example:
//      index = 13
//      13 -> 12 -> 8 -> 0
//
// Summing:
//      tree[13]
//      tree[12]
//      tree[8]
//
// gives the prefix sum efficiently.
// Complexity:
//      O(log n)
//
// ---------------------------------------------------------------------------
// Memory Complexity
// ---------------------------------------------------------------------------
//      O(n)
// Only one extra array of size n + 1 is required.
//
// ---------------------------------------------------------------------------
// Advantages
// ---------------------------------------------------------------------------
// + Simpler than Segment Tree
// + Less memory usage (O(n))
// + Fast updates and prefix/range sum queries
// + Easy to implement
//
// ---------------------------------------------------------------------------
// Limitations
// ---------------------------------------------------------------------------
// - Best suited for operations based on cumulative values
//   (sum, frequency count, etc.)
//
// - Less flexible than Segment Tree for complex range operations.
//
// ---------------------------------------------------------------------------
// Common Applications
// ---------------------------------------------------------------------------
// * Prefix Sum Queries
// * Range Sum Queries
// * Frequency Tables
// * Inversion Count
// * Order Statistics
// * Competitive Programming
// * Dynamic cumulative data maintenance
//
// Time Complexity Summary:
//      Build (using updates)     : O(n log n)
//      Point Update              : O(log n)
//      Prefix Sum Query          : O(log n)
//      Range Sum Query           : O(log n)
//      Space                     : O(n)
// ============================================================================


class FenwickTree {
    private:
        std::vector<int> tree;

    public:
        FenwickTree(vector<int>& data) {
            int n = data.size();
            tree.resize(data.size() + 1, 0);

            for (int i = 0; i < n; i++) {
                update(i, data[i]);
            }
        }

        void update (int index, int data) {
            index++;
            while (index < tree.size()) {
                tree[index] += data;
                index += index & (-index);
            }
        }

        int prefix(int index) {
            index++;

            int sum = 0;
            while(index > 0) {
                sum += tree[index];
                index -= index & (-index);
            }
            return sum;
        }

        void print_tree() {
            for(int num: tree) {
                cout << num << " ";
            }
            cout << endl;
        }
};

int main() {
    vector<int> arr({1, 3, 5, 7, 9, 11, 13, 15});
    FenwickTree* ft = new FenwickTree(arr);

    ft->print_tree();
    // prefix sum of range 1-5 -> r - (l - 1)
    cout << "Prefix sum: " << (ft->prefix(5) - ft->prefix(1-1));
    return 0;
}