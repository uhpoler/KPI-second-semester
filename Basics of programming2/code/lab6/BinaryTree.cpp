#include "BinaryTree.h"


/*


//конструктор ініціалізації дерева
template <typename T>
BinaryTree<T>::BinaryTree(std::initializer_list<T> initList) {
    for (const T* value = initList.begin(); value != initList.end(); ++value) {
        Insert(*value);
    }
}



//метод видалення дерева
template <typename T>
void BinaryTree<T>::Clear() {
    if (root != nullptr) {
        RemoveSubTree(root);
        root = nullptr;
    }
}

//рекурсивна функція видалення гілок дерева
template <typename T>
void BinaryTree<T>::RemoveSubTree(Node* node) {
    if (node->left != nullptr) {
        RemoveSubTree(node->left);
    }
    if (node->right != nullptr) {
        RemoveSubTree(node->right);
    }
    delete node;
}


//метод перевірки чи дерево пусте
template <typename T>
bool BinaryTree<T>::IsEmpty() const {
    return root == nullptr;
}


//метод визначення розміру дерева
template <typename T>
size_t BinaryTree<T>::Size() const {
    return Size(root);
}


//рекурсивна функція визначення розміру дерева
template <typename T>
size_t BinaryTree<T>::Size(const Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    else {
        return Size(node->left) + 1 + Size(node->right);
    }
}


//метод вставки значення в дерево
template <typename T>
void BinaryTree<T>::Insert(const T& value) {
    if (root == nullptr) {
        root = new Node{ value };
        return true;
    }
    Node* node = root;

    while (node != nullptr) {
        if (node->data == value) {
            return false;
        }
        else if(node->data > value){
            if (node->left == nullptr) {
                node->left = new Node{ value };
                return true;
            }

            node = node->left;
        }
        else {
            if (node->right == nullptr) {
                node->right = new Node{ value };
                return true;
            }
            node = node->right;
        }
    }
}

//шаблонна функція виведення дерева на екран
template <typename T>
void Show(const BinaryTree<T>& tree) {
    tree.DoForAllElements(ShowValue<T>);
}



template <typename T>
void ShowValue(const T& value) {
    std::cout << value << " ";
}



template <typename T>
void BinaryTree<T>::DoForNode(const Node* node) const {
    if (node != nullptr) {
        if (node->left != nullptr) {
            DoForNode(node->left);
        }

        ShowValue(node->data);

        if (node->right != nullptr) {
            DoForNode(node->right);
        }
    }
}




template <typename T>
void BinaryTree<T>::DoForAllElements(const Node* node) const {
    DoForNode(root);
}


*/










/*
----------------------------------------------------------------------------------
BinaryTree::~BinaryTree() {
    clear();
}

void BinaryTree::clear() {
    clear(root);
    root = nullptr;
}

bool BinaryTree::isEmpty() const {
    return root == nullptr;
}

int BinaryTree::size() const {
    return size(root);
}

void BinaryTree::insert(char value) {
    insert(root, value);
}

void BinaryTree::traverse() const {
    traverse(root);
}

BinaryTree::Iterator::Iterator(TNode* node) : current(node) {}

char BinaryTree::Iterator::operator*() const {
    return current->inf;
}

BinaryTree::Iterator& BinaryTree::Iterator::operator++() {
    if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr)
            current = current->left;
    }
    else {
        TNode* prev = current;
        current = current->left;
        while (current != nullptr && current->right != prev) {
            prev = current;
            current = current->right;
        }
    }

    return *this;
}

bool BinaryTree::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

BinaryTree::Iterator BinaryTree::begin() {
    if (root == nullptr)
        return end();

    TNode* current = root;
    while (current->left != nullptr)
        current = current->left;

    return Iterator(current);
}

BinaryTree::Iterator BinaryTree::end() {
    return Iterator(nullptr);
}

void BinaryTree::clear(TNode* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

int BinaryTree::size(TNode* node) const {
    if (node == nullptr)
        return 0;
    else
        return 1 + size(node->left) + size(node->right);
}

void BinaryTree::insert(TNode*& node, char value) {
    if (node == nullptr)
        node = new TNode(value);
    else if (value < node->inf)
        insert(node->left, value);
    else
        insert(node->right, value);
}

void BinaryTree::traverse(TNode* node) const {
    if (node != nullptr) {
        traverse(node->left);
        traverse(node->right);
        std::cout << node->inf << " ";
    }
}
*/