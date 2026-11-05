/*
 *Descripción:* Aho-Corasick construido con BFS, busca todas las apariciones de varios patrones en un texto. \
 `find(word)[i]` es el índice del patrón más largo que termina en la posición `i` (o `-1`). \
 `findAll(pat, word)[i]` son todos los patrones que empiezan en la posición `i`. \
 `nmatches` (opcional) cuenta cuántos patrones terminan en cada nodo. \
 Cambiar `alpha` y `first` según el alfabeto. Los patrones no pueden ser vacíos.
 *Complejidad:* Construcción: $O(N dot "alpha")$ con $N$ el largo total de los patrones. `find`: $O(|"word"|)$. `findAll`: $O(|"word"| + "ocurrencias")$
*/
struct AhoCorasick {
  enum { alpha = 26, first = 'a' }; // cambiar esto!
  struct Node {
    int back, next[alpha], start = -1, end = -1, nmatches = 0;
    // uint32_t real = 0;
    //int pref = 0, terminal = 0;
    Node(int v) { memset(next, v, sizeof(next)); }
  };
  vector<Node> N;
  vector<int> backp;
  void insert(string &s, int j) {
    assert(!s.empty());
    int n = 0;
    for (char c : s) {
      int &m = N[n].next[c - first];
      if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
      else n = m;
    }
    if (N[n].end == -1) N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
    N[n].nmatches++;
  }

  /*void insert(string &s, int j) {
    assert(!s.empty());

    int v = 0;
    N[v].pref++;

    for (char c : s) {
        int x = c - first;
        int m = N[v].next[x];

        if (m == -1) {
            m = sz(N);
            N[v].next[x] = m;
            N[v].real |= (1u << x);
            N.emplace_back(-1);
        }

        v = m;
        N[v].pref++;
    }

    N[v].terminal++;

    // Parte original de Aho-Corasick
    if (N[v].end == -1) N[v].start = j;
    backp.push_back(N[v].end);
    N[v].end = j;
    N[v].nmatches++;
}*/

  AhoCorasick(vector<string> &pat) : N(1, -1) {
    for (int i = 0; i < sz(pat); i++) insert(pat[i], i);
    N[0].back = sz(N);
    N.emplace_back(0);
    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      for (int i = 0; i < alpha; i++) {
        int &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1) ed = y;
        else {
          N[ed].back = y;
          (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
          N[ed].nmatches += N[y].nmatches;
          q.push(ed);
        }
      }
    }
  }
  vector<int> find(string word) {
    int n = 0;
    vector<int> res; // ll count = 0;
    for (char c : word) {
      n = N[n].next[c - first];
      res.push_back(N[n].end);
      // count += N[n].nmatches;
    }
    return res;
  }
  vector<vector<int>> findAll(vector<string> &pat, string word) {
    vector<int> r = find(word);
    vector<vector<int>> res(sz(word));
    for (int i = 0; i < sz(word); i++) {
      int ind = r[i];
      while (ind != -1) {
        res[i - sz(pat[ind]) + 1].push_back(ind);
        ind = backp[ind];
      }
    }
    return res;
  }
};


/*Recorre las aristas originales del Trie siguiendo los caracteres de s. Es una función auxiliar utilizada por las demás.

int trieNode(const string &s) const {
    int v = 0;

    for (char c : s) {
        int x = c - first;

        if (x < 0 || x >= alpha ||
            !(N[v].real & (1u << x)))
            return -1;

        v = N[v].next[x];
    }

    return v;
}*/

/* Cuenta cuántas palabras insertadas comienzan con el prefijo s, incluyendo repetidas.
int countPrefix(const string &s) const {
    int v = trieNode(s);
    return v == -1 ? 0 : N[v].pref;
}*/

/* Cuenta cuántas veces se insertó exactamente la palabra s
int countWord(const string &s) const {
    int v = trieNode(s);
    return v == -1 ? 0 : N[v].terminal;
}*/

/* bool hasWord(const string &s) const {
    return countWord(s) > 0;
}

bool hasPrefix(const string &s) const {
    return countPrefix(s) > 0;
}*/

/*Busca el prefijo más largo de s que también sea una palabra completa insertada. 
int longestWordPrefix(const string &s) const {
    int v = 0, ans = 0;

    for (int i = 0; i < sz(s); i++) {
        int x = s[i] - first;

        if (x < 0 || x >= alpha ||
            !(N[v].real & (1u << x)))
            break;

        v = N[v].next[x];

        if (N[v].terminal > 0)
            ans = i + 1;
    }

    return ans;
}*/
