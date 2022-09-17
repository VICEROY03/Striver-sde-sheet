void mirror(Node* node) {
        // code here
        if(node==NULL)
            return;
        Node* tmp;
        tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        mirror(node->left);
        mirror(node->right);
    }