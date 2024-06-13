#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    //Constructor for the node class
    Node(string i, Node* l, Node*r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // initializing ROOT to null
    }

    void insert(string element) // Insert a node in the binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr); // allocate memory for the new node
        newNode->info = element; // Assign value to the data field of the new node
        newNode->leftchild = nullptr; // Make the left child of the new node point to NULL
        newNode->rightchild = nullptr; // make the right child of the new node point to NULL

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); // Locate the node which will be the parent of the node to be insert

        if (parent == nullptr)// if the parent is NULL (Tree is empty)
        {
            ROOT = newNode; // Mark the new node as ROOT
            return; // Exit
        }

        if (element < parent->info) // if the value in the data field of the new node is less than that of the
        {
            parent->leftchild = newNode; // Make the left child of the parent point to the new node
        }

        else if(element > parent->info)// if the value in the data field of the new node is greater than that 
        {
            parent->rightchild = newNode;// Make the right child of the parent point to the new node
        }
    }

    void search(string element, Node*& parent, Node*& currentNode)
    {
        // This  function searches the currentNode of the specified Node as well as the current Node of its parent
        currentNode = ROOT;
        parent = NULL;
        while ((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node*ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            inorder(ptr->leftchild); // LEFT
            cout << ptr->info << " "; // ROOT
            inorder(ptr->rightchild); // RIGHT
        }
    }

     void preorder(Node*ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            cout << ptr->info << " "; // ROOT
            preorder(ptr->leftchild); // LEFT
            preorder(ptr->rightchild); // RIGHT
        }
    }

     void postorder(Node*ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            postorder(ptr->leftchild); // LEFT
            postorder(ptr->rightchild); // RIGHT
            cout << ptr->info << " "; // ROOT
        }
    }

    int main()
    {
        BinaryTree x;
        while (true)
        {
            cout << "\nMenu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Perform inorder traversal" << endl;
            cout << "3. Perform preorder traversal" << endl;
            cout << "4. Perform postorder traversal" << endl;
            cout << "5. exit" << endl;
            cout << "\nEnter your choice (1-5) :";

            char ch;
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1' :
            {
                cout << "Enter a word: ";
                string word;
                cin >> word;
                x.insert(word);
                break;
            }
            case '2':
            {
                x.inorder(x.ROOT);
                break;
            }
            
            }

            

        }
    }




