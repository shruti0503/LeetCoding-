class Solution {
public:
   

string generateString(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    int len = n + m - 1;

    vector<char> word(len, '?');

    // Step 1: Apply all 'T'
    for (int i = 0; i < n; i++) {
        if (str1[i] == 'T') {
            for (int j = 0; j < m; j++) {
                if (word[i + j] == '?' || word[i + j] == str2[j]) {
                    word[i + j] = str2[j];
                } else {
                    return ""; // conflict
                }
            }
        }
    }

    // Step 2: Fill remaining with 'a'
    for (int i = 0; i < len; i++) {
        if (word[i] == '?') word[i] = 'a';
    }

    // Helper: check all T constraints still valid
    auto validT = [&](vector<char>& w) {
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (w[i + j] != str2[j]) return false;
                }
            }
        }
        return true;
    };

    // Step 3: Fix 'F'
    for (int i = 0; i < n; i++) {
        if (str1[i] == 'F') {
            bool match = true;

            for (int j = 0; j < m; j++) {
                if (word[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                bool fixed = false;

                // try to break from right to left
                for (int j = m - 1; j >= 0 && !fixed; j--) {
                    char original = word[i + j];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;

                        word[i + j] = c;

                        // check F condition broken
                        bool stillMatch = true;
                        for (int k = 0; k < m; k++) {
                            if (word[i + k] != str2[k]) {
                                stillMatch = false;
                                break;
                            }
                        }

                        // also ensure T constraints still valid
                        if (!stillMatch && validT(word)) {
                            fixed = true;
                            break;
                        }
                    }

                    if (!fixed) word[i + j] = original; // revert
                }

                if (!fixed) return "";
            }
        }
    }

    return string(word.begin(), word.end());
}
};