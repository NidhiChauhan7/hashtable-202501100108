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

// Hash function: Division method (key mod M)
int hashFn(int key) { 
    return key % M; 
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
    // Testing specific keys to confirm collisions
    // Your keys 99 and 12 both mod 29 = 12
    cout << "Hash(99): " << hashFn(99) << "\n";
    cout << "Hash(12): " << hashFn(12) << "\n";
    cout << "Hash(42): " << hashFn(42) << "\n";
    display();
    return 0;
}
