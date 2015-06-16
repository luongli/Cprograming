void max_heapify(int *A, int i, int len)
	left = 2*i;
	right = 2*i+1;

	if( (left <= len-1) && (A[i] < A[left]) )	largest = left;
	else largest = i;

	if( (right <= len-1) && (A[largest] < A[right]) ) largest = right;

	if(largest != i)
		tmp = A[largest];
		A[largest] = A[i];
		A[i] = tmp;
		max_heapify(A, largest, len);


void build_max_heap(int *A, int len)
	for(i = (len-1)/2; i> 0; i--)
		max_heapify(A, i, len);

void heap_sort(int *A, int len)
	build_max_heap(A, len);
	for(i = len-1; i >= 2; i--)
		swap(A[i], A[1]);
		len--;
		max_heapify(A, 1, len);
