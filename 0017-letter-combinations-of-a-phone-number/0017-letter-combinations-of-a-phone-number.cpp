class Solution {
    void recursion(string digits,int i, string output, vector<string>&ans,string mapping[]){
        if(i>=digits.size()){
            ans.push_back(output);
            return ;
        }
        int num=digits[i]-'0';
        string value=mapping[num];
        for(int j=0;j<value.size();j++){
            output.push_back(value[j]);
            recursion(digits,i+1,output,ans,mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0) return ans;
        string mapping[10] = {"",    "",    "abc",  "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output;
        recursion(digits,0,output,ans,mapping);
        return ans;
    }
};