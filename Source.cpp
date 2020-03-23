#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {
    public:
        Stack() {

        }

        void push(int num) {
            nums.push_back(num);
        }

        void pop() {
           
            nums.pop_back();
        }

        void inc(int numFromBottom, int numToAdd) {
            if (numFromBottom > nums.size()) {
                cout << "not enough numbers\n";
                return;
            }

            for (int i = 0; i < numFromBottom; i++) {
                nums[i] += numToAdd;
            }
        }

        bool empty() {
            return nums.size() == 0;
        }

        int top() {
            return nums.back();
        }

        void print() {
            for (int num : nums)
                cout << num << " ";
        }

    private:
        vector<int> nums;
};

void superStack(vector<string> operations) {
    Stack s;

    for (auto operation : operations) {
        if (operation.substr(0, 4) == "push") {
            s.push(stoi(operation.substr(operation.find(" ") + 1)));

        }
        else if (operation.substr(0, 3) == "pop") {
            s.pop();
            if (s.empty())
                cout << "EMPTY\n";
        }
        else if(operation.substr(0, 3) == "inc"){
            int end = operation.find(" ", 5) + 1;
            int numFromBottom = stoi(operation.substr(4, operation.find(" ", 5)));
            int numToAdd = stoi(operation.substr(end));
            

            s.inc(numFromBottom, numToAdd);
        }

        if(!s.empty())
            cout << s.top() << endl;
    }

  //  s.print();
}

int main()
{
    superStack({ "push 15", "pop", "push -51", "pop", "push 41", "pop", "push -76", "push 51", "push -10", "inc 1 -49" });
    //string s = "inc 3 1";
    //cout << s.find(" ", 5) << endl;

    return 0;
}
