//function merge
merge(A, p, q, r)
	n1 = q - p + 1;
	n2 = r - q;
	L[n1+1];
	R[n2+1];
	
	for(i = 0; i < n1; i++)
		L[i] = A[p+i];

	for(i = 0; i < n2; i++)
		R[i] = A[q+i+1];

	L[n1] = END;
	R[n2] = END;

	i = 0;
	j = 0;

	for(k = p; k <= r; k++)
		if(L[i] <= R[j])
			A[k] = L[i];
			i++;
		else
			A[k] = R[j];
			j++;

mergeSort(A, p, r)
	if(p < r)
		q = (p+r)/2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	
