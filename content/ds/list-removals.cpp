#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using pii = pair<int,int>;
#define sz(a) ((int)a.size())

template <class T, T merge(T, T)>
struct segment_tree {
    int n;
    vector<T> node_values;
    int get_left_child_id(int index) { return index * 2; }
    int get_right_child_id(int index) { return index * 2 + 1; }
    void build(int node_id, int left, int right, vector<T> &leaves) {
        if (left == right) {
            node_values[node_id] = leaves[left];
            return;
        }
        int mid = (left + right) / 2;
        int left_child_id = get_left_child_id(node_id);
        int right_child_id = get_right_child_id(node_id);
        build(left_child_id, left, mid, leaves);
        build(right_child_id, mid + 1, right, leaves);
        node_values[node_id] = merge(node_values[left_child_id], node_values[right_child_id]);
    }
    segment_tree(vector<T> &leaves) {
        n = leaves.size();
        node_values.resize(n * 4 + 5);
        build(1, 0, n - 1, leaves);
    }
    int query(int node_id, int left, int right, int need) {
        if(left == right){
            node_values[node_id].first = 0;
            return node_values[node_id].second;
        }
        int mid = (left + right) / 2;
        int left_child_id = get_left_child_id(node_id);
        int right_child_id = get_right_child_id(node_id);
        int ans;
        if(node_values[left_child_id].first >= need){
            ans = query(left_child_id, left, mid, need);
        }
        else{
            ans = query(right_child_id, mid+1, right, need-node_values[left_child_id].first);
        }
        node_values[node_id] = merge(node_values[left_child_id], node_values[right_child_id]);
        return ans;
    }
    int query(int need) { return query(1, 0, n - 1, need); }
};

pii merge(pii a, pii b){
  return {a.first+b.first, 0};
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pii> a(n);
  for (int i=0;i<n;i++){
    a[i] = {1,i};
  }
  segment_tree<pii,merge> st(a);
  vector<ll> j1, j2;
  for (int i=0;i<n/2;i++){
    int x; cin>>x;
    j1.push_back(x);
  }
  for (int i=0;i<n/2;i++){
    int x; cin>>x;
    j2.push_back(x);
  }
  vector<int> ans1(n/2), ans2(n/2); 
  for (int i=0;i<n/2;i++){
    ans1[i] = st.query(j1[i]);
    ans2[i] = st.query(j2[i]);
  }
  for (auto x:ans1) cout << x+1 << ' ';
  cout << '\n';
  for (auto x:ans2) cout << x+1 << ' ';
  cout << '\n';
  return 0;
}
