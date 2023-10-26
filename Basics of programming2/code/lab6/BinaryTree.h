
#include <iostream>
#include <initializer_list>

template <typename T>
class BinaryTree {

private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;  
    };

    Node* root = nullptr;
    void RemoveSubTree(Node* node);
    size_t Size(const Node* node) const;

    Node* iterator;
public:

    BinaryTree()=default;
    BinaryTree(std::initializer_list<T> initList);


    bool Insert(const T& value);
    void Clear();
    bool IsEmpty() const;
    size_t Size() const;
    void Show();
    void ShowValue(const Node* node);
    void ReverseShowValue(const Node* node);
    void ReverseTraversal();
   
    Node* GetRoot() { return root; };
 
    class Iterator {
    private:
        Node* currentNode;
        Node* root;
    public:
        Iterator(Node* node = nullptr, Node* rootNode = nullptr) : currentNode(node), root(rootNode) {}

        //Оператори для ітератора
        T& operator*() const { return currentNode->data; }
        
        bool operator==(const Iterator& other) const { return currentNode == other.currentNode; }
        bool operator!=(const Iterator& other) const { return currentNode != other.currentNode; }
        Iterator& operator--();
    };

    // Методы для отримання ітератора
    Iterator begin() const { return Iterator(root, root); }
    Iterator end() const { return Iterator(nullptr); }
    

};




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

//функція видалення гілок дерева
template <typename T>
void BinaryTree<T>::RemoveSubTree(Node* node) {
    Node* current = node;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->left != nullptr) {
            Node* left = current->left;
            current->left = previous;
            previous = current;
            current = left;
        }
        else if (current->right != nullptr) {
            Node* right = current->right;
            current->right = previous;
            previous = current;
            current = right;
        }
        else {
            Node* parent = previous;
            delete current;
            current = nullptr;

            if (parent != nullptr) {
                if (parent->left == previous) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }
                current = parent;
                previous = nullptr;
            }
        }
    }
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


//функція визначення розміру дерева
template <typename T>
size_t BinaryTree<T>::Size(const Node* node) const {
    if (node == nullptr) {
        return 0;
    }

    size_t count = 0;
    const Node* current = node;
    const Node* previous = nullptr;

    while (current != nullptr) {
        if (previous == current->left) {
            count++;
            if (current->right != nullptr) {
                previous = current;
                current = current->right;
            }
            else {
                previous = current;
                current = current->parent;
            }
        }
        else if (previous == current->right) {
            previous = current;
            current = current->parent;
        }
        else {
            if (current->left != nullptr) {
                previous = current;
                current = current->left;
            }
            else if (current->right != nullptr) {
                count++;
                previous = current;
                current = current->right;
            }
            else {
                count++;
                previous = current;
                current = current->parent;
            }
        }
    }

    return count;
}


//метод вставки значення в дерево
template <typename T>
bool BinaryTree<T>::Insert(const T& value) {
    if (root == nullptr) {
        root = new Node{ value };
        return true;
    }
    Node* parent = nullptr;
    Node* node = root;
    while (node != nullptr) {
        parent = node;

        if (node->data == value) {
            return false;
        }
        else if (node->data > value) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    if (parent->data > value) {
        parent->left = new Node{ value };
        parent->left->parent = parent;
    }
    else {
        parent->right = new Node{ value };
        parent->right->parent = parent;
    }

    return true;
}


//метод виведення дерева на екран
template <typename T>
void BinaryTree<T>::Show() {
    ShowValue(root);
}


//метод виведення значень на екран
template <typename T>
void BinaryTree<T>::ShowValue(const Node* node) {
    const Node* current = node;
    const Node* previous = nullptr;

    while (current != nullptr) {
        if (previous == current->left) {
            std::cout << current->data << " ";
            if (current->right != nullptr) {
                previous = current;
                current = current->right;
            }
            else {
                previous = current;
                current = current->parent;
            }
        }
        else if (previous == current->right) {
            previous = current;
            current = current->parent;
        }
        else {
            if (current->left != nullptr) {
                previous = current;
                current = current->left;
            }
            else if (current->right != nullptr) {
                std::cout << current->data << " ";
                previous = current;
                current = current->right;
            }
            else {
                std::cout << current->data << " ";
                previous = current;
                current = current->parent;
            }
        }
    }
}



//метод зворотнього обходу дерева
template <typename T>
void BinaryTree<T>::ReverseTraversal(){
    ReverseShowValue(root);
}


//зворотній обхід дерева
template <typename T>
void BinaryTree<T>::ReverseShowValue(const Node* node) {
    const Node* current = node;
    const Node* previous = nullptr;

    while (current != nullptr) {
        if (previous == current->left) {
            if (current->right != nullptr) {

                previous = current;
                current = current->right;
            }
            else {
                std::cout << current->data << " ";
                previous = current;
                current = current->parent;
            }
        }
        else if (previous == current->right) {
            std::cout << current->data << " ";
            previous = current;
            current = current->parent;
        }
        else {
            if (current->left != nullptr) {
                previous = current;
                current = current->left;
            }
            else if (current->right != nullptr) {
                previous = current;
                current = current->right;
            }
            else {
                std::cout << current->data << " ";
                previous = current;
                current = current->parent;
            }
        }
    }
}




//переміщення ітератора на попереднє місце
template <typename T>
typename BinaryTree<T>::Iterator& BinaryTree<T>::Iterator::operator--() {
    if (currentNode == nullptr)
    {
 
        return *this;
    }


    if (currentNode->left != nullptr)
    {
 
        currentNode = currentNode->left;
        while (currentNode->right != nullptr)
        {
            currentNode = currentNode->right;
        }
    }
    else
    {

        Node* prevNode = nullptr;
        Node* ancestor = root;
        while (ancestor != currentNode)
        {
            if (currentNode->data > ancestor->data)
            {
                prevNode = ancestor;
                ancestor = ancestor->right;
            }
            else
            {
                ancestor = ancestor->left;
            }
        }
        currentNode = prevNode;
    }

    return *this;
}


