class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i = 0;
        while(s[i] != '\0'){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(s[i]==')'){
                    if(st.empty())return false;
                    if(st.top() != '(')return false;
                    st.pop();
                }
                else if(s[i]==']'){
                    if(st.empty())return false;
                    if(st.top() != '[')return false;
                    st.pop();
                }
                else{
                    if(st.empty())return false;
                    if(st.top() != '{')return false;
                    st.pop();
                }
            }
            i++;
        }
        if(st.empty())return true;
        return false;
    }
};