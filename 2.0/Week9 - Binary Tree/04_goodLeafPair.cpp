/*

🧠 Intuition
We want to count the number of leaf pairs (leaf1, leaf2) such that the distance between them is ≤ distance.
❓ How to find distance between two leaf nodes?
- The path between two leaf nodes always goes up to their Lowest Common Ancestor (LCA) and back down. So we can solve this recursively bottom-up:
*/