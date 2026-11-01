/*
  *Descripción:* Encuentra las ocurrencias de un patrón en un texto, en $O(n + m)$, donde $n$ y $m$ son los largos del texto y del patrón respectivamente.
*/
template<class T> struct KMP {
  T pattern; vector<int> lps;
  KMP(T &pat): pattern(pat) {
    lps.resize(pat.size(), 0);
    int len = 0, i = 1;
    while (i < sz(pattern)) {
      if (pattern[i] == pattern[len])
        lps[i++] = ++len;
      else {
        if (len != 0) len = lps[len - 1];
        else lps[i++] = 0;
      }
    }
  }
  vector<int> search(T &text) {
    vector<int> matches;
    int i = 0, j = 0;
    while (i < sz(text)) {
      if (pattern[j] == text[i]) {
        i++, j++;
        if (j == sz(pattern)) {
          matches.push_back(i - j);
          j = lps[j - 1];
        }
      } else {
        if (j != 0) j = lps[j - 1];
        else i++;
      }
    }
    return matches;
  }
};
