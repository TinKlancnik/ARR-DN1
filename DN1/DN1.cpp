#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Stable counting sort algorithm for sorting the bits
void countingSort(vector<unsigned char>& arr, int exp)
{
    vector<unsigned char> output(arr.size());
    vector<int> count(2, 0);

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] >> exp) & 1]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] >> exp) & 1] - 1] = arr[i];
        count[(arr[i] >> exp) & 1]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// Binary Radix sort algorithm
void radixSort(vector<unsigned char>& arr)
{
    int maxVal = 255; // maximum value of 8-bit unsigned integer

    // Sort each bit using counting sort algorithm
    for (int exp = 0; maxVal >> exp > 0; exp++) {
        countingSort(arr, exp);
    }
}

int main(int argc, char* argv[])
{
    cout << "File" << argv[1] << endl;
    // Check if input file is provided
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    // Open input file
    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "Error: Could not open input file\n";
        return 1;
    }

    // Read input numbers into vector
    vector<unsigned char> numbers;
    unsigned char num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    // Sort the numbers using Binary Radix sort algorithm
    radixSort(numbers);

    // Open output file
    ofstream outputFile("out.txt");
    if (!outputFile) {
        cout << "Error: Could not open output file\n";
        return 1;
    }

    // Write sorted numbers to output file
    for (const auto& num : numbers) {
        outputFile << static_cast<int>(num) << " ";
    }

    return 0;
}
