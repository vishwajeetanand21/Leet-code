//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    // STEP 2: Write a custome comparator which will find out the value to weight ratio 
    // and sort it in descending order
    bool static comparator(Item a, Item b)
    {
        double valueWeightRatioA=(double) a.value / (double) a.weight; //value to weight ratio of first item
        double valueWeightRatioB=(double) b.value / (double) b.weight; //value to weight ratio of second item
        
        
        return valueWeightRatioA > valueWeightRatioB;
        //the ratio of first item should be greater than the second
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //STEP 1: sort the array of Item in decending order of value to weight ratio
        sort(arr, arr+n, comparator);
        
        
        // STPE 3: Maintain 2 variables
        int currWeight=0; //this will store the current weight of the knapsack
        double finalValue=0.0; //this will store the final value of all item
        
        
        // STEP 4: Traverse all the elements from left to right
        // Because item whose value is greater will be on left and item whose value of less will be on right
        for(int i=0;i<n;i++)
        {
            if(currWeight+arr[i].weight <= W)
            //this means that if we add this item after that knapsack will has some empty space
            {
                currWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            
            else if(currWeight+arr[i].weight > W)
            //this means that if we add this item, our knapsack will be over weight: 
            // SO WE HAVE TO TAKE FRACTION OF THIS ITEM
            {
                int remainingWeight=W-currWeight;//calculating the remaining faction needed
                
                double valueWeightRatio=(double) arr[i].value / (double) arr[i].weight;
                //calculating the value to weight ratio of this element
                
                finalValue += valueWeightRatio*remainingWeight;
                //finally adding the value of this fraction item to the answer variable 
                break;
            }
        }
        
        //STEP 5: return the answer 
        return finalValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends