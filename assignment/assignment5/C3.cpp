//have bugs
//created by ChatGPT
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

// Function to create a circular linked list with n nodes
Node* createCircularLinkedList(int n) {
    Node* head = new Node(1);
    Node* current = head;

    for (int i = 2; i <= n; ++i) {
        current->next = new Node(i);
        current = current->next;
    }

    current->next = head; // Make the linked list circular

    return head;
}

// Function to find all prime numbers up to a given limit
vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

// Function to find the order of players going out of the ring
vector<int> findOrder(int n) {
    vector<int> primes = generatePrimes(n);
    vector<int> order;

    Node* head = createCircularLinkedList(n);
    Node* current = head;

    while (!primes.empty()) {
        int step = primes.front() - 1;
        primes.erase(primes.begin());

        for (int i = 1; i < step; ++i) {
            current = current->next;
        }

        Node* toRemove = current->next;
        order.push_back(toRemove->data);
        current->next = toRemove->next;
        delete toRemove;

        if (current->next == current) {
            break; // Last player remaining, break the loop
        }
    }

    delete head; // Release memory allocated for the circular linked list

    return order;
}

int main() {
    int n;
    cout << "Enter the number of players: ";
    cin >> n;

    vector<int> order = findOrder(n);

    cout << "Order of players going out of the ring: ";
    for (int player : order) {
        cout << player << " ";
    }
    cout << "\n";
    return 0;
}
