/*
 *Descripción:* Encuentra la rotación lexicográficamente menor de un string, en $O(n)$
*/
string minRotation(string &s) {
  int a = 0, n = sz(s);
  string res = s; s += s;
  for (int b = 0; b < n; b++) {
    for (int k = 0; k < n; k++) {
      if (a + k == b || s[a + k] < s[b + k]) {
        b += max(0, k - 1); break;
      }
      if (s[a + k] > s[b + k]) {
        a = b; break;
      }
    }
  }
  rotate(res.begin(), res.begin() + a, res.end());
  return res;
}