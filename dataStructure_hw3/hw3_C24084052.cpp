#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class BST;

class TreeNode {
private:
  TreeNode *leftchild;
  TreeNode *rightchild;
  TreeNode *parent;
  int key;
  string element;

public:
  friend class BST;
  TreeNode(): leftchild(0), rightchild(0), parent(0), key(0), element("") {};
  TreeNode(string element): leftchild(0), rightchild(0), parent(0), key(0), element("") {};
  TreeNode(int a, string b): leftchild(0), rightchild(0), parent(0), key(a), element(b) {};
};

class BST {
private:
  TreeNode* Leftmost(TreeNode *current);
  TreeNode* Successor(TreeNode *current);

public:
  TreeNode *root;
  BST(): root(0) {};
  TreeNode* Search(int key);
  void InsertBST(int key, string element);
  void InorderPrint();
  void PreorderPrint(TreeNode *current, int counter);
};

TreeNode* BST::Search(int KEY) {

  TreeNode *current = root;

  while (current != NULL && KEY != current->key) {  
    if (KEY < current->key) {
      current = current->leftchild;   
    } else {
      current = current->rightchild;
    }
  }
  return current;
}

void BST::InsertBST(int key, string element) {

  TreeNode *y = 0;      
  TreeNode *x = 0; 
  TreeNode *insert_node = new TreeNode(key, element);

  x = root;
  while (x != NULL) {
    y = x;
    if (insert_node->key < x->key) {
      x = x->leftchild;
    } else {
      x = x->rightchild;
    }
  }

  insert_node->parent = y;

  if (y == NULL) {             
    this->root = insert_node;
  } else if (insert_node->key < y->key) {
    y->leftchild = insert_node;
  } else {
    y->rightchild = insert_node;
  }
}

TreeNode* BST::Leftmost(TreeNode *current) {

  while (current->leftchild != NULL){
    current = current->leftchild;
  }
  return current;
}

TreeNode* BST::Successor(TreeNode *current) {

  if (current->rightchild != NULL) {
    return Leftmost(current->rightchild);
  }

  TreeNode *new_node = current->parent;

  while (new_node != NULL && current == new_node->rightchild) {
    current = new_node;
    new_node = new_node->parent;
  }

  return new_node;
}

void BST::InorderPrint() {
  TreeNode *current = new TreeNode();
  current = Leftmost(root);
  while(current) {
    cout << current->element << endl;
    current = Successor(current);
  }
}

void BST::PreorderPrint(TreeNode *current, int counter) {
  if (current) {
    for (int i = 0; i < counter; i++) {
      cout << "    ";
    }
    cout << current->element << endl;
    counter++;
    PreorderPrint(current->leftchild, counter);
    PreorderPrint(current->rightchild, counter);
    counter--;
  }
}


int main() {

  BST T;

  ifstream ifs;
  ifs.open("profit.txt");
  if (!ifs.is_open()) {
    cout << "Failed to open file!" << endl;
    return 1;
  }

  string store;
  int income, expense;
  vector<string> stores;
  vector<int> incomes;
  vector<int> expenses;
  while (ifs >> store >> expense >> income) {
    stores.push_back(store);
    expenses.push_back(expense);
    incomes.push_back(income);
  }
  ifs.close();

  string temp;
  vector<string> nodelist;
  for (int i = 0; i < stores.size(); i++) {
    int netIncome = incomes[i] - expenses[i];
    nodelist.push_back(stores[i] + " " + to_string(netIncome));
    cout << nodelist[i] << endl;     // assignment1: display the symbol and its corresponding net income
    T.InsertBST(netIncome, nodelist[i]);
  }

  cout << "-------------" << endl;
  T.PreorderPrint(T.root, 0);        // assignment2: display the layer
  cout << "-------------" << endl;
  cout << "Inorder: " << endl;       // assignment3: display Inorder Traversal
  T.InorderPrint();

  return 0;

};
