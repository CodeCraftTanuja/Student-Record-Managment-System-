#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to check how strong the password is
void checkPasswordQuality(bool inkUpper, bool inkLower, bool inkDigits, bool inkSpecial, int pwdLength) {
    int ratingPoints = 0;
    if (inkUpper) ratingPoints++;
    if (inkLower) ratingPoints++;
    if (inkDigits) ratingPoints++;
    if (inkSpecial) ratingPoints++;
    
    cout << "\n----------------------------------------" << endl;
    cout << "  PASSWORD SECURITY REPORT  " << endl;
    cout << "----------------------------------------" << endl;
    
    if (pwdLength < 8) {
        cout << "Security Status: POOR (Length should be at least 8)" << endl;
    } else if (ratingPoints == 4) {
        cout << "Security Status: EXCELLENT (Highly Secure)" << endl;
    } else if (ratingPoints == 3) {
        cout << "Security Status: GOOD" << endl;
    } else if (ratingPoints == 2) {
        cout << "Security Status: AVERAGE" << endl;
    } else {
        cout << "Security Status: POOR (Add more character variety)" << endl;
    }
    cout << "----------------------------------------" << endl;
}

int main() {
    // Making sure the random generator stays unique using time seed
    srand(static_cast<unsigned int>(time(0)));

    // Different sets of characters
    const string alphaSmall = "abcdefghijklmnopqrstuvwxyz";
    const string alphaCapital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string numericBits = "0123456789";
    const string specialChars = "@#$&!*?%=-_+^";

    int finalLength;
    char optUpper, optLower, optDigits, optSpecial;

    cout << "=== AUTOMATIC PASSWORD GENERATOR ===" << endl;
    
    cout << "Enter password size/length: ";
    cin >> finalLength;

    if (finalLength <= 0) {
        cout << "Invalid length entered!" << endl;
        return 1;
    }

    // Interactive user prompts
    cout << "Allow Capital Letters? (y/n): ";
    cin >> optUpper;
    cout << "Allow Small Letters? (y/n): ";
    cin >> optLower;
    cout << "Allow Numbers? (y/n): ";
    cin >> optDigits;
    cout << "Allow Special Symbols? (y/n): ";
    cin >> optSpecial;

    // Mapping inputs to true/false variables
    bool hasCaps = (optUpper == 'y' || optUpper == 'Y');
    bool hasSmall = (optLower == 'y' || optLower == 'Y');
    bool hasNums = (optDigits == 'y' || optDigits == 'Y');
    bool hasSyms = (optSpecial == 'y' || optSpecial == 'Y');

    // Merging selected characters into a master pool
    string masterPool = "";
    if (hasCaps)  masterPool += alphaCapital;
    if (hasSmall) masterPool += alphaSmall;
    if (hasNums)  masterPool += numericBits;
    if (hasSyms)  masterPool += specialChars;

    // Fallback option if user declines everything
    if (masterPool.length() == 0) {
        cout << "\n[Notice: No criteria selected. Using default lowercase options.]" << endl;
        masterPool = alphaSmall;
        hasSmall = true;
    }

    // Building the random password string
    string finalPassword = "";
    for (int idx = 0; idx < finalLength; idx++) {
        int position = rand() % masterPool.length();
        finalPassword += masterPool[position];
    }

    // Displaying the final result
    cout << "\nYour Secure Password: " << finalPassword << endl;
    
    // Evaluation call
    checkPasswordQuality(hasCaps, hasSmall, hasNums, hasSyms, finalLength);

    return 0;
}