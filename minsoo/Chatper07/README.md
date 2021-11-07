## 이진 탐색

- ### 순차 탐색

리스트 안에 있는 특정한 데이터를 찾기 위해 앞에서부터 데이터를 하나씩 차례대로 확인하는 방법 

장점 : 리스트에 데이터 양이 아무리 많아도 시간만 충분하다면 원하는 원소를 찾을 수 있음

```c++
int sequential_search(int n, string target, vector<string> arr) {
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) // 찾고자 하는 원소 비교
            return i + i; // 현재의 위치 반환 (인덱스는 0부터 시작하므로 1을 더한다)
    }
    return -1;
}
```

순차 탐색은 데이터 정렬 여부와 상관없이 가장 앞에 있는 원소부터 하나씩 확인하는 특징이 있다. 즉, 데이터의 개수가 N개일 때 최대 N번의 비교 연산이 필요하므로 순차탐색의 시간 복잡도는 O(N)이다.



- ### 이진 탐색 : 반으로 쪼개면서 탐색하기

이진 탐색 (Binary Search)는 배열 내부의 데이터가 정렬되어 있어야만 사용할 수 있다. 탐색 범위를 절반씩 좁혀가며 데이터를 탐색하기 때문에 빠르다는 특징이 있다.

이진 탐색은 시작점, 끝점, 중간점을 이용해서 **찾으려는 데이터와 중간점 위치에 있는 데이터를 반복적으로 비교해서 데이터를 찾는다**

```C++
// 이진 탐색 (재귀 함수)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    if (start > end) return -1;
    
    int mid = (start + end) / 2;
    
    if (arr[mid] == target) 
        return mid;
    else if (arr[mid] > target) // 중간점의 값 보다 찾고자 하는 값이 작은 경우
        return binarySearch(arr, target, start, mid - 1);
    else // 중간점의 값 보다 찾고자 하는 값이 큰 경우
        return binarySearch(arr, target, mid + 1, end);
}

// 이진 탐색 (반복문) 
int binarySearch(vector<int>& arr, int target, int start, int end) {
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
```

이진 탐색은 한 번 확인할 때마다 확인하는 원소의 개수가 절반씩 줄어든다는 점에서 시간 복잡도는 O(logN)이다.

- ### 코딩 테스트에서의 이진 탐색

탐색 범위가 2000만을 넘어가면 이진 탐색으로 문제에 접근 해보자

- ### 이진 탐색 트리 (Binary Search Tree)

이진 탐색이 동작할 수 있도록 고안된, 효율적 탐색이 가능한 자료구조이다.

<img src="https://blog.kakaocdn.net/dn/bCe3QD/btq2ytHuN1Z/Ai82KHYBlgY01j9hbwjOO1/img.png" alt="img" style="zoom:70%;" />

다음과 같은 특징이 있다. (왼쪽 자식 노드 < 부모 노드 < 오른쪽 자식 노드)

- 부모 노드보다 왼쪽 자식 노드가 작다
- 부모 노드보다 오른쪽 자식 노드가 크다.

```C++
class Node
{
public:
    int data;
    Node* leftChild = NULL;
    Node* rightChild = NULL;
    
    Node(int _data, Node* _leftChild, Node* _rightChild)
        :data(_data), leftChild(_leftChild), rightChild(_rightChild)
        {}
}
```

이진 탐색 트리에서 `Inorder traversal`(왼쪽 → 루트 →  오른쪽)을 수행하여 모든 키를 정렬된 순서로 가져올 수 있다. 시간 복잡도는 균형 상태에서 O(log N), 불균형 상태에서 O(N)이다.

**데이터 검색(Search)**는 루트 노드부터 왼쪽 자식 or 오른쪽 자식 노드로 이동하며 반복적으로 방문한다. 자식 노드가 없을 때까지 원소를 찾지 못했다면, 이진 탐색 트리에는 원소가 없는 것이다.

