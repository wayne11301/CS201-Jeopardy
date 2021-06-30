/*
This program simulate the game of Jeopardy game show, user can choose a category and an amount to see what quote is behind
*/
#include <iostream>
#include <string>

using namespace std;
const int NUM_CATEGORIES = 6, NUM_AMOUNTS = 5;

// linear search function, return the index of the target or -1 if the target is not found.
int findCategory(string categories[], string category) {
    for (int i=0; i < NUM_CATEGORIES; i++) {
        if (categories[i] == category) return i;
    }
    return -1; //target is not found.
}

//binary search helper function, reduce the size of the search area by half each time if the function didn't match the target
int binSearchHelper(int nums[], int lowIndex, int highIndex, int target) {
    if (lowIndex == highIndex) { //if only 1 item in the array
        if (nums[lowIndex] == target) return lowIndex;
        return -1; //target is not found.
    }

    int midIndex = (lowIndex + highIndex) / 2;

    // if target smaller than half-point of the array, look only at the left side next time
    if (target <= nums[midIndex]) return binSearchHelper(nums, lowIndex, midIndex, target);

    // if target greater than half-point of the array, look only at the right side next time
    return binSearchHelper(nums, midIndex + 1, highIndex, target);
}

int findMoney(int amounts[], int amount){
    //call helper function and provide all the parameters needed
    return binSearchHelper(amounts, 0, NUM_AMOUNTS - 1, amount);
}

int main()
{
    int col, row;
    string category;
    int amount;
    string categories[] = { "Before & After", "Science", "Literature", "American History", "Potpourri", "World History" };
    int amounts[] = { 100, 200, 300, 400, 500 };
    string board[][NUM_CATEGORIES] = { {"Mouselike boy in an E.B. White story traveling through the heavens as Ursa Minor", "Col1 Row0", "Col2 Row0", "Col3 Row0", "Col4 Row0", "Col5 Row0"},
                         {"Middle Eastern entertainment with rapid gyrations of the hips that's a reality TV show judged by Len Bruno & Carrie Ann", "Col1 Row1", "Col2 Row1", "Col3 Row1", "Col4 Row1", "Col5 Row1"},
                         {"Top U.N. official designed to cause loss of consciousness & of sensation in your whole body", "Col1 Row2", "Col2 Row2", "Col3 Row2", "Col4 Row2", "Col5 Row2"},
                         {"American daisy with dark center that was a leading U.S. suffragette", "Col1 Row3", "Col2 Row3", "Col3 Row3", "Col4 Row3", "Col5 Row3"},
                         {"The group assigned to protect the president proceeds through this door meant for delivery people & other help", "Col1 Row4", "Col2 Row4", "Col3 Row4", "Col4 Row4", "Col5 Row4"}
    };

    cout << "Jeopardy looking up clue" << endl<<endl<<"Categories: "<<endl;
    for (int i = 0; i < 6; i++) {
        cout << categories[i] << endl;
    }
    cout << "Category? ";
    getline(cin, category); //read in category
    int categIndex = findCategory(categories, category); //function call
    cout << "Amounts: ";
    for (int i = 0; i < 5; i++) {
        cout << amounts[i]<< " ";
    }
    cout << endl<<"Amount? "; //read in amount
    cin >> amount;
    int amountIndex = findMoney(amounts, amount); //function call
    if (categIndex == -1 || amountIndex == -1) {
        cerr << "error input"; //if one or both results are not found, output error message
    }
    else {
        cout << board[amountIndex][categIndex];
    }
    return 0;
}