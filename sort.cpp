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


void insertion_sort_digit(char** A, int* A_len, int l, int r, int d){
    //initialize variables
    int i;
    char* key;
    int k_len;
    
    char A_i_d, key_d;
    //cout<<*A_len<<endl;
    for( int j= l+1;j<=r;j++){
        //"abcd" d=0
        //"abcde"
        
        //flip the position from left to right
        key = A[j];
        k_len= A_len[j];
//        key=(A[j][keyDigit]);
        i = j-1;
        
        A_i_d = (A_len[i]<d) ? 0: A[i][d];
        key_d = (k_len<d) ? 0 : key[d];

        while((i>=l)&& (A_i_d> key_d)){
            A[i+1]= A[i];
            A_len[i+1] = A_len[i];
            i=i-1;
            if (i>=l)
                A_i_d =(A_len[i]<d) ? 0: A[i][d];
        }
            A[i+1]= A[i];
            A_len[i+1]= k_len;
        }

    }



void counting_sort_digit(char** A, int* A_len, char** B, int* B_len, int n, int d){
//int i;
    //Step 1 Create new array
    int counting[256];
    

    //first loop that counts
    for(int i=0;i<256;i++){
        counting[i]=0;
    }
    //update new array
    for(int j=0; j<n; j++){
        if (A_len[j]>=d){
            counting[A[j][d]] = counting[A[j][d]]+1;
        }
        else{
            counting[0] = counting[0]+1;
        }
    }

    for(int i=1;i<256;i++){
        counting[i]= counting[i]+counting[i-1];
    }
    //copy elements and move back to array
    for(int j=n-1;j>=0;j--){
        if(A_len[j]> d){
            B_len[counting[A[j][d]]-1] = A_len[j];
            B[counting[A[j][d]]-1] =A[j];

            //decrement array
            counting[A[j][d]] = counting[A[j][d]]-1;
            }
        else{
            B_len[counting[0]-1]=A_len[j];
            B[counting[0]-1]= A[j];
            counting[0]--;
        }
        }
    }
    
void radix_sort_is(char** A, int* A_len, int n, int m){
    //should this be m-1 or m?
    for(int i=m-1; i>=0;i++){
        
        //grab the insertionsort_digit recursively
        insertion_sort_digit(A,A_len, 0, n-1,i);
    }
}

void radix_sort_cs(char** A, int* A_len, int n, int m)
{

    char** B = new char*[n]; //B
    int* B_len = new int[n]; //B_len
    char** temp_A;
    int* temp_A_len;
    char** temp_B;
    int* temp_B_len;
    char** temp;
    int* temp_len;
    
    temp_A = A;
    temp_A_len = A_len;
    temp_B = B;
    temp_B_len = B_len;

    for(int i=m-1;i>=0;i--){
        //grab the countingsort_digit recursively
        counting_sort_digit(temp_A, temp_A_len, temp_B, temp_B_len,n,i);
        temp = temp_A;
        temp_A = temp_B;
        temp_B = temp;
        
        temp_len = temp_A_len;
        temp_A_len = temp_B_len;
        temp_B_len = temp_len;
    }
                         
    for(int i=0;i<n;i++){
        A[i]=temp_A[i];
        A_len[i]=temp_A_len[i];
    }
    delete[] B;
    delete[] B_len;
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
