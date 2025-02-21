

/**
 * A Node in a doubly linked list of char*.
 */
struct Node {
    char* data;
    Node* prev;
    Node* next;

    Node():
        data(""), prev(nullptr), next(nullptr) {}
    Node(char* const& _data):
        data(_data), prev(nullptr), next(nullptr) {}
    Node(char* const& _data, Node* const& _prev, Node* const& _next):
        data(_data), prev(_prev), next(_next) {}

    /** Destructor that relinks Nodes to fill the hole. */
    ~Node() {
        if (prev != nullptr) prev->next = next;
        if (next != nullptr) next->prev = prev;
    }

    /** Less than overload. Compares Node data alphabetically. */
    bool operator < (Node const& other) {
        // Used to compare chars.
        char* data0 = data;
        char* data1 = other.data;
        // Loop through chars.
        while (*data0 == *data1) {
            if (*data0 == '\0') break;
            if (*data1 == '\0') break;
            data0++;
            data1++;
        }
        // Compare alphabetically.
        return *data0 < *data1;
    }

    /** Greater than overload. Compares Node data alphabetically. */
    bool operator > (Node const& other) {
        // Used to compare chars.
        char* data0 = data;
        char* data1 = other.data;
        // Loop through chars.
        while (*data0 == *data1) {
            if (*data0 == '\0') break;
            if (*data1 == '\0') break;
            data0++;
            data1++;
        }
        // Compare alphabetically.
        return *data0 > *data1;
    }
};








/**
 * A doubly linked list of char*.
 * The head and tail can be nullptrs.
 * If tail exists, head must exist.
 * If tail exists, it will never equal head.
 */
struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList(): head(nullptr), tail(nullptr) {}
    LinkedList(Node* _head): head(_head), tail((*_head).next) {}

    /**
     * Creates a new Node before list head.
     */
    void insertBeforeHead(char* data) {
        // if (head == nullptr) {
        // head = node;
        // tail = node->next;
        // } else {
        // head->prev = node;
        // node->next = head;
        // head = node;
        // }
    }

    /**
     * Creates a new Node after list head.
     */
    void insertAfterHead(char* data) {
        // Node* afterHead = head->next;
        // head->next = node;
        // node->prev = head;
        // node->next = afterHead;
    }

    /**
     * Loops through list until a Node char* with greater or equal ASCII is found.
     * Creates a new Node right before that one.
     * If none are found, inserts at the tail.
     */
    void insertAlphabetically(char* newData) {
        Node* iter;
        bool insertAtTail = false;
        // Loop through list
        while ((*iter).data < newData) {
            if ((*iter).next == nullptr) {
                insertAtTail = true;
                break;
            }
            iter = (*iter).next;
        }
        // If greater wasnt found, insert at tail
        if (insertAtTail) {
            if (head == nullptr)
                head = new Node(newData);
            else if (tail == nullptr) {
                Node* newNode = new Node(newData, head, nullptr);
                (*head).next = newNode;
                tail = newNode;
            } else {
                Node* newNode = new Node(newData, tail, nullptr);
                (*tail).next = newNode;
                tail = newNode;
            }
        }
        // Otherwise, insert before greater
        else {

        }
    }
};
