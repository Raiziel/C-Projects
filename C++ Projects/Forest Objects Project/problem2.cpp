/*
    * Name:Nicholas Munoz, 2000781568, Section 1004
    * Description: recursive reverse string
    * Input: Define in main
    * Output: Results to console
*/

#include <iostream>
using namespace std;

// ****************************************************************

//  YOUR CODE HERE

void reverse(string& word, int left, int right)
{

    string temp = word;
    int count = right;
    for (int i = left; i < word.length(); i++)
    {
        word[i] = temp[count];
        count--;
    }




}
// *********************************************************
//  Basic tests

int main()
{
    string  strArr[] = {
                "hello",
                "racecar",
                "tattarrattat",
                "some long string",
                "animal loots foliated detail of stool lamina"
    };
    int strSize = sizeof(strArr) / sizeof(strArr[0]);

    cout << "Recursion Problem 2 - Reverse String" << endl << endl;

    for (int i = 0; i < strSize; i++) {
        cout << i << ": " << strArr[i] << endl;
        reverse(strArr[i], 0, strArr[i].size() - 1);
        cout << "R: " << strArr[i] << endl << endl;
    }

    return	EXIT_SUCCESS;
}