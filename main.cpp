/* PRN: 202501100108
   Seed S = 108 | Scenario: Mango varieties
   Hash: Division method (key mod m) | Collision: Linear probing
   Table size m = 29 */
#include <iostream>
#include <string>
using namespace std;

const int M = 29;
struct Entry { int key = -1; string name; bool used = false; };
Entry table[M];

int hashFn(int key) { return key % M; }

// Naive insertion: No collision handling yet
void insertKey(int key, const string& name) {
    int h = hashFn(key);
    table[h] = {key, name, true}; 
}

void display() {
    for (int i = 0; i < M; i++) {
        cout << i << ": ";
        if (table[i].used) cout << table[i].key << " " << table[i].name;
        else cout << "-";
        cout << "\n";
    }
}

int main() {
    int S = 108;
    for (int i = 0; i < 20; i++) {
        int key = (S + 13 * i) % 100;
        insertKey(key, "mango");
    }
    display();
    return 0;
}
