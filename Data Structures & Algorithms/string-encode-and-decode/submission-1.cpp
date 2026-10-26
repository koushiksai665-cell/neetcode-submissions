class Solution {
public:
    string encode(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        vector<int> sizes;
        string res;

        // Store the length of each string
        for (string& s : strs) {
            sizes.push_back(s.size());
        }

        // Store all lengths separated by commas
        for (int sz : sizes) {
            res.append(to_string(sz));
            res.push_back(',');
        }

        // Separate lengths from actual strings
        res.push_back('#');

        // Append all strings
        for (string& s : strs) {
            res.append(s);
        }

        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) {
            return {};
        }

        vector<int> sizes;
        vector<string> res;
        int i = 0;

        // Extract the lengths before '#'
        while (s[i] != '#') {
            int j = i;

            // Find the next comma
            while (s[j] != ',') {
                j++;
            }

            // Convert the length from string to integer
            sizes.push_back(stoi(s.substr(i, j - i)));

            // Move past the comma
            i = j + 1;
        }

        // Skip '#'
        i++;

        // Extract each original string using its length
        for (int sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }

        return res;
    }
};