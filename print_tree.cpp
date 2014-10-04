#include <bits/stdc++.h>

using namespace std;
struct binary_node {
	int key;
	struct binary_node *left, *right;
	binary_node(int x) {
		key = x;
		left = right = NULL;
	}	
};

void print_util(binary_node *root, bool *has_left, int spaces) {
	if (root == NULL) return;
	
	int cnt = 0;
	cout << root->key << endl;
	string gap = "";
	if (root->left) has_left[spaces] = 1;
	while (cnt < spaces) { 
		gap += (has_left[cnt])?"|":" ";
		gap += "   "; 
		cnt++; 
	}
	if (root->right) {
		if (root->left) cout << gap + "|";
		else cout << gap + "`";
		cout <<  "-- ";
		print_util(root->right, has_left, spaces+1);
	}
	if (root->left) {
		cout << gap + "`-- ";
		has_left[spaces] = 0;
		print_util(root->left, has_left, spaces+1);
	}
	
}

void print_binary_tree(binary_node *root) {
	bool has_left[100] = {0};
	print_util(root, has_left, 0);
}

/*
	The algorithm used below is taken from 
		http://stackoverflow.com/questions/4965335/how-to-print-binary-tree-diagram
	Thanks Vasya Novikov for this nice solution :)

*/
void print(binary_node *root, string prefix, bool isTail) {
	if (root == NULL) return;
	cout << prefix + (isTail ? "└── " : "├── ") << root->key << endl;
	
	if (root->right && root->left) {
		prefix += (isTail?"    ":"│  ");
		print(root->right, prefix, false);
		print(root->left, prefix, true);
	} else if (root->right) {
		prefix += "    ";
		print(root->right, prefix, true);
	} else {
		prefix += "    ";
		print(root->left, prefix, true);	
	}
}

int main() {
	binary_node *root = new binary_node(1);	
	
	root->left = new binary_node(2);
	root->left->left = new binary_node(4);
	root->left->left->left = new binary_node(7);
	root->left->left->right = new binary_node(6);
	root->left->right = new binary_node(5);
		
	root->right = new binary_node(3);
	root->right->left = new binary_node(8);
	root->right->right = new binary_node(9);
	root->right->left->right = new binary_node(10);
	root->right->left->left = new binary_node(11);
	print_binary_tree(root);

	cout << endl;
	print(root, "", (root->left && root->right));
	return 0;
}
