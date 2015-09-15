int binarySearch(int A[], int L, int R, int key)
	int l = L;
	int r = R;
	while(l <= r)
		int mid = (l+r)/2;
		if(A[mid] == key) return mid;
		if(A[mid] < key) l = mid+1;
		else r = mid - 1;
	return -1;