```C++
Node* BST_SearchNode(Node* root, int target)
{
	if(root == NULL || root->data == target)
        return root;
    else if (root->data > target)
        return BST_SearchNode(root->leftChild, target);
    else
        return BST_SearchNode(root->rightChild, target);
}
```

**데이터 삽입(Insert)**은 새 노드가 삽입될 적합한 위치를 이진 탐색으로 찾아야 한다. 즉, 이진 탐색 트리 규칙을 만족함과 동시에 각 레벨 마다 왼쪽 또는 오른쪽 서브트리를 선택하면서 내려오다 자식이 없는 Leaf 노드에 도달하게 되면 추가한다.

```C++
void BST_InsertNode(Node* root, Node* node)
{
	if (node->data < root->data){ 
        if (root->leftChild == NULL) { // 말단 노드 O
            root->leftChild == node;
            return;
        }
        else
            BST_InsertNode(root->leftChild, node); // 말단 노드 X
    }
    else if (node->data > root->data) {
        if (root->rightChild == NULL) {
            root->rightChild == node;
            return;
        }
        else
            BST_InsertNode(root->rightChild, node);
    }
}
```

**데이터 삭제(Delete)**는 삭제하려는 노드의 자식개수에 따라 방법이 다르다. 또한, 삭제할 노드의 부모와 삭제할 노드의 자식을 연결지어 주어야 하기 때문에 **삭제할 노드의 부모가 누군지에 대한 정보도 가지고 있어야 한다.**

1. 삭제할 노드의 서브트리가 0개일 때
2. 삭제할 노드의 서브트리가 1개일 때
3. 삭제할 노드의 서브트리가 2개일 때

```C++
Node* BST_SearchMinNode(Node* root)
{
	if (root == NULL)
        return NULL;
    
    if (root->left == NULL)
        return root;
    else
        BST_SearchMinNode(root->left);
}

Node* BST_RemoveNode(Node* root, Node* parent, int target)
{
	// target과 일치하는 노드는 삭제
    // 삭제할 노드의 위치가 되는 노드는 root에, 삭제할 노드의 부모는 parent에 저장
    // 삭제할 노드는 romovedNode에 복사하고 나중에 리턴
    
    if (root == NULL)
        return NULL;
    
    Node* removedNode = NULL;
    
 	// 삭제할 노드 탐색
    if (root->data > target)
        removedNode = BST_RemoveNode(root->left, root, target);
    else if (root->data < target)
        removedNode = BST_RemoveNode(root->right, root, target);
    else if (root->data == target){
        removedNode = root;
       	
        // 1. 삭제하려는 노드의 자식 서브트리가 0개
        if (root->left == NULL && root->right == NULL) {
            // 삭제할 노드의 부모 노드의 어느 쪽에 있는지 확인 후, 삭제
            if(parent->left == root)
            	parent->left == NULL;
            
            if(parent->right == root)
                parent->right == NULL;
        }
        // 2. 삭제하려는 노드의 자식 서브트리가 1개
        else if (root->left == NULL || root->right == NULL) {
            // 삭제할 노드의 자식 복사
            Node* temp = NULL;
            if (root->left != NULL)
                temp = root->left;
            else
                temp = root->right;
            
            // 삭제할 노드가 부모 노드의 어느 쪽에 있는지 확인 후, 삭제할 노드의 자식 노드를 연결
            if (parent->left == root) 
                parent->left == temp;
            else
                parent->right == temp;
        }
        // 3. 삭제하려는 노드의 자식 서브트리가 2개
        else if (root->left != NULL && root->right != NULL) {
            // 삭제할 노드의 오른쪽 서브트리에서 가장 작은 값
            Node* minNode_Of_BiggerNodes = BST_SearchMinNode(root->right);
            minNode_Of_BiggerNodes = BST_RemoveNode(root, NULL, minNode_Of_BiggerNodes->data);
            root->data = minNode_Of_BiggerNodes->data;
        }
    }
    
    return removeNode;
}
```

