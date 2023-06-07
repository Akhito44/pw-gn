/* Password Generator */

#include <iostream>
#include <ctime>
using namespace std;

struct password_type {
    bool uppercase, lowercase, number, special;
    unsigned short length;
};

bool Boolonizer(char choice) {
    char letter = tolower(choice);

    if(letter == 'y') return true;
    else return false;
}

password_type Parameters() {
    password_type type;
    char choice;

    cout<<"|*--------- PASSWORD GENERATOR ---------*|\n\n";
    cout<<" Choose the type of combination!\n";

    cout<<" - Password length: ";
    cin>>type.length;
    cin.ignore(256,'\n');

    cout<<" - Uppercase (Y/N): ";
    cin>>choice;
    cin.ignore(256,'\n');
    type.uppercase = Boolonizer(choice);

    cout<<" - Lowercase (Y/N): ";
    cin>>choice;
    cin.ignore(256,'\n');
    type.lowercase = Boolonizer(choice);

    cout<<" - Number (Y/N): ";
    cin>>choice;
    cin.ignore(256,'\n');
    type.number = Boolonizer(choice);

    cout<<" - Special characters (Y/N): ";
    cin>>choice;
    cin.ignore(256,'\n');
    type.special = Boolonizer(choice);

    cout<<"\n\n";
    return type;
}

string Generator(const password_type &type) {
    string password;
    string uppercase_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercase_letters = "abcdefghijklmnopqrstuvwxyz";
    string numbers = "0123456789";
    string special_characters = "!@#$%^&*()_+";
    string possible_characters;

    if (type.uppercase) possible_characters += uppercase_letters;
    if (type.lowercase) possible_characters += lowercase_letters;
    if (type.number) possible_characters += numbers;
    if (type.special) possible_characters += special_characters;

    srand(time(0));

    for (short i=0; i<type.length; i++) password += possible_characters[rand()%possible_characters.length()];

    return password;
}

int main() {
    password_type password = Parameters();
    cout<<" Generated password: "<<Generator(password)<<endl;

    cout<<"\n\n ";
    system("pause");
    return 0;
}
