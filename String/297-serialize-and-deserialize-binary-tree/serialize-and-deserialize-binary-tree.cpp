/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialize(TreeNode* root, string& result) {
        if(root == nullptr) {
            result += "#,";
            return;
        }

        result += to_string(root->val) + ",";
        serialize(root->left, result);
        serialize(root->right, result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serialize(root, result);
        return result;
    }

    TreeNode* buildTree(vector<string>& tokens, int& index) {
        if(index >= tokens.size()) {
            return nullptr;
        }

        string value = tokens[index++];
        if(value == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));
        root->left = buildTree(tokens, index);
        root->right = buildTree(tokens, index);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string token;

        stringstream ss(data);

        while(getline(ss, token, ',')){
            tokens.push_back(token);
        }

        int index = 0;

        return buildTree(tokens, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));