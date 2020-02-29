#include <bits/stdc++.h>
using namespace std;
struct node{
    int left;
    int right;
}Tree[12];
int n;
int num=0;
void inorder(int root)
{
    if(root==-1)
        return ;
    inorder(Tree[root].right);
    num++;
    if(num<n)
        printf("%d ",root);
    else
        printf("%d\n",root);
    inorder(Tree[root].left);
}
void Layerorder(int root)
{
    queue<int>q;
    q.push(root);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        num++;
        if(num<n)
            printf("%d ",now);
        else
            printf("%d\n",now);
        if(Tree[now].right!=-1) q.push(Tree[now].right);
        if(Tree[now].left!=-1) q.push(Tree[now].left);
    }
}
int main()
{
    scanf("%d",&n);
    getchar();
    char left,right;
    int a[n]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%c",&left);
        if(left=='-')
            Tree[i].left=-1;
        else{
            Tree[i].left=left-'0';
            a[left-'0']=1;
        }
        getchar();
        scanf("%c",&right);
        if(right=='-')
            Tree[i].right=-1;
        else{
            Tree[i].right=right-'0';
            a[right-'0']=1;
        }
        getchar();
    }
    int root;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            root=i;
            break;
        }
    }
    Layerorder(root);
    num=0;
    inorder(root);
    return 0;

}
//下面为柳婼的代码，注意学习
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id, l, r, index, level;
} a[100];
vector<node> v1;
void dfs(int root, int index, int level) {
    if (a[root].r != -1) dfs(a[root].r, index * 2 + 2, level + 1);
    v1.push_back({root, 0, 0, index, level});
    if (a[root].l != -1) dfs(a[root].l, index * 2 + 1, level + 1);
}
bool cmp(node a, node b) {
    if (a.level != b.level) return a.level < b.level;
    return a.index > b.index;
}
int main() {
    int n, have[100] = {0}, root = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].id = i;
        string l, r;
        cin >> l >> r;
        if (l != "-") {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        } else {
            a[i].l = -1;
        }
        if (r != "-") {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        } else {
            a[i].r = -1;
        }
    }
    while (have[root] == 1) root++;
    dfs(root, 0, 0);
    vector<node> v2(v1);
    sort(v2.begin(), v2.end(), cmp);
    for (int i = 0; i < v2.size(); i++) {
        if (i != 0) cout << " ";
        cout << v2[i].id;
    }
    cout << endl;
    for (int i = 0; i < v1.size(); i++) {
        if (i != 0) cout << " ";
        cout << v1[i].id;
    }
    return 0;
}
