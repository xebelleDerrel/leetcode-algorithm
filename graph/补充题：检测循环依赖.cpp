#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n = 3;
  vector<vector<int>> nums = {{0,1},{1,2},{2,0}};

  vector<int> res(n);
  vector<int> indegrees(n);
  vector<vector<int>> adjacency(n);
  // 初始化邻接表和入度表
  for (auto &vec : nums) {
    adjacency[vec[0]].push_back(vec[1]);
    indegrees[vec[1]]++;
  }
  queue<int> q;
  // 入度为0的节点进入队列
  for (int i = 0; i < n; ++i) {
    if (indegrees[i] == 0) q.push(i);
  }

  int count = 0;
  while (!q.empty()) {
    int head = q.front(); q.pop();
    res[count++] = head;
    for (auto near : adjacency[head]) {
      indegrees[near]--;
      if (indegrees[near] == 0) {
        q.push(near);
      }
    }
  }
  if (n == count) {
    for (auto i : res) {
      cout << i << " ";
    }
    cout << endl;
  } else {
    cout << "Circular Dependency" << endl;
  }
  
  return 0;
}