#include "Ong.h"

// Name: Ong (Default Constructor)
// Desc: Constructor to build an empty Ong Cipher
// Preconditions - None
// Postconditions - Creates a Ong cipher to be encrypted
Ong::Ong():Cipher(){}


// Name: Ong (Overloaded Constructor)
// Desc: Constructor to build a populated Ong Cipher
// Preconditions - Pass it the message and isEncrypted
// Postconditions - Creates a Ong cipher to be encrypted
Ong::Ong(string message, bool isEncrypted):Cipher(message, isEncrypted){}


// Name: Ong (Destructor)
// Desc: Destructor - Anything unique to Ong to delete?
// Preconditions - ~Ong exists
// Postconditions - Ong destroyed
Ong::~Ong(){
    cout << "Destructing ong cipher" << endl;
}


// Name: IsVowel (Helper function)
// Desc: Returns true if vowel, space, or punctuation
// Preconditions - Message exists
// Postconditions - Returns true or false as above
bool Ong::IsVowel(char character){
if(char(tolower(character)) == 'a' || char(tolower(character)) == 'e' || char(tolower(character)) == 'i' || char(tolower(character)) == 'o' || char(tolower(character)) == 'u' || character == '.' || character == ',' || character == ' ' || character == ')' || character == '(' ){
    return true;     // returns true if any of these characters are present
}          
else{
    return false;
}
return true;
}


// Name: ToString
// Desc - A function that returns the string of the object type
// Preconditions - The object exists
// Postconditions - The subtype is returned (Ong in this case)
string Ong::ToString(){
    return "(Ong)";  // used to display ong cipher type
}


// Name: FormatOutput()
// Desc - A function that returns the formatted output for Output function
// Preconditions - The object exists (use stringstream)
// Postconditions - o, delimiter, isencrypted, delimiter,
//                  message, delimiter, blank are output
string Ong::FormatOutput(){
    ostringstream out;
    if (GetMessage().empty()){
        cout << "Error: Empty message" << endl;
    }
    else {
        out << "c" << DELIMITER << int(GetIsEncrypted()) << DELIMITER << GetMessage() << DELIMITER << endl;
    }
    return out.str();
}


// Name: Encrypt
// Desc: If vowel then vowel and dash displayed. dog = dong-o-gong
// If consonant then consonant and ong and dash displayed.
// Preconditions - Message exists
// Postconditions - Encrypts as above
void Ong::Encrypt(){

string newString = "";

for (unsigned int i = 0; i < (GetMessage().length()); i++){
    if (IsVowel(GetMessage()[i])){
        newString = newString + GetMessage()[i];
    }
    else{
        newString = newString + GetMessage()[i] + "ong";
    }
     if ((GetMessage()[i] != ' ') && (GetMessage()[i+1] != ' ') && (i != GetMessage().size() -1)){
     newString += "-";
     }
}
 SetMessage(newString);
  ToggleEncrypted();
}


// Name: Decrypt
// Desc: Removes the dashes and "ong" when necessary cong-a-tong = cat
// Double check words like "wrong" so that they work correctly!
// Preconditions - Message exists
// Postconditions - Original message is displayed
void Ong::Decrypt(){
  string newString = "";
  for (unsigned int index = 0; index < GetMessage().size(); index++){
    if (GetMessage()[index] != '-'){
      
      if (GetMessage()[index+1] == 'o' and GetMessage()[index+2] == 'n' and GetMessage()[index+3] == 'g'){
	newString += GetMessage()[index];
	index = index+3;

      }else if (IsVowel(GetMessage()[index])){
	    newString += GetMessage()[index];
      }
    }
  }
  SetMessage(newString);
  ToggleEncrypted();
}

