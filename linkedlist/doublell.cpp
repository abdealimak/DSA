// ============================================================
//  DOUBLY LINKED LIST — Complete C++ Implementation
//  Covers: insertAtHead, insertAtTail, insertAtPosition,
//          insertAfterNode, deleteNode, deleteByValue,
//          deleteAtPosition, search, displayForward,
//          displayBackward, reverse, length
// ============================================================

#include <iostream>
using namespace std;

// ─── NODE STRUCTURE ──────────────────────────────────────────
struct DNode {
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// ─── DOUBLY LINKED LIST CLASS ────────────────────────────────
class DoublyLinkedList {
    DNode* head;
    DNode* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // ── Destructor ────────────────────────────────────────────
    ~DoublyLinkedList() {
        DNode* curr = head;
        while (curr) {
            DNode* tmp = curr->next;
            delete curr;
            curr = tmp;
        }
    }

    // ── 1. Insert at Head — O(1) ─────────────────────────────
    void insertAtHead(int val) {
        DNode* n = new DNode(val);
        if (!head) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
        size++;
    }

    // ── 2. Insert at Tail — O(1) ─────────────────────────────
    void insertAtTail(int val) {
        DNode* n = new DNode(val);
        if (!tail) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        size++;
    }

    // ── 3. Insert at Position (0-indexed) — O(n) ─────────────
    void insertAtPosition(int val, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) { insertAtHead(val); return; }
        if (pos == size) { insertAtTail(val); return; }

        DNode* n = new DNode(val);
        DNode* curr = head;
        for (int i = 0; i < pos - 1; i++)
            curr = curr->next;

        DNode* nxtNode = curr->next;
        n->prev = curr;
        n->next = nxtNode;
        curr->next = n;
        if (nxtNode) nxtNode->prev = n;
        size++;
    }

    // ── 4. Insert After a Given Node — O(1) ──────────────────
    //       (given direct node pointer — e.g. from search)
    void insertAfterNode(DNode* node, int val) {
        if (!node) return;
        DNode* n = new DNode(val);
        n->prev = node;
        n->next = node->next;
        if (node->next) node->next->prev = n;
        else tail = n;
        node->next = n;
        size++;
    }

    // ── 5. Delete a Node by Pointer — O(1) ───────────────────
    void deleteNode(DNode* node) {
        if (!node) return;
        if (node->prev) node->prev->next = node->next;
        else            head = node->next;  // deleting head
        if (node->next) node->next->prev = node->prev;
        else            tail = node->prev;  // deleting tail
        delete node;
        size--;
    }

    // ── 6. Delete by Value — O(n) ────────────────────────────
    void deleteByValue(int val) {
        DNode* curr = head;
        while (curr) {
            if (curr->data == val) {
                deleteNode(curr);
                return;
            }
            curr = curr->next;
        }
        cout << "Value " << val << " not found!" << endl;
    }

    // ── 7. Delete at Position (0-indexed) — O(n) ─────────────
    void deleteAtPosition(int pos) {
        if (!head || pos < 0 || pos >= size) {
            cout << "Invalid position!" << endl;
            return;
        }
        DNode* curr = head;
        for (int i = 0; i < pos; i++)
            curr = curr->next;
        deleteNode(curr);
    }

    // ── 8. Search — returns pointer (O(n)) ───────────────────
    DNode* search(int val) {
        DNode* curr = head;
        int index = 0;
        while (curr) {
            if (curr->data == val) {
                cout << "Found " << val << " at index " << index << endl;
                return curr;
            }
            curr = curr->next;
            index++;
        }
        cout << "Value " << val << " not found!" << endl;
        return nullptr;
    }

    // ── 9. Reverse — O(n) ────────────────────────────────────
    void reverse() {
        DNode* curr = head;
        DNode* temp = nullptr;
        while (curr) {
            // swap prev and next pointers
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev; // move forward (was next)
        }
        if (temp) head = temp->prev;
    }

    // ── 10. Display Forward ───────────────────────────────────
    void displayForward() {
        if (!head) { cout << "NULL" << endl; return; }
        cout << "NULL <-> ";
        DNode* curr = head;
        while (curr) {
            cout << "[" << curr->data << "]";
            if (curr->next) cout << " <-> ";
            curr = curr->next;
        }
        cout << " <-> NULL" << endl;
    }

    // ── 11. Display Backward ─────────────────────────────────
    void displayBackward() {
        if (!tail) { cout << "NULL" << endl; return; }
        cout << "NULL <-> ";
        DNode* curr = tail;
        while (curr) {
            cout << "[" << curr->data << "]";
            if (curr->prev) cout << " <-> ";
            curr = curr->prev;
        }
        cout << " <-> NULL" << endl;
    }

    // ── 12. Length — O(1) ────────────────────────────────────
    int length() { return size; }

    // ── 13. Get Head & Tail values ───────────────────────────
    int getHead() { return head ? head->data : -1; }
    int getTail() { return tail ? tail->data : -1; }
};

// ─── MAIN: DEMO ──────────────────────────────────────────────
int main() {
    cout << "===== DOUBLY LINKED LIST DEMO =====" << endl;

    DoublyLinkedList dll;

    cout << "\n-- Insert at Head --" << endl;
    dll.insertAtHead(30);
    dll.insertAtHead(20);
    dll.insertAtHead(10);
    dll.displayForward(); // NULL <-> [10] <-> [20] <-> [30] <-> NULL

    cout << "\n-- Insert at Tail --" << endl;
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.displayForward(); // ... [10] <-> [20] <-> [30] <-> [40] <-> [50] ...

    cout << "\n-- Insert at Position 2 (val=25) --" << endl;
    dll.insertAtPosition(25, 2);
    dll.displayForward();

    cout << "\n-- Display Backward --" << endl;
    dll.displayBackward();

    cout << "\n-- Search 40 --" << endl;
    DNode* found = dll.search(40);

    cout << "\n-- Insert After node(40): val=45 --" << endl;
    if (found) dll.insertAfterNode(found, 45);
    dll.displayForward();

    cout << "\n-- Delete by Value (25) --" << endl;
    dll.deleteByValue(25);
    dll.displayForward();

    cout << "\n-- Delete at Position 0 --" << endl;
    dll.deleteAtPosition(0);
    dll.displayForward();

    cout << "\n-- Reverse --" << endl;
    dll.reverse();
    dll.displayForward();

    cout << "\n-- Length: " << dll.length() << endl;
    cout << "-- Head: " << dll.getHead() << ", Tail: " << dll.getTail() << endl;

    return 0;
}

/*
  COMPILE & RUN:
    g++ -o dll doubly_linked_list.cpp && ./dll

  TIME COMPLEXITY SUMMARY:
    insertAtHead       → O(1)
    insertAtTail       → O(1)   ← DLL has tail pointer!
    insertAtPosition   → O(n)
    insertAfterNode    → O(1)   ← given node pointer
    deleteNode(ptr)    → O(1)   ← KEY advantage of DLL
    deleteByValue      → O(n)
    deleteAtPosition   → O(n)
    search             → O(n)
    reverse            → O(n)
    length             → O(1)

  KEY INSIGHT:
    deleteNode() is O(1) when you have the pointer — because
    DLL stores prev, so you don't need to find the predecessor.
    This is why LRU Cache uses DLL + HashMap!
*/