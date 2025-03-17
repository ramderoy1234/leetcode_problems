class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // Extract start and end times
        string start1 = event1[0], end1 = event1[1];
        string start2 = event2[0], end2 = event2[1];

        // If event2 starts before event1 ends AND event1 starts before event2 ends, they overlap
        return !(end1 < start2 || end2 < start1);
    }
};
