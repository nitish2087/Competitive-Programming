// Valid parantheses

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
*/

/*
Solution:
Create two list and do following operations as you traverse the parentheses string:
l1 = ['(', '[', '{'] - insert in stack
l2 = [')', ']', '}'] - pop if key in map match with top element, else return false.
map= { ')' : '(', ']' : '[', '}' : '{'}
If stack is empty in end, return else false.
*/

class Solution {
    public boolean isValid(String s) {
        List<Character> l1 = Arrays.asList('(', '[', '{');
        List<Character> l2 = Arrays.asList(')', ']', '}');
        Map<Character,Character> mp = new HashMap<>();
        mp.put(')','(');
        mp.put('}','{');
        mp.put(']', '[');
        char[] ch = s.toCharArray();
        Stack<Character> st = new Stack<Character>();
        for (Character c: ch) {
            if (l1.contains(c)) {
                st.push(c);
            } else if (l2.contains(c)) {
                if (!st.empty() && mp.get(c) == st.peek()) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty() ? true : false;
    }
}
