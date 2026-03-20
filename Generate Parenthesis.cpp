/*
Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

*/

class Solution {
public:

void f(int n,int op,int cp,string temp,vector<string>&ans){
    if(op==cp && op+cp ==2*n){
        ans.push_back(temp);
        return;
    }
    if(op<n) f(n,op+1,cp,temp+"(",ans);
    if(cp<op) f(n,op,cp+1,temp+")",ans);
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        f(n,0,0,"",ans);
        return ans;
    }
};