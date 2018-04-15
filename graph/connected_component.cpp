/* ============================================================================
817. Linked List Components
https://leetcode.com/problems/linked-list-components/description/
============================================================================ */
class Solution {
public:
#if 0
    // BFS
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, int> indegree;
        unordered_map<int, unordered_set<int>> edges;
        if (head == NULL)
            return G.size();
        unordered_set<int> nodes;
        for (int n : G)
            nodes.insert(n);
        
        while (head) {
            if (head->next) {
                if (nodes.count(head->val) > 0 && nodes.count(head->next->val) > 0)
                {
                    edges[head->val].insert(head->next->val);
                    indegree[head->next->val]++;
                    if (indegree.count(head->val) == 0)
                        indegree[head->val] = 0;
                }
            }
            head = head->next;
        }
        int total = 0;
        while (nodes.size() > 0) {
            int k = -1;
            for (auto n : nodes) {
                if (indegree[n] == 0) {
                    k = n;
                    // nodes.erase(n);
                    indegree[n] = -1;
                    // cout << k << endl;
                    break;
                }
            }
            // no indegree 0 nodes
            if (k == -1)
                break;
            queue<int> q;
            q.push(k);
            while (q.size() > 0) {
                int cur = q.front();
                q.pop();
                nodes.erase(cur);
                for (int nei : edges[cur]) {
                    if (nodes.count(nei) > 0)
                        q.push(nei);
                }
            }
            total++;
        }
        
        // cout << "total: " << total << endl;
        // cout << "size: " << nodes.size() << endl;
        
        return total + nodes.size();
    }
#endif
    // Fast intuitive solution:
    // Beacause the values in list head are unique,
    // the input is a straight line. O-->O-->O-->O
    // G is a subgraph with some nodes removed: O-->O   X   O
    // When the next node of an edge is not in G, or next node is null (last node),
    // we found an component.
    // O(n) time, O(1) space
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> node(G.begin(), G.end());
        int connected = 0;
        while (head) {
            if (node.count(head->val) > 0) {
                if (head->next == NULL || node.count(head->next->val) == 0)
                    connected++;
            }
            head = head->next;
        }
        return connected;
    }
};