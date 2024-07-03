#include "RailFence.h"

// Name: RailFence (Default Constructor)
// Desc: Constructor to build an empty RailFence Cipher (Defaults to 3 rails)
// Preconditions - None
// Postconditions - Creates a RailFence cipher
RailFence::RailFence():Cipher(){
    m_rails = 3;
}

// Name: RailFence (Overloaded Constructor)
// Desc: Constructor to build a populated RailFence Cipher (Defaults to 3 rails)
// Preconditions - Pass it the message, isdecrypt, and number of rails (any integer)
// Postconditions - Creates a RailFence cipher to be decrypt
RailFence::RailFence(string message, bool isdecrypt, int rails):Cipher(message, isdecrypt){
    m_rails = rails;
}

// Name: RailFence (Destructor)
// Desc: Destructor - Anything specific part of RailFence to delete?
// Preconditions - ~RailFence exists
// Postconditions - RailFence destroyer
RailFence::~RailFence(){
    cout << "Destructing RailFence cipher" << endl;
}


// Name: ToString
// Desc - A function that returns the string of the object type
// Preconditions - The object exists
// Postconditions - The subtype is returned (RailFence in this case)
string RailFence::ToString(){
    return "(RailFence)";
}

// Name: Decrypt
// Desc: Single decrypt string is pushed back on the rails and reversed
// Preconditions - Message exists
// Postconditions - The decrypted string is stored
void RailFence::Decrypt(){
  char fence[m_rails][(GetMessage().size())];
  string upOrDown; // used to change direction of 'fence'
  int row = 0;    

  for (int i = 0; i < m_rails; i++){
    for (unsigned int j = 0; j < GetMessage().size(); j++){
      fence[i][j] = '!' ; // populate 'fence' with '!'
    }
  }
  for (unsigned int i = 0; i < GetMessage().size(); i++){
     if (row == 0){
      upOrDown = "down";    
    }else if (row == m_rails - 1){
      upOrDown = "up";
    }
       fence[row][i] = '$'; 
    if (upOrDown == "down"){
      row++;
    }else{
      row--;
    }
  }
  unsigned int counter = 0;
  for(int i = 0; i < m_rails; i++){
    for(unsigned int j = 0; j < GetMessage().size(); j++){
      
      if (fence[i][j] == '$' and counter < GetMessage().size()){ 
	fence[i][j] = GetMessage()[counter];
	counter++;
      }
    }
  }

  string decrypt = "";
  row = 0;
  for (unsigned int i = 0; i < GetMessage().size(); i++){
    if (row == 0){
      upOrDown = "down";
    }else if (row== m_rails - 1){ 
      upOrDown = "up";
    }
    if (fence[row][i] != '!'){
      decrypt += fence[row][i]; // strings together letters
    }
    if (upOrDown == "down"){
      row++;
    }else{
      row--;
    }
  }
  SetMessage(decrypt);
  ToggleEncrypted();
}

// Name: Encrypt()
// Desc: Letters are placed on a fence rail based on the number of rails
//       Letters are read from one rail at a time into a single string
// Preconditions - Message exists
// Postconditions - A single decrypt string is stored
void RailFence::Encrypt(){
  char fence[m_rails][(GetMessage().size())];
  string upOrDown;
  int rail = 0;

  for (int i = 0; i < m_rails; i++){
    for (unsigned int j = 0; j < GetMessage().size(); j++){
      fence[i][j] = '!' ; // populate 'fence' with '!'
    }
  }

  for (unsigned int i = 0; i < GetMessage().size(); i++){
    
      if (rail == 0){
        upOrDown = "down";
      }else if (rail == m_rails - 1){
        upOrDown = "up";
      }
      
      fence[rail][i] = GetMessage()[i];
      
      if (upOrDown == "down"){
        rail++;
      }else{
        rail--;
      }
    }

  string encrypted = "";
  
  for (int i = 0; i < m_rails; i++){
    for (unsigned int j = 0; j < GetMessage().size(); j++){ 
      
      if (fence[i][j] != '!'){
        encrypted += fence[i][j]; // strings together letters
      }
    }
  }
  SetMessage(encrypted);
  ToggleEncrypted();
}


// Name: FormatOutput()
// Desc - A function that returns the formatted output for Output function
// Preconditions - The object exists (use stringstream)
// Postconditions - r, delimiter, isencrypted, delimiter,
//                  message, delimiter, m_rails are returned for output
string RailFence::FormatOutput(){
    ostringstream out;
    if (GetMessage().empty()){
        cout << "Error: Empty message" << endl;
    }
    else {
        out << "c" << DELIMITER << int(GetIsEncrypted()) << DELIMITER << GetMessage() << DELIMITER << endl;
    }
    return out.str();

}
