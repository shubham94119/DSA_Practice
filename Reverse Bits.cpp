/*
Reverse Bits

Reverse bits of a given 32 bits signed integer.

 

Example 1:

Input: n = 43261596

Output: 964176192

Explanation:

Integer	Binary
43261596	00000010100101000001111010011100
964176192	00111001011110000010100101000000
Example 2:

Input: n = 2147483644

Output: 1073741822

Explanation:

Integer	Binary
2147483644	01111111111111111111111111111100
1073741822	00111111111111111111111111111110
 

Constraints:

0 <= n <= 231 - 2
n is even.
*/

class Solution {
public:
    int reverseBits(int n) {
        int temp=0;
        long c=1;
        string s="";
        for(int i=0;i<32;i++){
            temp*=10;
            if((c&n)!=0) s=s+'1';
            else s=s+'0';
            c*=2;
        }
        reverse(s.begin(),s.end());
        // cout<<s<<endl;
        for(int i=0;i<32;i++){
            if(s[i]=='1') temp=temp+pow(2,i);
        }
        return temp;
    }
};