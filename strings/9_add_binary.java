// Add binary

/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:
1 <= a.length, b.length <= 10^4
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

// Solution : 0
class Solution {
    public String addBinary(String a, String b) {
        if (a == null || a == "") return b;
        if (b == null || b == "") return a;
        StringBuilder result = new StringBuilder();
        StringBuilder aS = new StringBuilder();
        aS.append(a);
        a = aS.reverse().toString();
        aS.replace(0, a.length(), b);
        b = aS.reverse().toString();
        char carry = '0';
        int i = 0;
        for (; i < b.length() && i < a.length(); i++) {
            if (b.charAt(i) == a.charAt(i)) {
                if ( b.charAt(i) == '0') {
                    result.append(carry == '0' ? '0' : carry);
                    carry = '0';
                } else {
                    result.append(carry == '0' ? '0' : '1');
                    carry = '1';
                }
                
            } else {
                result.append(carry == '1' ? '0' : '1');
            }
        }
        if (a.length() > b.length()) {
            for (; i < a.length(); i++) {
                if (carry == '1') {
                    if (a.charAt(i) == '0') {
                        result.append('1');
                        carry = '0';
                    } else {
                        result.append('0');
                        carry = '1';
                    }
                } else {
                    result.append(a.charAt(i));
                }
            }
        }
        if (b.length() > a.length()) {
            for (; i < b.length(); i++) {
                if (carry == '1') {
                    if (b.charAt(i) == '0') {
                        result.append('1');
                        carry = '0';
                    } else {
                        result.append('0');
                        carry = '1';
                    }
                } else {
                    result.append(b.charAt(i));
                }
            }
        }
        if (carry == '1') {
            result.append(carry);
        }
        return result.reverse().toString();
    }
}

/*
Solution : 1

class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int i = a.length() - 1, j = b.length() -1, carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (j >= 0) sum += b.charAt(j--) - '0';
            if (i >= 0) sum += a.charAt(i--) - '0';
            sb.append(sum % 2);
            carry = sum / 2;
        }
        if (carry != 0) sb.append(carry);
        return sb.reverse().toString();
    }
}
*/
