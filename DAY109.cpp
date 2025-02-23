//VERTICAL TRAVERSAL OF BINARY TREE
class Solution {
public:
    void find(Node* root, int pos, int &l, int &r) {
        if (!root) {
            return;
        }
        l = min(pos, l);
        r = max(pos, r);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalOrder(Node *root) {
        int l = 0, r = 0;
        find(root, 0, l, r);
        
        vector<vector<int>> positive(r + 1);
        vector<vector<int>> negative(abs(l) + 1);
        
        queue<Node*> q;
        queue<int> index;
        
        q.push(root);
        index.push(0);
        
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();
            
            if (pos >= 0) {
                positive[pos].push_back(temp->data);
            } else {
                negative[abs(pos)].push_back(temp->data);
            }
            
            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }
            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        // Combine results
        vector<vector<int>> result;

        // Insert all negative arrays in reverse order
        for (int i = negative.size() - 1; i > 0; i--) {
            result.push_back(negative[i]);
        }

        // Insert all positive arrays in normal order
        for (int i = 0; i < positive.size(); i++) {
            result.push_back(positive[i]);
        }

        return result;
    }
};


