#include<bits/stdc++.h>
using namespace std;

void knapsack(int n, float profit[],float weight [], float M)
{
    float x[20], tp=0;
    int i,j;
    cout<<"\nEntered items are : "<<endl;
    cout<<"Value\t\t\tProfit: "<<endl;
    cout<<"\n-------------------\n";
    for(i=0;i<n;i++)
    {
        cout<<profit[i]<<"\t\t\t"<<weight[i]<<endl;
    }

    for(i=0;i<n;i++)
        x[i]=0.0;
    for( i=0;i<n;i++)
    {
        if(weight[i]>M)
            break;
        else
        {
            x[i]=1.0;
            tp+=profit[i];
            M-=weight[i];
        }
    }
    if(i<n)
    {
        x[i]= M/weight[i];
    }
    tp+=x[i]*profit[i];
    cout<<"\n\nProfit Vector is : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<x[i]<<"\t";
    }
    cout<<"\n";
    cout<<"\nTotal Profit : "<<tp<<endl;
}


int main()
{
    float weight[20],profit[20], Ratio[20], capacity, temp;
    int n;
    cout<<"Enter no of items : "<<endl;
    cin>>n;
    cout<<"Enter Capacity : "<<endl;
    cin>>capacity;
    cout<<"Enter weight and profit : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter weight and profit for item "<<i<<": "<<endl;
        cin>>weight[i]>>profit[i];
    }

    for(int i=0;i<n;i++)
    {
        Ratio[i]=profit[i]/weight[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(Ratio[i]<Ratio[j])
            {
                temp=Ratio[j];
                Ratio[j]=Ratio[i];
                Ratio[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
       cout<< Ratio[i]<<" ";
    }
    cout<<endl;
    knapsack(n,profit,weight,capacity);
    return 0;

}
