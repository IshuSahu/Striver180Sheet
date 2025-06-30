vector<int> compute(string s) {
    int n = s.length();
    vector<int> result(n, 0);
    int len = 0;

    for (int i = 1; i < n; ) {
        if (s[i] == s[len]) {
            len++;
            result[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = result[len - 1];  
            } else {
                result[i] = 0;
                i++;
            }
        }
    }
    cout<<endl;
    return result;
}
