int l=0,r=0;
unordered_map<char,int>m;
unordered_map<string,int>Ans_String;

while(r<n){
    m[a[r]]++;
    if(m.size() > 2){
        while(m.size()>2){
            m[a[l]]--;
            if(m[a[l]] == 0)m.erase(a[l]);
            l++;
        }
    }
    maxlen = max(maxlen,r-l+1);
    string result = a.substr(l,r-l+1);
    Ans_String[result] = maxlen;
    r++
}

now print string with
