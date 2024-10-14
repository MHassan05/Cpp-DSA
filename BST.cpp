#include <iostream>
using namespace std;

template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;

    nodeType(elemType data)
    {
        info = data;
        lLink = rLink = nullptr;
    }
};

template <class elemType>
class BST
{
public:
    // Overload the assignment operator.
    const BST<elemType> &operator=(const BST<elemType> &otherTree)
    {
        if (this != &otherTree)
        {
            if (root != nullptr)
            {
                destroy(root);
            }

            if (otherTree.root != nullptr)
            {
                copyTree(this->root, otherTree.root);
            }
            else
                this->root = nullptr;
        }

        return *this;
    }

    // Function to determine whether the BST is empty.
    bool isEmpty() const
    {
        return this->root == nullptr;
    }

    // Function to do an inorder traversal of the BST.
    void inorderTraversal() const
    {
        this->inorder(root);
    }

    // Function to do a preorder traversal of the BST.
    void preorderTraversal() const
    {
        this->preorder(root);
    }

    // Function to do a postorder traversal of the BST.
    void postorderTraversal() const
    {
        this->postorder(root);
    }

    // Function to determine the height of a BST.
    int treeHeight() const
    {
        return this->height(root);
    }

    // Function to determine the number of nodes in a BST.
    int treeNodeCount() const
    {
        return this->nodeCount(root);
    }

    // Function to determine the number of leaves in a BST
    int treeLeavesCount() const
    {
        return this->leavesCount(root);
    }

    // Function to destroy the BST.
    void destroyTree()
    {
        this->destroy(root);
        root = nullptr;
    }

    // Function to determine if searchItem is in the BST.
    bool search(const elemType &searchItem) const
    {
        return searchInTree(root, searchItem);
    }

    // Function to insert insertItem in the BST.
    void insert(const elemType &insertItem)
    {
        nodeType<elemType> *newNode = new nodeType<elemType>(insertItem);

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        nodeType<elemType> *temp = root;
        while (temp)
        {
            if (insertItem > temp->info)
            {
                if (temp->rLink)
                {
                    temp = temp->rLink;
                }
                else
                {
                    temp->rLink = newNode;
                    return;
                }
            }
            else if (insertItem < temp->info)
            {
                if (temp->lLink)
                {
                    temp = temp->lLink;
                }
                else
                {
                    temp->lLink = newNode;
                    return;
                }
            }
            else
            {
                cout << "Duplicate value found in the tree.\n";
                return;
            }
        }
    }

    // Function to delete deleteItem from the BST.
    void deleteNode(const elemType &deleteItem)
    {
        nodeType<elemType> *current;      
        nodeType<elemType> *trailCurrent; 
        bool found = false;
        if (root == NULL)
            cout << "Cannot delete from an empty tree." << endl;
        else
        {
            current = root;
            trailCurrent = root;
            while (current != NULL && !found)
            {
                if (current->info == deleteItem)
                    found = true;
                else
                {
                    trailCurrent = current;
                    if (current->info > deleteItem)
                        current = current->lLink;
                    else
                        current = current->rLink;
                }
            } // end while
            if (current == NULL)
                cout << "The item to be deleted is not in the tree." << endl;
            else if (found)
            {
                if (current == root)
                    deleteFromTree(root);
                else if (trailCurrent->info > deleteItem)
                    deleteFromTree(trailCurrent->lLink);
                else
                    deleteFromTree(trailCurrent->rLink);
            }
            else
                cout << "The item to be deleted is not in the tree." << endl;
        }
    }

    // Copy constructor
    BST(const BST<elemType> &otherTree)
    {
        if (otherTree.root == nullptr)
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }

    // Default constructor
    BST()
    {
        this->root = nullptr;
    }

    // Destructor
    ~BST()
    {
        destroy(root);
    }

protected:
    nodeType<elemType> *root;

private:
    // Makes a copy of the BST to which otherTreeRoot points.
    void copyTree(nodeType<elemType> *&copiedTreeRoot, nodeType<elemType> *otherTreeRoot)
    {
        if (otherTreeRoot != nullptr)
        {
            copiedTreeRoot = new nodeType<elemType>(otherTreeRoot->info);
            copyTree(copiedTreeRoot, otherTreeRoot->lLink);
            copyTree(copiedTreeRoot, otherTreeRoot->rLink);
        }
        copiedTreeRoot = nullptr;
    }
    // Function to destroy the BST to which p points.
    void destroy(nodeType<elemType> *&p)
    {
        if (p)
        {
            destroy(p->lLink);
            destroy(p->rLink);
            delete p;
            p = nullptr;
        }
    }
    // Function to do an inorder traversal of the BST to which p points.
    void inorder(nodeType<elemType> *p) const
    {
        if (p)
        {
            inorder(p->lLink);
            cout << p->info << "  ";
            inorder(p->rLink);
        }
    }

