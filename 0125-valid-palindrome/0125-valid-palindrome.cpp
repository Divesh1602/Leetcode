class Solution {
public:
    bool isPalindrome(string s) {
        std::string lowercase = "";

        for ( auto i : s ) {
            char lowChar = tolower( i );

            if ( (lowChar - 0 >= 48 and lowChar - 0 <= 57 ) or (lowChar - 0 >= 97 and lowChar - 0 <= 122) )
                lowercase += lowChar;
        }

        int length = lowercase.size() - 1;
        
        for ( int i = length, j{}; i >= 0 or j < length; --i, ++j ) {        
            if ( lowercase[i] != lowercase[j] )
                return false;
        }

        return true;
    }
};