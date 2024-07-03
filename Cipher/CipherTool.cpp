#include "CipherTool.h"

// Name: CipherTool Constructor
// Desc - Creates a new CipherTool and sets m_filename based on string passed
// Preconditions - Input file passed and populated with Cipher
// Postconditions - CipherTool created
CipherTool::CipherTool(string filename){
    m_filename = filename;
}

// Name: CipherTool Destructor
// Desc - Calls destructor for all ciphers in m_ciphers
// Preconditions - m_ciphers is populated
// Postconditions - m_ciphers deallocated and vector emptied
CipherTool::~CipherTool(){
    cout << "Destructing..." << endl;
    for (unsigned int i=0; i<m_ciphers.size(); i++){
        delete m_ciphers[i];
        m_ciphers[i] = nullptr;     // deallocating dynamic cipher
    }
    m_ciphers.resize(0);
}

// Name: StringToBoolean
// Desc - Helper function that converts a string to a boolean for reading in file
// Preconditions - Passed string of either 0 or 1
// Postconditions - Returns false if 0 else true
bool CipherTool::StringToBoolean(string input){ 
    if (stoi(input) == 0) {
        return false;
    }
    else {
        return true;
    }
}

// Name: LoadFile
// Desc - Opens file and reads in each Cipher. Each Cipher dynamically allocated
// and put into m_ciphers (c is Caesar, r is RailFence, and o is Ong)
// Preconditions - Input file passed and populated with Ciphers
// Postconditions - m_ciphers populated with Ciphers
void CipherTool::LoadFile(){
    string type, sbool, message, sshift;  // temporary strings 'sshift' & 'ssbool'
    bool boolean;
    int shift = 0;

    fstream newFile;
    newFile.open(m_filename);

    if (newFile.is_open()) {
    cout << "Opened File" << endl;

    while(getline(newFile, type, '|') &&
        getline(newFile, sbool, '|') &&
        getline(newFile, message, '|') &&
        getline(newFile, sshift))
{
    boolean = StringToBoolean(sbool); // conversion of ssbool

    if((type != "o") &&  (type!= "v")){
    shift = stoi(sshift); // implementing case for 'ong' cipher, conversion of sshift
    }

    Cipher *cipher;

    if (type == "c"){
        cipher = new Caesar(message, boolean, shift);
        }
        else if (type == "r"){
        cipher = new RailFence(message, boolean, shift);
      }
      else if (type == "o"){
        cipher = new Ong(message, boolean);
      }
      else if (typer == "v"){
        cipher = new Vignere(message, boolean, shift)
      }
       m_ciphers.push_back(cipher);
    }
    
    cout << "Ciphers Loaded" << endl;
    }
else {
    cout << "ERROR: File could not be found" << endl; 
}
newFile.close();
    }

// Name: DisplayCiphers
// Desc - Displays each of the ciphers in the m_ciphers
// Preconditions - Input file passed and m_ciphers populated
// Postconditions - Displays ciphers
void CipherTool::DisplayCiphers(){
    for (unsigned int i=0; i<m_ciphers.size(); i++)
        cout << i+1 << ". " << *m_ciphers[i]<< m_ciphers[i]->ToString() << endl;
}

// Name: EncryptDecrypt
// Desc - Encrypts or decrypts each of the ciphers in the m_ciphers
// Preconditions - Input file passed and m_ciphers populated
// Postconditions - Either Encrypts or Decrypts each cipher in m_ciphers
void CipherTool::EncryptDecrypt(bool toEncrypt){  
int index = 0;
  for (unsigned int i = 0; i < m_ciphers.size(); i++){
    if (toEncrypt){
      if (not m_ciphers[i]->GetIsEncrypted()){   // Encrypts cipher
	m_ciphers[i]->Encrypt();
	index++;
      }
         
    }else if (not toEncrypt){  
      if (m_ciphers[i]->GetIsEncrypted()){    
	m_ciphers[i]->Decrypt();    // Decrypts cipher
	index++;
      }
    }
  }

  if (toEncrypt == true){
    cout << index << " cipher(s) Encrypted "<< endl;
  }
  else if(toEncrypt == false){
    cout << index << " cipher(s) Encrypted " << endl;
  }
    
}

// Name: Menu
// Desc - Displays menu and returns choice
// Preconditions - m_ciphers all populated
// Postconditions - Returns choice
int CipherTool::Menu(){
int choice = 0;

while(choice !=5){
        cout << "What would you like to do?" << endl;
        cout << "1. Display all ciphers" << endl;
        cout << "2. Encrypt all ciphers" << endl; 
        cout << "3. Decrypt all ciphers" << endl;
        cout << "4. Export all ciphers" << endl;
        cout << "5. Quit" << endl; 
        cin >> choice;

        while(choice <1 || choice >5){
        cout << "Invalid input!" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Display all ciphers" << endl;
        cout << "2. Encrypt all ciphers" << endl; 
        cout << "3. Decrypt all ciphers" << endl;
        cout << "4. Export all ciphers" << endl;
        cout << "5. Quit" << endl; 
        cin >> choice;
        }

return choice;
}

return choice;
}


// Name: Start
// Desc - Loads input file, allows user to choose what to do
// Preconditions - m_ciphers populated with ciphers
// Postconditions - none
void CipherTool::Start(){
    LoadFile();

      int choice;

  do{
    choice = Menu();   //Calls Menu 

    if (choice == 1){   //Selector
      DisplayCiphers();
      
    }else if(choice == 2){
      EncryptDecrypt(true);   
      
    }else if (choice == 3){
      EncryptDecrypt(false);
    
    }else if (choice == 4){
      Export();
    }
  }while (choice != 5);
    
}

// Name: Export
// Desc - Exports each of the ciphers in the m_ciphers (so they can be reused)
// Preconditions - Input file passed and m_ciphers populated
// Postconditions - All ciphers exported
void CipherTool::Export(){
  string nameOfFile;
  int num = 0;
  
  cout << "What would you like to call the export file?" << endl;
  cin >> nameOfFile;
  
  ofstream newFile(nameOfFile);     // Opening file to write
  
  for (unsigned int i = 0; i < m_ciphers.size(); i++){
    newFile << m_ciphers[i]->FormatOutput();
    num++;      
  }
  cout << num << " ciphers exported" << endl;
  newFile.close();   // Closing file
}

  