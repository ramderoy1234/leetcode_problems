class Solution {
  void recursion(int i, string &digits,string &curr,vector<string>&ans, string mapping[]){
    if(i>=digits.size()){
      ans.push_back(curr);
      return ;
    }
    int num=digits[i]-'0';
    string value=mapping[num];
    for(int j=0;j<value.size();j++){
      curr.push_back(value[j]);
      recursion(i+1,digits,curr,ans,mapping);
      curr.pop_back();
    }

  }
public:
    vector<string> letterCombinations(string digits) {
       vector<string>ans;
        if(digits.size()==0) return ans;
        string curr;
        string mapping[10] = {"",    "",    "abc",  "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        recursion(0,digits,curr,ans,mapping);
        return ans;
    }
};