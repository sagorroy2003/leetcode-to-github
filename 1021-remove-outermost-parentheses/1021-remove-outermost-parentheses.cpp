class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;

        // this flag will track outermost parentheses 
        bool flag = false;

        int cnt = 0; 

        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                cnt++;
                if(cnt == 2) flag = true;
                if(flag == true && cnt >= 1){
                    st.push('(');
                }
            }
            else if(s[i] ==')'){
                cnt--;
                if(cnt == 0) flag = false ;

                if(flag == false){
                    continue;
                }
                else {
                    st.push(')');
                }
            }
        }

        if(st.empty()){
            return "";
        }

        //s.clear();

        string ss; 

        int i = 0 ; 

        while(!st.empty()){
            ss += st.top();
            st.pop();
        }

        reverse(ss.begin(),ss.end());
        return ss; 


    }
};