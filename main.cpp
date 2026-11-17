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

void display() {
    for (int i = 0; i < M; i++) {
        cout << i << ": ";
        if (table[i].used) cout << table[i].key << " " << table[i].name;
        else cout << "-";
        cout << "\n";
    }
}

int main() {
    display();
    return 0;
}
