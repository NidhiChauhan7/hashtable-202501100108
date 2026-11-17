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

bool insertKey(int key, const string& name) {
    int h = hashFn(key);
    for (int i = 0; i < M; i++) {
        int idx = (h + i) % M;
        if (!table[idx].used) {
            table[idx] = {key, name, true};
            cout << "Inserted " << key << " (" << name << ") at index " << idx;
            if (i > 0) cout << " [Collision resolved]";
            cout << endl;
            return true;
        }
    }
    return false;
}

void display() {
    cout << "\nHash Table Contents:\n";
    for (int i = 0; i < M; i++) {
        cout << i << ": ";
        if (table[i].used) cout << table[i].key << " (" << table[i].name << ")";
        else cout << "-";
        cout << "\n";
    }
}

int main() {
    string mango[20] = {"Alphonso", "Kesar", "Dasheri", "Langra", "Totapuri", 
                        "Chausa", "Banganapalli", "Neelam", "Mallika", "Amrapali", 
                        "Raspuri", "Badami", "Himsagar", "Fazli", "Mulgoba", 
                        "Pairi", "Safeda", "Rajapuri", "Sindhura", "Ratna"};
    int S = 108;
    for (int i = 0; i < 20; i++) {
        int key = (S + 13 * i) % 100;
        insertKey(key, mango[i]);
    }
    display();
    return 0;
}
