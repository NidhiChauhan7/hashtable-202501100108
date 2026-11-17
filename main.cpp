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

// Global counters for statistics
int totalCollisions = 0;
int totalProbes = 0;

int hashFn(int key) { return key % M; }

bool insertKey(int key, const string& name) {
    int h = hashFn(key);
    for (int i = 0; i < M; i++) {
        totalProbes++;
        int idx = (h + i) % M;
        
        // Reject Duplicates
        if (table[idx].used && table[idx].key == key) {
            cout << "Insert " << key << " failed: Duplicate key rejected." << endl;
            return false;
        }

        if (!table[idx].used) {
            table[idx] = {key, name, true};
            if (i > 0) totalCollisions++;
            cout << "Inserted " << key << " (" << name << ") at index " << idx;
            if (i > 0) cout << " [Collision resolved]";
            cout << endl;
            return true;
        }
    }
    return false;
}

void display() {
    cout << "\n--- FINAL HASH TABLE STATE ---\n";
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
    
    cout << "\n--- STATISTICS ---\n";
    cout << "Total Collisions: " << totalCollisions << endl;
    cout << "Total Probes: " << totalProbes << endl;

    // Manual test for duplicate
    cout << "\nTesting duplicate insertion (Key 21):" << endl;
    insertKey(21, "DuplicateMango");

    return 0;
}
