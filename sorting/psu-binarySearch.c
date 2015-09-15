//binary search algorithm
//function binarySearch

int binarySearch(A[], int p, int r, int x)
  if p <= r
    int q = [(p+r)/2];
    if(A[q] == x)
      return q;
    else
      if(x < A[q])
        return binarySearch(A, p, q, x);
      else
        return binarySearch(A, q+1, r, x);
	return -1;
