//psuedocode for maximum subsequence problem

findMaxCrossSubarray(A, low, mid, high)

	leftSum = -INF;
	sum = 0;
	for(i = mid downto low)
		sum += A[i];
		if(leftSum < sum)
			leftSum = sum;
			leftMax = i;

	rightSum = -INF;
	sum = 0;
	for(i = mid+1 to high)
		sum += A[i];
		if(rightSum < sum)
			rightSum = sum;
			rightMax = i;

	return(leftMax, RightMax, leftSum + rightSum);


findMaxSubarray(A, low, high)
	
	if(low == high)
		return(low, high, A[low]);
	else
		mid = [low + high]/2;
		(leftLow, leftHigh, leftSum) = findMaxSubarray(A, low, mid);
		(rightLow, rightHigh, rightSum) = findMaxSubarray(A, mid+1, high);
		(crossLow, crossHigh, crossSum) = findMaxCrossSubarray(A, low, mid, high);

		if(leftSum > rightSum && leftSum > crossSum) return(leftLow, leftHigh, leftSum);
		else if(rightSum > leftSum && rightSum > corssSum) return(rightLow, rightHigh, rightSum);
		else return(crossLow, crossHigh, crossSum);
