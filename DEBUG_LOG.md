# Debugging Log

## Commit 1: Skeleton
Wrote the Entry struct, the table array and display(). <what you tried, what broke, how you fixed it>

## Commit 2: Hash function
Implemented division method (key % 29). Tested with keys 99 and 12; confirmed they map to the same index (12). This confirms collisions will occur and requires linear probing in the next step.

## Commit 3: Naive insertion
Implemented insertKey without collision handling. Observed that keys 99 and 90 were overwritten by keys 12 and 3. This proves that a simple hash table needs a collision strategy.

## Commit 4: Linear Probing
Implemented linear probing using the formula (hash + i) % M. This fixed the overwrite bug from Commit 3. Verified that all 20 keys are now stored correctly by checking indices where collisions previously occurred.

## Commit 5: Mango Varieties Data
Applied the mango varieties scenario. Added names array and updated output to show exactly where each key was placed and which ones experienced collisions.
