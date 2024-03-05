#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

void takeInput();
void calculateResult();
void targetFound(vector<int> array, int a, int b);

vector<int> givenNums;
int inputNums;
int target;
int addition;
bool numFound = false;

int main() {
  takeInput();
} 

void takeInput(){
    

    cout << "enter the target number\n";
    cin >> target;

    cout << "enter your list of numbers\n";
    cout << "enter numbers one at a time and enter any key that is not a number when done\n";
    while(cin >> inputNums){
      givenNums.push_back(inputNums);
    }
      
    calculateResult();
}

void calculateResult(){

   int n = givenNums.size();

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {

        addition = givenNums[i] + givenNums[j];

        if (givenNums[i] == givenNums[j])
        {
          continue;
        }

        else if(addition == target && !numFound){
          targetFound(givenNums, givenNums[i], givenNums[j]);
          numFound = true;
          return;
        }
      }  
   }

}

void targetFound(vector<int> array, int a, int b){

        auto first = find(givenNums.begin(), givenNums.end(), a);
        auto second = find(givenNums.begin(), givenNums.end(), b);

            if (first != givenNums.end() && second != givenNums.end()) {
        int index1 = first - givenNums.begin();
        int index2 = second - givenNums.begin();

        if (index1 > index2) {
            swap(index1, index2);
        }

        cout << "[" << index1 << "," << index2 << "]" << endl;
    } 
    
}