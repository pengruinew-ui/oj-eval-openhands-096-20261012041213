#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

class Solution {
private:
    unordered_map<int, TreeNode*> nodeMap;
    unordered_map<int, int> depthMap;
    
    TreeNode* buildTree(vector<int>& preorder, int& index) {
        if (index >= preorder.size() || preorder[index] == -1) {
            index++;
            return nullptr;
        }
        
        int val = preorder[index++];
        TreeNode* node = new TreeNode(val);
        nodeMap[val] = node;
        
        node->left = buildTree(preorder, index);
        node->right = buildTree(preorder, index);
        
        return node;
    }
    
    void setParentAndDepth(TreeNode* node, TreeNode* parent, int depth) {
        if (!node) return;
        
        if (parent) {
            node->parent = parent;
        }
        depthMap[node->val] = depth;
        
        setParentAndDepth(node->left, node, depth + 1);
        setParentAndDepth(node->right, node, depth + 1);
    }
    
public:
    vector<int> areCousins(vector<int>& preorder, vector<pair<int, int>>& queries) {
        vector<int> result;
        
        // Reset maps for each test case
        nodeMap.clear();
        depthMap.clear();
        
        // Build the tree from preorder traversal
        int index = 0;
        TreeNode* root = buildTree(preorder, index);
        
        // Set parent pointers and calculate depths
        setParentAndDepth(root, nullptr, 0);
        
        // Process each query
        for (auto& query : queries) {
            int x = query.first;
            int y = query.second;
            
            // Check if both nodes exist
            if (nodeMap.find(x) == nodeMap.end() || nodeMap.find(y) == nodeMap.end()) {
                result.push_back(0);
                continue;
            }
            
            TreeNode* nodeX = nodeMap[x];
            TreeNode* nodeY = nodeMap[y];
            
            // Check if they are cousins (same depth, different parents)
            if (depthMap[x] == depthMap[y] && nodeX->parent != nodeY->parent) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
        }
        
        // Clean up memory
        cleanup(root);
        
        return result;
    }
    
    void cleanup(TreeNode* node) {
        if (!node) return;
        cleanup(node->left);
        cleanup(node->right);
        delete node;
    }
};

int main() {
    int q;
    cin >> q;
    
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    string line;
    getline(cin, line); // consume newline
    getline(cin, line);
    
    // Parse preorder traversal
    vector<int> preorder;
    stringstream ss(line);
    int val;
    while (ss >> val) {
        preorder.push_back(val);
    }
    
    Solution solution;
    vector<int> result = solution.areCousins(preorder, queries);
    
    for (int res : result) {
        cout << res << endl;
    }
    
    return 0;
}