class Solution {
public:
    bool isValid(string s) {
        int l = s.length();
        vector<char> v;
        int sum = 0;
        v.push_back('.');
        for(int i=0;i<l;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                v.push_back(s[i]);
                sum++;
            }
            else{
                if(v.back()=='.'){
                    return 0;
                }
                else if(v.back()== '(' && s[i]!=')'){
                    return 0;
                }
                else if(v.back()== '[' && s[i]!=']'){
                    return 0;
                }
                else if(v.back()== '{' && s[i]!='}'){
                    return 0;
                }
                else{
                    v.pop_back();
                    sum--;
                }
            }
        }
        return (sum>0?0:1);
    }    
};
