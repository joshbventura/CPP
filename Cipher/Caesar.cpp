#include "Caesar.h"

// Name: Caesar (Default Constructor)
// Desc: Constructor to build an empty Caesar Cipher (Defaults to shift 3)
// Preconditions - None
// Postconditions - Creates a Caesar cipher to be encrypted
Caesar::Caesar():Cipher(){
    m_shift = 3;
}

// Name: Caesar (Overloaded Constructor)
// Desc: Constructor to build a populated Caesar Cipher (Defaults to shift 3)
// Preconditions - Pass it the message, isEncrypted, and shift (any integer)
// Postconditions - Creates a Caesar cipher to be encrypted
Caesar::Caesar(string message, bool isEncrypted, int shift):Cipher(message, isEncrypted){
    m_shift = shift;
}

// Name: Encrypt
// Desc: Shifts characters right based on shift (lower stay lower, upper stay upper)
// Preconditions - Message exists
// Postconditions - Shifts each character "right".
void Caesar::Encrypt(){
  string newMessage = "";
  
  for (int i = 0; i < int(GetMessage().length()); i++){
    char character = GetMessage()[i];
    
    if (character >= 'A' and character <= 'Z'){
      character += m_shift;
      
      if (character > 'Z'){
	character = character % 'Z'  + 'A' - 1;
      }
    }

    else if (character >= 'a' and character <= 'z'){
      character += m_shift; 
      
      if (character > 'z'){
	character = character % 'z' + 'a'  - 1 ;
      }
    }
    newMessage += character;
  }
  SetMessage(newMessage);
  ToggleEncrypted();
}

// Name: Decrypt
// Desc: Shifts characters left based on shift (lower stay lower, upper stay upper)
// Preconditions - Message exists
// Postconditions - Shifts each character "left".
void Caesar::Decrypt(){
  string newMessage = "";
  
  for (int i = 0; i < int(GetMessage().length()); i++){
    char character = GetMessage()[i];
    
    if (character >= 'A' and character <= 'Z'){
      character -= m_shift;
      
      if (character < 'A'){
	character = 'Z' - ('A' % character -1);
      }
    }

    else if (character >= 'a' and character <= 'z'){
      character -= m_shift; 
      
      if (character < 'a'){
	character =  'z' - ('a' % character - 1);
      }
    }
    newMessage += character;
  }
  SetMessage(newMessage);
  ToggleEncrypted();
}

// Name: ToString
// Desc - A function that returns the string of the object type
// Preconditions - The object exists
// Postconditions - The subtype is returned (Caesar in this case)
string Caesar::ToString(){
    return "(Caesar)";
}

// Name: FormatOutput()
// Desc - A function that returns the formatted output for Output function
// Preconditions - The object exists (use stringstream)
// Postconditions - c, delimiter, isencrypted, delimiter,
//                  message, delimiter, m_shift are returned for output
string Caesar::FormatOutput(){
    ostringstream out;
    if (GetMessage().empty()){
        cout << "Error: Empty message" << endl;
    }
    else {
        out << "c" << DELIMITER << int(GetIsEncrypted()) << DELIMITER << GetMessage() << DELIMITER << m_shift << endl;
    }
    return out.str();
}


// Name: Caesar (Destructor)
// Desc: Destructor - Anything specific to Caesar to delete?
// Preconditions - ~Caesar exists
// Postconditions - Caesar destroyed
Caesar::~Caesar(){
    cout << "Destructing Caesar cipher..." << endl;
}