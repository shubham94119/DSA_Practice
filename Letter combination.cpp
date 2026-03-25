/*
Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/

class Solution {
public:
void f(int ind,string digits,vector<string>&mp,vector<string>&ans,string &temp){
    if(ind==digits.size()){
        ans.push_back(temp);
        return;
    }
    string t=mp[digits[ind]-'0'];
    for(int i=0;i<t.size();i++){
        temp.push_back(t[i]);
        f(ind+1,digits,mp,ans,temp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string temp="";
        f(0,digits,mp,ans,temp);
        return ans;
        
    }
};