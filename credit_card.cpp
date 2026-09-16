#include <iostream>
using namespace std;

bool isValid(long long number);              // Return true if the card number is valid
int sumOfDoubleEvenPlace(long long number);   // Get the result from Step 2
int getDigit(int number);                     // Return single digit (sum digits if two-digit number)
int sumOfOddPlace(long long number);          // Return sum of odd place digits in number
bool prefixMatched(long long number, int d);  // Return true if digit d is a prefix for number
int getSize(long long d);                      // Return the number of digits in d
long long getPrefix(long long number, int k);  // Return the first k digits of number

int main() {
    long long cardNumber;
    // Step 1: Ask the user for a credit card number
    cout << "Enter a credit card number as a long integer: ";
    cin >> cardNumber;
    // Step 2: Check validity using our isValid function and display the result
    if (isValid(cardNumber)) {
        cout << cardNumber << " is valid" << endl;
    } else {
        cout << cardNumber << " is invalid" << endl;
    }
    return 0;
}
bool isValid(long long number) {
    // Check the length of the number (must be between 13 and 16 digits)
    int size = getSize(number);
    if (size < 13 || size > 16) {
        return false;
    }

    bool validPrefix = prefixMatched(number, 4) ||
 prefixMatched(number, 5) ||prefixMatched(number, 37) ||prefixMatched(number, 6);

    if (!validPrefix) {
        return false;
    }
    long long total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (total % 10 == 0);
}
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
 // Keep processing digits until the number becomes 0
    while (number != 0) {
// Remove the last digit (rightmost) first -> this is an "odd place" digit
 number = number / 10;
// The next digit (now at the end) is an "even place" digit from the right
int digit = static_cast<int>(number % 10);
// Double it, then reduce to a single digit if needed
sum += getDigit(digit * 2);
// Remove this digit too, so we move two places for the next loop
number = number / 10;
}
 return sum;
}
int getDigit(int number) {
    if (number < 10) {
        return number;
    } else {
        // Add the tens digit and the units digit
        return (number / 10) + (number % 10);
    }
}
int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number != 0) {
// The rightmost digit is always an "odd place" digit
 int digit = static_cast<int>(number % 10);
sum += digit;
// Skip two digits: one odd place (just used) and one even place
   number = number / 100;
    }
return sum;
}
bool prefixMatched(long long number, int d) {
    int digitsInD = getSize(d);
    // Get the same number of leading digits from "number"
    long long prefix = getPrefix(number, digitsInD);
    // Compare the prefix to d
    return (prefix == d);
}
int getSize(long long d) {
    int size = 0;
    while (d != 0) { d = d / 10;
    size++;
    }
    return size;
}
long long getPrefix(long long number, int k) {
    int totalDigits = getSize(number);

    if (totalDigits < k) {
        return number;
    }
    long long divisor = 1;
    for (int i = 0; i < totalDigits - k; i++) {
     divisor *= 10;
    }
    return number / divisor;
}