// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
// we may just use brutal force and check each deleted string, but that would cause TLE
// So we use two-pointers algorithm

bool isValid(string &s, int l , int r, int cnt){
        while(l < r){
            if(s[l] == s[r]){
                l++; r--;
            }
            else if(cnt){
                return isValid(s, l+1, r, 0) || isValid(s, l, r-1, 0);
            }
            else return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return true;
        return isValid(s, 0, n-1, 1);
    }
