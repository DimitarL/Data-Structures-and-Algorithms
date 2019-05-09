#include <iostream>
#include <string>
#include <iomanip>
#include <queue>  
int key = 0;

using namespace std;

struct Node
{
	double value;
	Node *left;
	Node *right;

	Node(double value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

class AVLTree
{
private:
	Node * root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	void add(double value)
	{
		root = addNum(root, value);
	}

	Node *addNum(Node* node, double value)
	{
		if (node == nullptr)return new Node(value, NULL, NULL);

		if (value == node->value)
		{
			cout << node->value << " already added" << endl;
		}

		else if (value < node->value)
		{
			node->left = addNum(node->left, value);
		}

		else if (value > node->value)
		{
			node->right = addNum(node->right, value);
		}

		return node;
	}

	Node * minValueNode(Node* node)
	{
		Node *current = node;

		while (current->left != nullptr)
			current = current->left;

		return current;
	}

	Node* deleteNode(Node* root, double value)
	{
		if (root == nullptr) return root;

		if (value < root->value) root->left = deleteNode(root->left, value);
		else if (value > root->value) root->right = deleteNode(root->right, value);
		else
		{
			key = 1;
			if (root->left == nullptr)
			{
				Node *temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == NULL)
			{
				Node *temp = root->left;
				free(root);
				return temp;
			}

			Node *temp = minValueNode(root->right);

			root->value = temp->value;
			root->right = deleteNode(root->right, temp->value);
		}
		return root;
	}

	void remove(double value)
	{
		key = 0;
		root = deleteNode(root, value);
		if (key == 0) cout << value << " not found to remove" << endl;
	}

	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}
