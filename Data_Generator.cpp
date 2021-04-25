#include <iostream>

#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

static void generateData(string fileName, int amountOfData)
{
    int randomNumber = 0;

    srand((int)time(0));

    ofstream file;
    file.open(fileName);

    file << amountOfData << endl; //first line is amount of data

    for (size_t i = 0; i < amountOfData; i++)
    {
        randomNumber = (rand() % amountOfData) + 1;
        file << randomNumber << endl; //next lines are data
    }

    file.close();

    cout << "data generated" << endl;
}

int main()
{

    int amountOfData = 1500000;

    string fileName = "test_data/1_5m/tdata10.txt";

    generateData(fileName, amountOfData);

    return 0;
}