    // Function to do a preorder traversal of the BST to which p points.
    void preorder(nodeType<elemType> *p) const
    {
        if (p)
        {
            cout << p->info << "  ";
            preorder(p->lLink);
            preorder(p->rLink);
        }
    }

    // Function to do a postorder traversal of the BST to which p points.
    void postorder(nodeType<elemType> *p) const
    {
        if (p)
        {
            postorder(p->lLink);
            postorder(p->rLink);
            cout << p->info << "  ";
        }
    }

    // Function to determine the height of the BST to which p points.
    int height(nodeType<elemType> *p) const
    {
        if (p)
        {
            return 1 + max(height(p->lLink), height(p->rLink));
        }
        return 0;
    }
    // Function to determine the larger of x and y.
    int max(int x, int y) const
    {
        if (x > y)
            return x;
        return y;
    }
    // Function to determine the number of nodes in the BST to which p points.
    int nodeCount(nodeType<elemType> *p) const
    {
        if (p)
        {
            return 1 + nodeCount(p->rLink) + nodeCount(p->lLink);
        }
        return 0;
    }

    // Function to determine the number of leaves in the BST to which p points.
    int leavesCount(nodeType<elemType> *p) const
    {
        if (p == nullptr)
        {
            return 0;
        }
        if (p->rLink == nullptr && p->lLink == nullptr)
        {
            return 1;
        }
        return leavesCount(p->rLink) + leavesCount(p->lLink);
    }

    // function to delete the node to which p points is deleted from the BST
    void deleteFromTree(nodeType<elemType> *&p)
    {

        nodeType<elemType> *current;
        nodeType<elemType> *trailCurrent;
        nodeType<elemType> *temp;
        
        if (p == NULL)
            cout << "Error: The node to be deleted is NULL." << endl;
        else if (p->lLink == NULL && p->rLink == NULL)
        {
            temp = p;
            p = NULL;
            delete temp;
        }
        else if (p->lLink == NULL)
        {
            temp = p;
            p = temp->rLink;
            delete temp;
        }
        else if (p->rLink == NULL)
        {
            temp = p;
            p = temp->lLink;
            delete temp;
        }
        else
        {
            current = p->lLink;
            trailCurrent = NULL;
            while (current->rLink != NULL)
            {
                trailCurrent = current;
                current = current->rLink;
            }
            p->info = current->info;
            if (trailCurrent == NULL)
                p->lLink = current->lLink;

            delete current;
        }
    }

    // function to search item in the tree
    bool searchInTree(nodeType<elemType> *p, elemType searchItem) const
    {
        if (p == nullptr)
        {
            return false;
        }

        if (searchItem == p->info)
        {
            return true;
        }

        if (searchItem > p->info)
        {
            return searchInTree(p->rLink, searchItem);
        }

        if (searchItem < p->info)
        {
            return searchInTree(p->lLink, searchItem);
        }

        return false;
    }
};

int main()
{
    BST<int> tree;
    int choice, item;

    do
    {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Tree Height\n";
        cout << "8. Node Count\n";
        cout << "9. Leaf Count\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> item;
            tree.insert(item);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> item;
            tree.deleteNode(item);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> item;
            if (tree.search(item))
                cout << "Item found in tree.\n";
            else
                cout << "Item not found.\n";
            break;
        case 4:
            cout << "Inorder Traversal: ";
            tree.inorderTraversal();
            break;
        case 5:
            cout << "Preorder Traversal: ";
            tree.preorderTraversal();
            break;
        case 6:
            cout << "Postorder Traversal: ";
            tree.postorderTraversal();
            break;
        case 7:
            cout << "Tree Height: " << tree.treeHeight() << endl;
            break;
        case 8:
            cout << "Node Count: " << tree.treeNodeCount() << endl;
            break;
        case 9:
            cout << "Leaf Count: " << tree.treeLeavesCount() << endl;
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}