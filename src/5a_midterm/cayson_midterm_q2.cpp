#include <iostream>
using namespace std;

//// ==========================================================================
//// ``````````````````````````````````````````````````````````````````````````
//// .
//// ..          Chris Ayson
//// ...         Prof. Spinrad
//// ...         CSD233 13170 - C++ Programming
//// ...         12 Feb 2025
//// ...
//// ..          MIDTERM QUESTION 2
//// .
//// ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//// ==========================================================================

struct node {
    int data;
    struct node* next;
};

class LinkIntList {
    private:
        struct node* head;
    public:
        LinkIntList() {
            head = nullptr;
        }
        void Add(int x) {
            struct node* newNode = new struct node;
            newNode->next = head;
            newNode->data = x;
            head = newNode;
        }

        // removes the first node with the value x
        // returns true if successful
        // returns false if value x isn't found
        bool Remove(int x) {

            // Pointers used to loop through the linked list
            node* beforeCursor = nullptr;
            node* cursor = head;

            // Loop through linked list, looking for a match to x
            while (cursor != nullptr) {
                if (cursor-> data == x) {

                    // Unlink node before the matched node
                    if (beforeCursor != nullptr)
                        beforeCursor->next = cursor->next;

                    // If matched node is current head, update head
                    if (head == cursor)
                        head = cursor->next;

                    // Deallocate memory of matched node
                    delete cursor;

                    // Report that match was found
                    return true;
                }

                // Increment loop index
                beforeCursor = cursor;
                cursor = cursor->next;
            }

            // Report that match was not found
            return false;
        }

        void PrintAll() {
            struct node* ptr = head;
            while (nullptr != ptr) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
};


int main() {
    LinkIntList list;
    for (int i = 0; i < 10; i++)
        // populate the list with numbers 0..9
        list.Add(i);

    list.Remove(10);
    list.Remove(9);
    list.Remove(7);
    list.Remove(0);
    list.Remove(4);

    list.PrintAll();

    return 0;
}
