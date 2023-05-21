//{ Driver Code Starts
//Initial Template for C

// } Driver Code Ends
//User function Template for C

int sumDiagonal(int N, int arr[][N])
{
   // your code here
   int sum=0;
   for(int i=0;i<N;i++)
   {
       for(int j=0;j<=i;j++)
       {
           if(i==j)
           {
               sum+=arr[i][j];
           }
       }
   }
   return sum;
}

//{ Driver Code Starts.

#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);
	
	while(t--)
	{
	    int N;
	    scanf("%d", &N);
	    
	    int M[N][N];
	    for(int i = 0; i < N; i++)
	    {
	        for(int j = 0; j < N; j++)
	        scanf("%d", &M[i][j]);
	    }
	    
	    printf("%d", sumDiagonal(N, M));
	    printf("\n");
	}
	return 0;
}
// } Driver Code Ends