#include <bits/stdc++.h>
using namespace std;

int longest_prefix_suffix(string s) {
    // get set of all prefixes
    set<string> prefixes;
    for (int i = 1; i <= s.length(); i++)
        // reverse because we are comparing backwards
        prefixes.insert(s.substr(0, i).reverse());
    
    // loop through every index and figure out the longest prefix/suffix
    int longest[s.length()] = {0};
    
    // we start from i = 1, because i = 0 has no possible prefix
    for (int i = 1; i < s.length(); i++) {
        string temp = "";
        for (int j = i; j >= 0; j--) {
            temp += s[j];
            // search for it in the prefixes array
            if (prefixes.find(temp) != prefixes.end()) {
                longest[i] = max(longest[i], i - j + 1);
            }
        }
    }
}


int main() {
    vector<int> d = {4, 4, 5, 2, 6, 5, 1, 3, 5};
    cout << partition(d, 13, 9) << endl;

}
