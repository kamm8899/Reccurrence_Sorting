#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include <string.h>

/* 
 * HW 2 part
 */
int string_compare(char* s1, char *s2)
{ 
/*
 * We assume that s1 and s2 are non-null pointers
 */
  int i;

  i = 0;
  while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]))
    i++;

  if (s1[i] == s2[i])
    return 0;
  else
    {
      if (s1[i] < s2[i])
	return -1;
      else
	return 1;
    }
} /*>>>*/

void insertion_sort(char** A, int l, int r)
{ 
  int i;
  char* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (string_compare(A[i], key) > 0))
        {
	  A[i+1] = A[i];
	  i = i - 1;
	}

      A[i+1] = key;
    }
}

void insertion_sort_digit(char** A, int* A_len, int l, int r, int d)
{
    //
    int i;
    char* key;
    
    for( int j= l+1;j<=r;j++){
        //"abcd" d=0
        //flip the position from left to right
       int keyDigit = strlen(A[j])-(1+d);
        key=A[j][keyDigit];
        i = j-1;
        int otherDigit = strlen(A[i])-(1+d);
        
        while((i>=l)&& (string_compare(A[i][otherDigit],key)>0)){
            
            
        }
    }

    



}


void counting_sort_digit(char** A, int* A_len, char** B, int* B_len, int n, int d)
{
//    int i;
//    //Step 1 Create new array
//    int counting[256/*not sure what to put in here*/];
//
//    //first loop that counts
//    for(i=0;i<256;i++){
//        counting[i]=0;
//    }
//    //update new array
//    for(int j=0; j<n; j++){
//        counting[A[j][d]] = counting[A[j][d]]+1;
//    }
//    else{
//        counting[0] = counting[0]+1;
//                 }
//
//    for(int i=0;i<256;i++){
//        counting[i]= counting[i]+counting[0];
//    }
//    //copy elements and move back to array
//    for(int j=n-1;j>=0;j--){
//        if(B_len[j]>= d){
//            B_len[counting[A[j][d]]-1] = A_len[j];
//            B[counting[A[j][d]]-1] =A[j];
//
//            //decrement array
//            counting[A[j][d] = counting[A[j][d]]-1;
//
//            }
//
//
//        }
                 
    


}

void radix_sort_is(char** A, int* A_len, int n, int m)
{ 
    for(int i=m-1; i>0;i++){
        //grab the insertionsort_digit recursively
        insertion_sort_digit(A,A_len, 0, n-1,i);
    }
}

void radix_sort_cs(char** A, int* A_len, int n, int m)
{

    for(int i=m-1;i>0;i++){
        //grab the countingsort_digit recursively
//        counting_sort_digit(A,A_len,B, B_len,n-1,i)
        
    }
    

}

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(char** A, int l, int r)
{
  for (int i = l+1; i < r; i++)
    if (string_compare(A[i-1],A[i]) > 0)
      return false;
  return true;
}
