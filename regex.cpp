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
