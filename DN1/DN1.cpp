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

void countingSort(vector<int>& arr, int exp)
{
    //sortiramo stevila glede na bit 
    vector<int> output(arr.size());
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

void radixSort(vector<int>& arr)
{
    //najdemo stevilo bitov za najvišje število
    int maxVal = INT_MIN;
    for (const auto& num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    //sprehodimo se èez bite
    for (int k = 0; maxVal >> k > 0; k++) {
       countingSort(arr, k);
    }
}

void saveToFile(const string& filename, const vector<int>& numbers) {
    ofstream file(filename);
    if (file) {
        copy(numbers.begin(), numbers.end(), ostream_iterator<int>(file, "\n"));
    }
}

int main(int argc, char* argv[])
{
    vector<int> numbers;
    //vektor napolnimo s stevili
    readFromFile(argv[1], numbers);
    //stevila uredimo
    radixSort(numbers);
    //urejena stevila shranimo
    saveToFile("out.txt", numbers);
    return 0;
}
