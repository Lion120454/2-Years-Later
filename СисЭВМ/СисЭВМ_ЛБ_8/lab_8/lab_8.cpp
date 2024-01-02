#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void blockSort(vector<double>& arr, int blockSize) 
{
    int n = arr.size();
    int numBlocks = (n + blockSize - 1) / blockSize;
    vector<double> blockMax(numBlocks, 0);
    vector<vector<double>> blocks(numBlocks);
    for (int i = 0; i < n; ++i) 
    {
        int blockIndex = i / blockSize;
        blocks[blockIndex].push_back(arr[i]);
        blockMax[blockIndex] = max(blockMax[blockIndex], arr[i]);
    }
    for (int i = 0; i < numBlocks; ++i) 
    {
        std::sort(blocks[i].begin(), blocks[i].end());
    }
    int index = 0;
    for (int i = 0; i < numBlocks; ++i) 
    {
        for (int j = 0; j < blocks[i].size(); ++j) 
        {
            if (blocks[i][j] == blockMax[i]) {
                swap(arr[index], arr[i * blockSize + j]);
                ++index;
                break;
            }
        }
    }
    sort(arr.begin() + index, arr.end());
}

void printArray(const vector<double>& arr) 
{
    for (double x : arr) 
    {
        cout << x << endl;
    }
    cout << endl;
}

int main() 
{
    setlocale(LC_ALL, "RU");
    vector<string> fileNames = { "input100.txt", "input1000.txt", "input10000.txt" };
    vector<int> blockSizes = { 5, 50, 500 };
    double time[3];
    for (int i = 0; i < fileNames.size(); ++i)
    {
        ifstream inputFile(fileNames[i]);
        vector<double> arr;
        double x;
        while (inputFile >> x)
        {
            arr.push_back(x);
        }
        inputFile.close();
        int blockSize = blockSizes[i];
        auto start = chrono::high_resolution_clock::now();
        blockSort(arr, blockSize);
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        printArray(arr);
        time[i] = elapsed.count();
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "Файл " << fileNames[i] << " отсортирован за " << time[i] << " секунды\n";
    }
    return 0;
}