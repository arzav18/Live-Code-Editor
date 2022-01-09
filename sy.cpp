#include <bits/stdc++.h>
using namespace std;

set<int> s;

int l1,r1,l2,r2;

void buildtree(int *a,int *b, int s, int e, int *tree, int index) {
    if (s == e) {
        if(s<=r1 && s>=l1)
            tree[index] = a[s];
        else(s<=r2 && s>=l2)
            tree[index] = b[s];
        return;
    }
    int mid = (s + e) / 2;
    buildtree(a, s, mid, tree, 2 * index);
    buildtree(a, mid + 1, e, tree, 2 * index + 1);

    tree[index] = tree[2 * index]+ tree[2 * index + 1];
    return;
}

void countD(int *tree, int s, int e, int index) {
    if (s == e) {
        s.insert(tree[s]);
        return;
    }
    int mid = (s + e) / 2;
    buildtree(a, s, mid, tree, 2 * index);
    buildtree(a, mid + 1, e, tree, 2 * index + 1);
    return;
}

int main() {
    int n1,n2;
    cin>>n1>>n2;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++) cin>>a[i];
    for(int i=0;i<n2;i++) cin>>b[i];
    cin>>l1>>r1>>l2>>r2;
    int *tree = new int[4 * n + 1];
    buildtree(a,b, 0, n1 - 1, tree, 1);
    countD(tree,0,n1-1,1);
    cout<<"Sum = "<<tree[1]<<endl;
    cout<<"Distinct elements :"<<s.size()<<endl;
    free(tree);
}
