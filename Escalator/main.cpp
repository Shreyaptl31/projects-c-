#include <iostream>
using namespace std;

// Base Class

class StackBase
{
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void top() = 0;
    virtual void isEmpty() = 0;
    virtual void isFull() = 0;

    virtual ~StackBase() {}
};


// Derived Class
class Stack : public StackBase
{
private:
    static const int SIZE = 5;
    int arr[SIZE];
    int topIndex;

public:
    // Constructor
    Stack()
    {
        topIndex = -1;
    }

    // Push
    void push(int value) override
    {
        if (topIndex == SIZE - 1)
        {
            cout << "\nStack is Full.\n";
            return;
        }

        topIndex++;
        arr[topIndex] = value;

        cout << value << " inserted successfully.\n";
    }

    // Pop
    void pop() override
    {
        if (topIndex == -1)
        {
            cout << "\nStack is Empty.\n";
            return;
        }

        cout << arr[topIndex] << " removed successfully.\n";
        topIndex--;
    }

    // Top
    void top() override
    {
        if (topIndex == -1)
        {
            cout << "\nStack is Empty.\n";
        }
        else
        {
            cout << "\nTop Element : " << arr[topIndex] << endl;
        }
    }

    // Empty
    void isEmpty() override
    {
        if (topIndex == -1)
            cout << "\nStack is Empty.\n";
        else
            cout << "\nStack is NOT Empty.\n";
    }

    // Full
    void isFull() override
    {
        if (topIndex == SIZE - 1)
            cout << "\nStack is Full.\n";
        else
            cout << "\nStack is NOT Full.\n";
    }

    // Display
    void display()
    {
        if (topIndex == -1)
        {
            cout << "\nStack is Empty.\n";
            return;
        }

        cout << "\nStack Elements:\n";

        for (int i = topIndex; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};


// Main Function

int main()
{
    Stack s;

    int choice;
    int value;

    do
    {
        cout << "\n============================";
        cout << "\n      STACK MENU";
        cout << "\n============================";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Top";
        cout << "\n4. Check Empty";
        cout << "\n5. Check Full";
        cout << "\n6. Display Stack";
        cout << "\n7. Exit";
        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value : ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.top();
            break;

        case 4:
            s.isEmpty();
            break;

        case 5:
            s.isFull();
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "\nProgram Ended.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 7);

    return 0;
}