/*
 * maximum subsequence
 */

#include<stdio.h>
#include "/home/li/Cprograming/luong.h"
#include<time.h>

#define INF 1000000000

typedef int mytype;

typedef struct {
  mytype low;
  mytype high;
  mytype sum;
} MaxSub;

//prototpye
MaxSub findMaxSubarray(mytype *A, mytype low, mytype high);
MaxSub findMaxCrossSubarray(mytype *A, mytype low, mytype mid, mytype high);
void setMaxSub(MaxSub *mySub, mytype low, mytype high, mytype sum);
MaxSub findMaxSub_Dynamic(mytype *A, int len);
void printResult(MaxSub mySub, double time_spent);

int main(int argv, char **argc)
{

  if(argv != 3){
    printf("Wrong command.\n");
    return 1;
  }

  srand(time(NULL));

  int len = atoi(argc[2]);
  int i;
  clock_t begin, end;
  double time_spent;

  if(len < 1){
    printf("The number of elements must be larger than 0.\n");
    return 1;
  }

  mytype *A = malloc(len*sizeof(mytype));
  MaxSub mySub, mySub2;

  //generate data for computation
  generateData(A, argc[1], -1000, 1000, len);

  //for(i = 0; i < len; i++) printf("%d ", A[i]);
  printf("\n");

  printf("Using recursive method\n");
  begin = clock();
  mySub = findMaxSubarray(A, 0, len-1);
  end = clock();
  time_spent = (double) (end - begin)/CLOCKS_PER_SEC;
  printResult(mySub, time_spent);

  printf("\nUsing dynamic method\n");
  begin = clock();
  mySub2 = findMaxSub_Dynamic(A, len);
  end = clock();
  time_spent = (double) (end - begin)/CLOCKS_PER_SEC;
  printResult(mySub, time_spent);

  free(A);

}//end main

MaxSub findMaxSub_Dynamic(mytype *A, int len)
{
  int i;
  mytype sum = A[0];
  MaxSub max = {A[0], 0, 0};

  for(i = 1; i < len; i++){
    sum += A[i];
    if((A[i] >= max.sum) && (A[i]) >= sum){
      max.sum = sum;
      max.low = i;
      max.high = i;
      sum = A[i];
    }else if((sum > max.sum) && (sum > A[i])){
	max.sum = sum;
	max.high = i;
      }//end nested if
  }//end for

  return max;

}//end findMaxSub_Dynamic

MaxSub findMaxSubarray(mytype *A, mytype low, mytype high)
{
  
  if(low == high){
    MaxSub baseSub;
    //setMaxSub(&baseSub, low, high, sum);
    baseSub.low = low;
    baseSub.high = high;
    baseSub.sum = A[low];

    return baseSub;
  }

  int mid = (low + high)/2;

  MaxSub leftSub = findMaxSubarray(A, low, mid);
  MaxSub rightSub = findMaxSubarray(A, mid+1, high);
  MaxSub crossSub = findMaxCrossSubarray(A, low, mid, high);

  if(leftSub.sum > rightSub.sum && leftSub.sum > crossSub.sum) return leftSub;
  else if(rightSub.sum > leftSub.sum && rightSub.sum > crossSub.sum) return rightSub;
  else return crossSub;

}


MaxSub findMaxCrossSubarray(mytype *A, mytype low, mytype mid, mytype high)
{

  MaxSub crossSub;
  int i;
  int leftMost, rightMost;
  mytype sum = 0;
  mytype leftSum = -INF;
  mytype rightSum = -INF;

  for(i = mid; i >= low; i--){
    
    sum += A[i];
    if(leftSum < sum){
      leftSum = sum;
      leftMost = i;
    }//end if

  }//end for

  //find max right
  sum = 0;
  for(i = mid+1; i <= high; i++){
    
    sum += A[i];
    if(rightSum < sum){
      rightSum = sum;
      rightMost = i;
    }//end if

  }//end for

  crossSub.low = leftMost;
  crossSub.high = rightMost;
  crossSub.sum = leftSum + rightSum;

  return crossSub;

}//end findMaxCrossSubarray

/*
void setMaxSub(MaxSub *mySub, mytype low, mytype high, mytype sum)
{
  
  mySub->low = low;
  mySub->high = high;
  mySub->sum = sum;
  
}//end sutMaxSub
*/

void printResult(MaxSub mySub, double time_spent)
{
  printf("The maximum subsequence is from A[%d] to A[%d]\n", mySub.low, mySub.high);
  printf("Its sum is %d\n", mySub.sum);
  printf("The running time is %lf\n", time_spent);

}
