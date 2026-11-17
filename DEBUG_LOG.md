# Debugging Log

## Commit 1: Skeleton
Wrote the Entry struct, the table array and display(). <what you tried, what broke, how you fixed it>

## Commit 2: Hash function
Implemented division method (key % 29). Tested with keys 99 and 12; confirmed they map to the same index (12). This confirms collisions will occur and requires linear probing in the next step.

## Commit 3: Naive insertion
Implemented insertKey without collision handling. Observed that keys 99 and 90 were overwritten by keys 12 and 3. This proves that a simple hash table needs a collision strategy.
