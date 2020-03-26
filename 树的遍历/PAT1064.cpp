#include <bits/stdc++.h>
using namespace std;
const int maxn=1001;
int N;
int data[maxn];
vector<int> ans;
struct Node{
	int data;
	Node *left,*right;
};
Node* create(int left,int right)
{
	if(left>right)
		return NULL;
	Node* root=new Node;
	int length=right-left+1,depth=1;
	
	while(pow(2.0,depth)-1<length) depth++;
	int leftNum=(int)(pow(2.0,depth-1)-1);
	int distint=(int)(pow(2.0,depth)-1-length-pow(2.0,depth-1)/2);
	if(distint>0) leftNum-=distint;
	//int value=data[leftNum+1];
	int value=data[left+leftNum];
	root->data=value;
	root->left=create(left,left+leftNum-1);
	root->right=create(left+leftNum+1,right);
	return root;
}
void layderOrder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		int size=q.size();
		while(size--)
		{
			Node* now=q.front();
			ans.push_back(now->data);
			q.pop();
			if(now->left!=NULL) q.push(now->left);
			if(now->right!=NULL) q.push(now->right);
		}
		
	}
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&data[i]);
	sort(data+1,data+N+1);      //从小到大排序
	Node* root=NULL;
	root=create(1,N);
	layderOrder(root);
	printf("%d",ans[0]);
	for(int i=1;i<ans.size();i++)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
//以下为简洁版，长时间不做都忘记完全二叉树的特性了
#include <bits/stdc++.h>
using namespace std;
const int maxn=1001;
int n,data[maxn],CBT[maxn];
int Index=0;
void inorder(int root)
{
	if(root>n) return ;
	inorder(root*2);
	CBT[root]=data[Index++];
	inorder(root*2+1);
	
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	sort(data,data+n);      //从小到大排序
	inorder(1);
	printf("%d",CBT[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",CBT[i]);
	printf("\n");
	return 0;
}
