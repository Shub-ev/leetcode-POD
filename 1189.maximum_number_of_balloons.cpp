/*
 * Problem: 1189. Maximum Number of Balloons
 * Difficulty: Easy
 * 
 * Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
 * You can use each character in text at most once. Return the maximum number of instances that can be formed.
 * 
 * Example 1:
 * Input: text = "nlaebolko"
 * Output: 1
 * 
 * Example 2:
 * Input: text = "loonbalxballpoon"
 * Output: 2
 * 
 * Example 3:
 * Input: text = "leetcode"
 * Output: 0
 * 
 * Constraints:
 * 1 <= text.length <= 104
 * text consists of lower case English letters only.
 */


// My solution:
// Time complexity: O(n)
// Space complexity: O(1)
// We use a map to count the occurrences of each character in the input string.
// We only care about the characters 'b', 'a', 'l', 'o', and 'n' since those are the characters needed to form the word "balloon".
// After counting, we divide the counts of 'l' and 'o' by 2 since we need two of each to form one instance of "balloon".
// Finally, we find the minimum count among these characters, which will give us the maximum number of instances of "balloon" that can be formed.
#include <string>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> ins;
        int lCount = 0;
        int oCount = 0;

        ins['b']; ins['l']; ins['o']; ins['a']; ins['n'];

        for(char ch: text) {
            if(ch != 'b' && ch != 'a' && ch != 'l' && ch != 'o' && ch != 'n') continue;
            else ins[ch]++;
        }

        ins['l'] = ins['l']/2;
        ins['o'] = ins['o']/2;

        int ans = INT_MAX;
        for(auto& pair: ins) {
            if(ans > pair.second) ans = pair.second;
        }

        return ins.empty() ? 0 : ans;

    }
};



// Another solution:
// Time complexity: O(n)
// Space complexity: O(1)
// We use an array of size 5 to count the occurrences of the characters 'b', 'a', 'l', 'o', and 'n' in the input string.
// After counting, we divide the counts of 'l' and 'o' by 2 since we need two of each to form one instance of "balloon".
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ins[5] = {0};
        string s = "balon";
        for(char ch: text)
            for(int i = 0; i < 5; i++)
                ins[i] += !(ch ^ s[i]);

        return min({ins[0], ins[1], ins[2]>>1, ins[3]>>1, ins[4]});
    }
};