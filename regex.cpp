    bool regx_match_rec(const string& text, const string& pattern, int i, int j) {
        if (pattern.length() == j) {
            if (text.length() == i)
                return true;
            else
                return false;
        }

        if (j < pattern.length() - 1 && pattern[j + 1] == '*') {
            for (int k = i; k <= text.length(); ++k) {
                if (regx_match_rec(text, pattern, k, j + 2))
                    return true;
                if (pattern[j] != '.' && text[k] != pattern[j])
                    return false;
            }
        }
        else if (i < text.length() && j < pattern.length() && (pattern[j] == '.' || pattern[j] == text[i])) {
                return regx_match_rec(text, pattern, i + 1, j + 1);
        }

        return false;
    }
        
