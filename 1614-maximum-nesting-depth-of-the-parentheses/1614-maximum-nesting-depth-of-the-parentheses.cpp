class Solution {
public:
    int maxDepth(string s) {
        int _size = 0;
        int ans = 0; 

        stack<char> st;

        for(int i = 0 ; i<s.size(); i++){
            if(s[i] == '('){
                st.push('(');
                _size = st.size();
                ans = max(ans,_size);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
                _size = st.size();
                ans = max(ans, _size);
            }
        }

        return ans ; 
    }

};