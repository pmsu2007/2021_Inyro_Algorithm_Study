## 정렬

데이터를 특정한 기준에 따라서 순서대로 나열하는 것

- ### 선택 정렬

선택정렬(Selection Sort)은 정렬되지 않은 데이터들에 대해 **가장 작은 데이터**를 찾아 가장 앞의 데이터와 교환해나가는 정렬이다.

<img src="https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif" alt="img" style="zoom:80%;" />

- 과정

1. 주어진 배열 중 최솟값을 찾는다.
2. 최솟값을 맨 앞에 위치한 값과 교체한다.
3. 맨 처음 위치를 뺀 나머지 배열을 하나의 원소만 남을 때 까지 위의 과정을 반복한다.

- 코드

``` c++ 
void selectionSort()
{
    for (int i = 0; i < MAXLEN; i++)
    {
        int minValue = arr[i];
        int location = i;
        for (int j = i + 1; j < MAXLEN; j++)
        {
            if (minValue > arr[j])
            {
                minValue = arr[j];
                location = j;
            }
        }
        swap(arr[i], arr[location]);
    }
}
```

- 시간 복잡도

선택 정렬은 `N-1`번 만큼 가장 작은 수를 찾아서 맨 앞으로 보내야 하고, 매번 가장 작은 수를 찾기 위해서 비교 연산이 필요하다. 따라서, 선택 정렬의 시간 복잡도는 O(N^2^)이다.

- ### 삽입 정렬

기존의 배열의 모든 값을 앞부터 정렬된 배열과 비교하여 들어갈 위치를 찾고, 그 위치에 삽입하며 정렬해나가는 방법이다. 따라서, 데이터가 거의 정렬되어 있을 때 효율적이다.

<img src="https://upload.wikimedia.org/wikipedia/commons/e/ea/Insertion_sort_001.PNG" alt="img" style="zoom:80%;" />

- 과정

1. 첫 번째 요소는 그 자체로 정렬되어 있다고 판단하기 때문에 두 번째 요소부터 시작한다.
2. 두 번째 데이터를 정렬된 배열에 어떤 위치로 들어갈지 판단해 삽입한다.
3. 위 과정을 반복한다.

- 코드

```C++
void insertionSort()
{
    for (int i = 1; i < MAXLEN; i++)
    {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = key;
    }
}
```

- 시간 복잡도

삽입 정렬의 시간 복잡도는 O(N^2^) 이다. 배열이 거의 정렬되어 있는 상태인 경우 O(N)의 시간 복잡도를 가진다. 이 때는 퀵 정렬보다 훨씬 빠른 속도를 보인다.

- ### 퀵 정렬

하나의 배열이 있을 때, 피벗(pivot)을 기준으로 두 개의 비균등한 크기로 분할하고 분할된 부분 리스트를 정렬한 다음, 두 개의 정렬된 부분 배열을 합하여 전체가 정렬된 배열이 되게 하는 방법이다.



<img src="https://gmlwjd9405.github.io/images/algorithm-quick-sort/quick-sort.png" alt="img" style="zoom: 25%;" />

- 과정

1. 배열에서 첫 번째 원소를 피벗(pivot)으로 선택한다.
2. 피벗을 기준으로 피벗보다 작은 요소들은 모두 피벗의 왼쪽으로 옮겨지고 피벗보다 큰 요소들은 모두 피벗의 오른쪽으로 옮겨진다.
3. 피벗을 제외한 왼쪽 배열과 오른쪽 배열을 다시 정렬한다.
4. 위 과정을 부분 배열들이 더 이상 분할이 불가능할 때 까지 반복한다.

- 코드

```c++
int partition(int s, int e) // pivot 위치 리턴
{
    int pivot, left, right;
    left = s + 1;
    right = e;
    pivot = arr[s];

    while (left <= right)
    {
        while ((pivot >= arr[left]) && (left <= right)) // pivot 보다 큰 값 찾기
            left++;
        while ((pivot <= arr[right]) && (left <= right)) // pivot 보다 작은 값 찾기
            right--;
        if (left <= right)
            swap(arr[left], arr[right]);
    }
    swap(arr[s], arr[right]); // left, right 엇갈릴 때
    return right;
}

void quickSort(int s, int e)
{
    if (s >= e)
        return;
    int m = partition(s, e);
    quickSort(s, m - 1);
    quickSort(m + 1, e);
}
```

- 시간 복잡도

퀵 정렬의 시간복잡도는 O(NlogN)이다. 그러나 이미 데이터가 정렬되어있는 상태인 최악의 경우일 때 시간 복잡도는 O(N^2^)가 된다.

- ### 계수 정렬

특정한 조건이 부합할 때만 사용할 수 있는 정렬 방법이다.

데이터의 크기 범위가 제한되어 정수 형태로 표현할 수 있을 때 사용할 수 있고 일반적으로 가장 큰 데이터와 가장 작은 데이터의 차이가 1,000,000을 넘지 않을 때 효과적으로 사용할 수 있다.

계수 정렬은 직접 데이터의 값을 비교한 뒤에 위치를 변경하며 정렬하는 방식이 아닌 별도의 배열을 선언하고 그 배열안에 정렬에 대한 정보를 담는다는 특징이 있다.

<img src="https://devjin-blog.com/static/e76265aba4274a04f7c8f8e3d84a7dc7/fcda8/counting_sort_2.png" alt="counting sort 2" style="zoom: 80%;" />

- 과정

1. 가장 큰 데이터와 가장 작은 데이터의 범위가 모두 담길 수 있도록 0으로 초기화된 하나의 배열을 생성한다.
2. 데이터를 하나씩 확인하며 데이터의 값과 동일한 인덱스의 데이터를 1 씩 증가시킨다.
3. 배열의 첫 번째 데이터부터 하나씩 그 값만큼 출력하면 된다.

- 코드 

```C++
void countingSort()
{
    int* counting = new int[*max_element(arr, arr + MAXLEN) + 1];
    
    for (int i = 0; i <= MAXLEN; i++)
        counting[i] = 0;

    for (int i = 0; i < MAXLEN; i++)
    {
        counting[arr[i]]++;
    }

    for (int i = 0; i < MAXLEN; i++)
    {
        for (int j = 0; j < counting[i]; j++)
        {
            cout << i << " ";
        }
    }
    cout << '\n';
}
```
- 시간 복잡도

모든 데이터가 양의 정수인 상황에서 데이터의 개수를 N, 데이터 중 최대값의 크기를 K라고 할 때, 계수정렬의 시간 복잡도는 O(N + K)이다.

- 공간 복잡도

계수 정렬은 데이터 간 값의 차이가 크면 오히려 비효율적인 메모리 사용을 초래할 수 있다. 따라서, 동일한 값을 가지는 데이터이가 여러 개 등장할 때 적합하다.

