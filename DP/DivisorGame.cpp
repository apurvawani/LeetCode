/*
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
Choosing any x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.


Example 1:
Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

Example 2:
Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 

Constraints:
1 <= n <= 1000
*/

//DP
class Solution {
public:
    
    vector<bool> dp;
    
    bool helper(int n) {
        if(n == 1)
            return false;
        if(dp[n])
            return dp[n];
        else {
            for(int i = 1 ; i <= sqrt(n) ; i++) {
                if(n%i == 0) {
                    if(!helper(n-i))
                        return dp[n] = true;
                    if((n/i != n) && !helper(n-(n/i)))
                        return dp[n] = true;
                }
            }   
        }
        return false;
    }
    
    bool divisorGame(int n) {
        dp.resize(1001, false);
        return helper(n);
    }
};


//Math
class Solution {
public:
    
    bool divisorGame(int n) {
        return (n%2 == 0);
    }
};