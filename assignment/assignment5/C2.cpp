#include <iostream>
#include <vector>

using namespace std;

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

    vector<bool> inRing(n + 1, true);

    int index = 0;

    while (!primes.empty()) {
        int step = primes[index] - 1;
        int count = 0;

        for (int i = 1; i <= n; ++i) {
            if (inRing[i]) {
                count++;
                if (count == step + 1) {
                    order.push_back(i);
                    inRing[i] = false;
                    count = 0;
                }
            }
        }

        primes.erase(primes.begin() + index);

        if (index == primes.size()) {
            index = 0;
        }
    }

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

    return 0;
}
