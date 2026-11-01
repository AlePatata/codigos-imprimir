/*
 *Descripción:* Aho-Corasick, generalización de KMP a múltiples patrones, con memoización
 *Complejidad:* Construccion: $O(N)$ con $N$ el largo total de los patrones
*/
struct AhoCorasick {
  struct Vertex {
    int next[26], go[26];
    int p, link = -1;
    vector<int> leaf;
    char pch;
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
      for (int i = 0; i < 26; i++) next[i] = -1, go[i] = -1;
    }
  };
  vector<Vertex> t = vector<Vertex>(1);
  void add(string &s, int id) {
    int v = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (t[v].next[c] == -1) {
        t[v].next[c] = sz(t);
        t.emplace_back(v, ch);
      }
      v = t[v].next[c];
    }
    t[v].leaf.push_back(id);
  }
  int get_link(int v) {
    if (t[v].link == -1) {
      if (v == 0 || t[v].p == 0) t[v].link = 0;
      else t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
  }
  int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
      if (t[v].next[c] != -1) t[v].go[c] = t[v].next[c];
      else t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
  }
};

