#include <iostream>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

Job jobs[100];

void sortJobs(int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - 1 - i; j++)
        {
            if (jobs[j].profit <= jobs[j + 1].profit)
            {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of jobs -  ";
    cin >> n;
    cout << "Enter job id, deadline & profit" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    int maxDeadline = 0;
    for (int i = 1; i <= n; i++)
    {
        if (maxDeadline < jobs[i].deadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }
    int slot[100];
    int jobId[100];
    for (int i = 1; i <= maxDeadline; i++)
    {
        slot[i] = 0;
    }

    sortJobs(n);

    int totalProfit = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = jobs[i].deadline; j >= 1; j--)
        {
            if (slot[j] == 0)
            {
                slot[j] = 1;
                jobId[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    cout << "Selected jobs -  ";
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (slot[i] == 1)
        {
            cout << jobId[i] << " ";
        }
    }
    cout << "Maximum profit -  " << totalProfit << endl;
    return 0;
}