// Recursive
bool isMatchRec(string s, string p, int i, int j){
    if(j>=p.size()) {
        if(i==s.size()) return true;
        else return false;
    }
    bool firstMatch = (i<s.size()) && ((s[i]==p[j])|| (p[j] == '.'));
    if(j+1<p.size() && p[j+1] == '*') {
        return isMatchRec(s, p, i, j+2) || (firstMatch && isMatchRec(s, p, i+1, j));
    }
    else {
        return firstMatch && isMatchRec(s, p, i+1, j+1);
    }
}

//top down memoization
bool isMatchRec(string s, string p, int i, int j, vector<vector<int>> &dp) {
    if(j==p.size()) return i==s.size();
    if(dp[i][j]!=-1)  return dp[i][j];
    bool firstMatch = (i<s.size()) && (s[i] == p[j] || (p[j] == '.'));
    bool ans;
    if(j+1< p.size() && p[j+1] == '*') {
        ans = isMatchRec(s, p, i, j+2, dp) || (firstMatch && isMatchRec(s, p, i+1, j, dp));
    }
    else {
        ans = firstMatch && isMatchRec(s, p, i+1, j+1, dp);
    }
    dp[i][j] = ans;
    return ans;
}
vector<vector<int>> dp(m+1, vector<int>(n+1,-1));        


