#include <bits/stdc++.h>
#include <utility>

using namespace std;

pair<pair<float, float>, pair<int, float>> a[1000000]; // first.first -> cgpa, first.second -> credit, second.first -> id, second.second-> ratio

int n;

void merge_sort(pair<pair<float, float>, pair<int, float>> a[], int size)
{
    if(size==1)
    {
        return;
    }

    int leftSize = size/2;
    int rightSize = size-leftSize;

    pair<pair<float, float>, pair<int, float>> left[leftSize];
    pair<pair<float, float>, pair<int, float>> right[rightSize];

    for(int i=0; i<leftSize; i++)
    {
        left[i] = a[i];
    }
    for(int i=leftSize; i<size; i++)
    {
        right[i-leftSize] = a[i];
    }

    merge_sort(left, leftSize);
    merge_sort(right, rightSize);

    int leftMarker = 0;
    int rightMarker = 0;
    int i = 0;

    while(leftMarker<leftSize && rightMarker<rightSize)
    {
        if(left[leftMarker].second.second <= right[rightMarker].second.second)
        {
            a[i] = left[leftMarker];
            i++;
            leftMarker++;
        }
        else
        {
            a[i] = right[rightMarker];
            i++;
            rightMarker++;
        }
    }
    while(leftMarker < leftSize)
    {
        a[i] = left[leftMarker];
        i++;
        leftMarker++;
    }
    while(rightMarker < rightSize)
    {
        a[i] = right[rightMarker];
        i++;
        rightMarker++;
    }
}

void scholarship_list(pair<pair<float, float>, pair<int, float>> a[], int size)
{
    cout << "Scholarship List: \n";
    for (int i = n-1; i >= n/2; i--)
    {
        cout << "Student ID: " << a[i].second.first << ", with ratio: " << a[i].second.second << endl;
    }
}

int main()
{
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("Enter the CGPA: \n");
    for(int i=0; i<n; i++)
    {
        cout << "Input CGPA: ";
        cin >> a[i].first.first;
        cout << "Input Credit: ";
        cin >> a[i].first.second;

        a[i].second.first = i;
        a[i].second.second = a[i].first.second / a[i].first.first;
    }
    merge_sort(a, n);
    scholarship_list(a, n);
    return 0;
}
