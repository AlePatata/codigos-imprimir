/*
 *Descripción:* Aho-Corasick, generalización de KMP a múltiples patrones, con memoización
 *Complejidad:* Construccion: $O(N)$ con $N$ el largo total de los patrones
 #box(width: 100%, height: 125pt, { \
 let r = 6; let lb = (0, 1, 2, 8, 9, 6, 7, 3, 4, 5); \
 let n = ((120,8,0),(70,33,0),(40,58,1),(40,83,0),(40,108,1),(100,58,0),(100,83,1),(170,33,0),(170,58,0),(170,83,1)); \
 let e = ((0,1,"h"),(1,2,"e"),(2,3,"r"),(3,4,"s"),(1,5,"i"),(5,6,"s"),(0,7,"s"),(7,8,"h"),(8,9,"e")); \
 let s = ((9,2,(110,125)),(8,1,(125,40)),(6,7,(135,65)),(4,7,(235,140))); \
 let p(i) = (n.at(i).at(0) * 1pt, n.at(i).at(1) * 1pt); \
 for (a, b, c) in e { \
 let (x1, y1) = p(a); let (x2, y2) = p(b); \
 place(line(start: (x1, y1), end: (x2, y2), stroke: 0.6pt)); \
 place(dx: (x1 + x2) / 2 + (if x2 < x1 { -6pt } else if x2 > x1 { 2pt } else { -6pt }), dy: (y1 + y2) / 2 - 5pt, text(size: 6pt, raw(c))) \
 }; \
 for (a, b, c) in s { \
 let (x1, y1) = p(a); let (x2, y2) = p(b); let (cx, cy) = (c.at(0) * 1pt, c.at(1) * 1pt); \
 let (dx, dy) = (x2 - cx, y2 - cy); let d = calc.sqrt(dx / 1pt * dx / 1pt + dy / 1pt * dy / 1pt) * 1pt; \
 let (ux, uy) = (dx / d, dy / d); let (ex, ey) = (x2 - ux * (r + 0.5) * 1pt, y2 - uy * (r + 0.5) * 1pt); \
 place(curve(stroke: (paint: red, thickness: 0.5pt, dash: "dashed"), curve.move((x1, y1)), curve.quad((cx, cy), (ex, ey)))); \
 place(polygon(fill: red, (ex, ey), (ex - ux * 4pt - uy * 2pt, ey - uy * 4pt + ux * 2pt), (ex - ux * 4pt + uy * 2pt, ey - uy * 4pt - ux * 2pt))) \
 }; \
 for (i, (x, y, t)) in n.enumerate() { \
 place(dx: x * 1pt - r * 1pt, dy: y * 1pt - r * 1pt, circle(radius: r * 1pt, fill: if t == 1 { rgb("#cde") } else { white }, stroke: (thickness: if t == 1 { 1.2pt } else { 0.6pt }), align(center + horizon, text(size: 6pt, str(lb.at(i)))))) \
 }; \
 place(dx: 200pt, dy: 0pt, box(width: 60pt, text(size: 6pt)[Patrones: \ `he`, `she`, `his`, `hers` \ #box(circle(radius: 3pt, fill: rgb("#cde"), stroke: 1.2pt)) fin de patrón \ #box(line(length: 10pt, stroke: (paint: red, thickness: 0.5pt, dash: "dashed"))) suffix link \ (el resto va a 0)])) \
 }) \
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

