#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Rekurzív függvény postorder bejárás létrehozásához
void buildPostorder(const vector<int>& preorder, const vector<int>& inorder,
                    int preStart, int inStart, int inEnd,
                    vector<int>& postorder, unordered_map<int, int>& inMap) {
    // Alapeset
    if (preStart >= preorder.size() || inStart > inEnd) return;

    // A gyökér az első elem preorder esetén
    int root = preorder[preStart];

    //  A gyökérindex megkeresése inorder esetén
    int rootIndex = inMap[root];

    // Rekurzívan építsük fel a bal és a jobb oldali részfát
    // Bal oldali részfa
    buildPostorder(preorder, inorder, preStart + 1, inStart, rootIndex - 1, postorder, inMap);
    // Jobb oldali részfa
    buildPostorder(preorder, inorder, preStart + (rootIndex - inStart + 1), rootIndex + 1, inEnd, postorder, inMap);

    // Adjuk hozzá a gyökeret a postorder bejáráshoz
    postorder.push_back(root);
}

int main() {
    int n;
    cin >> n; // A csomópontok számának beolvasása

    vector<int> preorder(n);
    vector<int> inorder(n);
    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }

    // Hozzunk létre egy map-et az egyes értékek indexének tárolására a gyors keresés érdekében
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; ++i) {
        inMap[inorder[i]] = i;
    }

    vector<int> postorder; // Vektor a postorder bejárásának tárolására
    buildPostorder(preorder, inorder, 0, 0, n - 1, postorder, inMap);

    // Írjuk ki a postorder bejárást
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}