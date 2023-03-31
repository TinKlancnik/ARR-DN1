#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void readFromFile(const string& filename, vector<int>& numbers) {

    ifstream file(filename);
    if (file) {
        copy(std::istream_iterator<int>(file),
            istream_iterator<int>(),
            back_inserter(numbers));
    }
}

void radixSort(vector<int>& arr)
{
    int maxVal = INT_MIN;
    for (const auto& num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }

    for (int k = 0; maxVal >> k > 0; k++) {
       // countingSort(arr, k);
    }
}
int main(int argc, char* argv[])
{
    vector<int> numbers;
    readFromFile(argv[1], numbers);
    radixSort(numbers);

    return 0;
}
