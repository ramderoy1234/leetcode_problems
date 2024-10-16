class Solution {
public:
    
string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size()) {
        return s;
    }

    vector<string> rows(min(numRows, int(s.size())));  // To store characters for each row
    int currRow = 0;
    bool goingDown = false;  // To track direction (down or up)

    // Iterate over the characters in the string
    for (char c : s) {
        rows[currRow] += c;  // Add the character to the current row
        // If we reach the top or bottom row, change direction
        if (currRow == 0 || currRow == numRows - 1) {
            goingDown = !goingDown;
        }
        // Move to the next row (down or up depending on the direction)
        currRow += goingDown ? 1 : -1;
    }

    // Combine all the rows to form the final string
    string result;
    for (string row : rows) {
        result += row;
    }

    return result;
}
};