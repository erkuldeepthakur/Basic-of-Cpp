#include <iostream>
#include <string>
using namespace std;

void print_full_name(string first, string last) {
    // Print the formatted string
    cout << "Hello " << first << " " << last << "! You just delved into function." << endl;
}

int main() {
    string first_name, last_name;

    // Input
    getline(cin, first_name);  // Read the first name
    getline(cin, last_name);  // Read the last name

    // Call the function
    print_full_name(first_name, last_name);

    return 0;
}
