class Solution {
public:
    void buildGraph(TreeNode* cur, TreeNode* parent, unordered_map<int, vector<int>>& graph) {
        if (cur) {
            // If there is a parent, create an edge between current node and parent
            if (parent) {
                graph[parent->val].push_back(cur->val); // Connect parent to current node
                graph[cur->val].push_back(parent->val); // Connect current node to parent
            }

            buildGraph(cur->left, cur, graph);
            buildGraph(cur->right, cur, graph);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph; // Adjacency list to represent the graph
        buildGraph(root, nullptr, graph); // Build the graph from the binary tree

        vector<int> res; // Vector to store the result
        unordered_set<int> vis; // Set to keep track of visited nodes
        queue<pair<int, int>> q; // Queue to perform BFS, storing (node, distance)

        // Start BFS from the target node with distance 0
        q.push({target->val, 0});
        vis.insert(target->val); // Mark the target node as visited

        // Perform BFS to find all nodes at distance k
        while (!q.empty()) {
            int cur = q.front().first; // Current node value
            int dist = q.front().second; // Current distance from target
            q.pop(); // Remove the current node from the queue

            // If the current distance equals k, add the node to the result
            if (dist == k) {
                res.push_back(cur); // Store the node value in the result
                continue; // Continue to the next node in the queue
            }

            // Explore all unvisited neighbors of the current node
            for (int neigh : graph[cur]) {
                if (vis.find(neigh) == vis.end()) { // Check if neighbor is not visited
                    vis.insert(neigh); // Mark neighbor as visited
                    q.push({neigh, dist + 1}); // Push neighbor with incremented distance
                }
            }
        }
        return res; // Return the list of nodes at distance k
    }
};