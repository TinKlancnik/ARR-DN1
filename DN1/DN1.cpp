#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void readFromFile(const string& filename, vector<int>& numbers) {


    // Open input file
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error: Could not open input file\n";
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        int num;
        while (iss >> num) {
            numbers.push_back(num);
        }
    }
}
void radixSort(vector<int>& arr)
{
    int maxVal = 255;

    for (int k = 0; maxVal >> k > 0; k++) {
        //countingSort(arr, exp);
    }
}

int main(int argc, char* argv[])
{
    vector<int> numbers;
    readFromFile(argv[1], numbers);

    return 0;
}
