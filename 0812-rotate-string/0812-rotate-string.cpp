class Solution {
public:
    bool rotateString(string s, string goal) {
        // return s.size() == goal.size() && ((s + s).find(goal) != string::npos);
        if(s.size()==goal.size()){
           if((s+s).find(goal)!=string::npos){
            return true;
           }
        }
        return false;
    }
};

