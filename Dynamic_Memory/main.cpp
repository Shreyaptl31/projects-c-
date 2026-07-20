#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class DynamicMemoryAllocation
{
private:
    Node *head;

public:
   
    DynamicMemoryAllocation()
    {
        head = NULL;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "\nLinked List is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\nLinked List : ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    void insert_at_beginning(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << "\nNode Inserted Successfully.\n";
    }

   
    void Search(int key)
    {
        Node *temp = head;
        int position = 1;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "\nElement Found at Position " << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "\nElement Not Found.\n";
    }

  
    void Delete_node(int key)
    {
        if (head == NULL)
        {
            cout << "\nList is Empty.\n";
            return;
        }

        // First Node
        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            cout << "\nNode Deleted Successfully.\n";
            return;
        }

        Node *current = head;
        Node *previous = NULL;

        while (current != NULL && current->data != key)
        {
            previous = current;
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\nElement Not Found.\n";
            return;
        }

        previous->next = current->next;
        delete current;

        cout << "\nNode Deleted Successfully.\n";
    }

    
    void reverse()
    {
        Node *prev = NULL;
        Node *current = head;
        Node *nextNode = NULL;

        while (current != NULL)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;

        cout << "\nLinked List Reversed Successfully.\n";
    }
};

int main()
{
    DynamicMemoryAllocation list;

    int choice, value;

    do
    {
        cout << "\n==============================";
        cout << "\n Linked List CRUD Operations";
        cout << "\n==============================";
        cout << "\n1. Append";
        cout << "\n2. Display";
        cout << "\n3. Insert at Beginning";
        cout << "\n4. Search";
        cout << "\n5. Delete Node";
        cout << "\n6. Reverse List";
        cout << "\n7. Exit";
        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value : ";
            cin >> value;
            list.append(value);
            break;

        case 2:
            list.display();
            break;

        case 3:
            cout << "Enter Value : ";
            cin >> value;
            list.insert_at_beginning(value);
            break;

        case 4:
            cout << "Enter Value to Search : ";
            cin >> value;
            list.Search(value);
            break;

        case 5:
            cout << "Enter Value to Delete : ";
            cin >> value;
            list.Delete_node(value);
            break;

        case 6:
            list.reverse();
            break;

        case 7:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 7);

    return 0;
}