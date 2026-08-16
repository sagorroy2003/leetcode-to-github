class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapST[256];
        int mapTS[256];
        
        fill(mapTS, mapTS + 256 , -1);
        fill(mapST, mapST + 256, -1);


        for (int i = 0; i < s.size(); i++) {
            if (mapST[s[i]] == -1 && mapTS[t[i]] == -1) // both not mapped
            {
                mapST[s[i]] = t[i];
                mapTS[t[i]] = s[i];
            } 
            else if(mapST[s[i]] != -1 && mapST[s[i]] != t[i]){
                return false;
            }
            else if(mapTS[t[i]] != -1 && mapTS[t[i]] != s[i]){
                return false;
            }
        }


        return true; 
    }
};