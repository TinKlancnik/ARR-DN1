#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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

    vector<int> numbers;
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        int num;
        while (iss >> num) {
            numbers.push_back(num);
            cout << num << ", ";
        }
    }
        return 0;
}
