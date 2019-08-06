#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printMenu()//creates the prompt for the user, will repeat
{
        cout << endl << "------------------ \n";
        cout << "Enter 0 to exit \n";
        cout << "Enter 1 to search for a word in word search 1\n";
        cout << "Enter 2 to search for a word in word search 2\n";
    
}

//function for searching up in Lab3_WordSearch1
void searchup(int i, int j, int q, int k, string word, char (&word1)[10][10]);
//function for searching down in Lab3_WordSearch1
void searchdown(int i, int j, int q, int k, string word, char (&word1)[10][10]);
//function for searching left in Lab3_WordSearch1
void searchleft(int i, int j, int q, int k, string word, char (&word1)[10][10]);
//function for searching right in Lab3_WordSearch1
void searchright(int i, int j, int q, int k, string word, char (&word1)[10][10]);

//function for searching up in Lab3_WordSearch2
void searchup1(int m, int n, int o, int p, string word, char (&word2)[10][10]);
//function for searching down in Lab3_WordSearch2
void searchdown1(int m, int n, int o, int p, string word, char (&word2)[10][10]);
//function for searching left in Lab3_WordSearch2
void searchleft1(int m, int n, int o, int p, string word, char (&word2)[10][10]);
//function for searching right in Lab3_WordSearch2
void searchright1(int m, int n, int o, int p, string word, char (&word2)[10][10]);

int main(){
//inputting function for both word searches
ifstream infile("Lab3_WordSearch1.txt");
ifstream infilex("Lab3_WordSearch2.txt");
//initializations
int i, j, q, k, m, n, o, p;
int found = 0;
string word;
int choice=0;
char word1[10][10] = {' '};//character array that will be used for word search
char word2[10][10] = {' '};

//Repeat whats inside
do{
    
    printMenu();
    cin >> choice;
    
    if(choice == 1)//option 2 in menu
        {   
        for(int i = 0; i < 10; i++){//rows (0,0) - (9,0) for Lab3_WordSearch1
        for(int j = 0; j < 10; j++)//column (0,0) - (0,9) together (0,0)-(9,9)
        {
                infile >> word1[i][j];//same as cin  >> word1[i][j]
                cout << "  " << word1[i][j];//displays the characters from the $
        }
        cout << endl;
        }
        
        cout << "Please type in a word to search for\n";//prompt the user for a word
        cin >> word;//user can enter anything they like
        for(int i=0; i<word.length(); i++)
        {
        word[i] = toupper(word[i]);//Since the character array is in all capital letters this converts any lowercase letters that the user enters to uppercase
        }
        //calling functions to search for word that matches in Lab3_WordSearch1.txt
        searchup(i, j, q, k, word, word1);
        searchdown(i, j, q, k, word, word1);
        searchleft(i, j, q, k, word, word1);
        searchright(i, j, q, k, word, word1);
        }

       if(choice == 2)//option 3 in menu
        {
        for(int m = 0; m < 10; m++){//for Lab3_WordSearch2
        for(int n = 0; n < 10; n++)
        {
                infilex >> word2[m][n];
                cout << "  " << word2[m][n];
        }
        cout << endl;
        }
        
        cout << "Please type in a word to search for\n";
        cin >> word;
        for(int i=0; i<word.length(); i++)
        {
        word[i] = toupper(word[i]);
        }
        //calling functions to search for word that matches in Lab3_WordSearch2.txt
        searchup1(m, n, p, o, word, word2);
        searchdown1(m, n, p, o, word, word2);
        searchleft1(m, n, p, o, word, word2);
        searchright1(m, n, p, o, word, word2);
        }


    }while(choice != 0);//option 1 in menu

return 0;
}

//Declaring function prototype for up, pass by reference array
void searchup(int i, int j, int q, int k, string word, char (&word1)[10][10])
{
for(int i = 0; i < 10; i++){//rows
for(int j = 0; j < 10; j++){//columns
        if(word1[i][j] == word[0])//checks to see if first letter of word entered equals a letter within the character array
                {
//need to iterate through the length of the word because it will vary depending on what the user enters 
//set q = i which is the row and decrement q as we are searching up, therefore decrement row
                for(int q = i, k = 0; k <= word.length(); k++, q--)
                {
                if(q < 0)//checks bounds
                {
                        break;//q = i (row < 0) then terminate
                }
                if(word1[q][j] != word[k])//checks to see if the iterating word in the character array does not equal the word entered
                {
                        break;//terminate
                }
                if(word1[q][j] == word[word.length()-1])///checks to see if the iterating word in the character array does equal the word entered
                {
                cout << word << " starts at " << i << "," << j  << " and is going up\n";//if so print out word, its starting coordinates, and direction
                cout << "The memory address of: " << word << " is at " << &word;//for fun print out its memory address
                }
}
}
}
}
}
//Declaring function prototype for down, pass by reference array
void searchdown(int i, int j, int q, int k, string word, char (&word1)[10][10])
{
for(int i = 0; i < 10; i++){//rows
for(int j = 0; j < 10; j++){//columns
        if(word1[i][j] == word[0])//checks to see if first letter of word entered equals a letter within the character array
                {
//need to iterate through the length of the word because it will vary depending on what the user enters
//set q = i which is the row and increment q as we are searching down, therefore increment row
                for(int q = i, k = 0; k <= word.length(); k++, q++) 
                {
                if(q < 0)//checks bounds
                {
                        break;//q = i (row < 0) then terminate
                }
                if(word1[q][j] != word[k])//checks to see if the iterating word in the character array does not equal the word entered
                {
                        break;//terminate
                }
                if(word1[q][j] == word[word.length()-1])//checks to see if the iterating word in the character array does equal the word entered
                {
                cout << word << " starts at " << i << "," << j  << " and is going down\n";//same as above
                cout << "The memory address of " << word << " is at " << &word;//same as above
                }
    
}
}
}
}
}
//Declaring function prototype for left, pass by reference array
void searchleft(int i, int j, int q, int k, string word, char (&word1)[10][10])
{
for(int i = 0; i < 10; i++){//rows
for(int j = 0; j < 10; j++){//columns
        if(word1[i][j] == word[0])//checks to see if first letter of word entered equals a letter within the character array
                {
                for(int q = j, k = 0; k <= word.length(); k++, q--)
                {
                if(q < 0)//checks bounds
                {
                        break;//q = i (row < 0) then terminate
                }
                if(word1[i][q] != word[k])//checks to see if the iterating word in the character array does not equal the word entered
                {
                        break;//terminate
                }
                if(word1[i][q] == word[word.length()-1])//checks to see if the iterating word in the character array does equal the word entered
                {
                cout << word << " starts at " << i << "," << j  << " and is going left\n";//print word, starting coordinates, direction            
                cout << "The memory address of " << word << " is at " << &word;//print memory address
                }

}
}
}
}
}
//Declaring function prototype for right, pass by reference array
void searchright(int i, int j, int q, int k, string word, char (&word1)[10][10])
{
for(int i = 0; i < 10; i++){//rows
for(int j = 0; j < 10; j++){//columns
        if(word1[i][j] == word[0])//checks to see if first letter of word entered equals a letter within the character array
                {
                for(int q = j, k = 0; k <= word.length(); k++, q++)
                {
                if(q < 0)//checks bounds
                {
                        break;//q = i (row < 0) then terminate
                }
                if(word1[i][q] != word[k])//checks to see if the iterating word in the character array does not equal the word entered
                {
                        break;//terminate
                }
                if(word1[i][q] == word[word.length()-1])//checks to see if the iterating word in the character array does equal the word entered
                {
                cout << word << " starts at " << i << "," << j  << " and is going right\n";//print word, starting coordinates, and direction
                cout << "The memory address of " << word << " is at " << &word;//print memory address
                }
}
}
}
}
}

/*See comments for functions above as the the functions below are the same 
except for different initializations as these functions access word search 2*/

//Declaring function prototype for up, pass by reference array
void searchup1(int m, int n, int o, int p, string word, char (&word2)[10][10])
{
for(int m = 0; m < 10; m++){
for(int n = 0; n < 10; n++){
                if(word2[m][n] == word[0])
                {
                for(int o = m, p = 0; p <= word.length(); p++, o--)
                {
                if(o < 0)
                {
                        break;
                }
                if(word2[o][n] != word[p])
                {
                        break;
                }
                if(word2[o][n] == word[word.length()-1])
                {
                cout << word << " starts at " << m << "," << n  << " and is going up\n";                
                cout << "The memory address of " << word << " is at " << &word;
                }
}
}
}
}
}
//Declaring function prototype for down, pass by reference array
void searchdown1(int m, int n, int o, int p, string word, char (&word2)[10][10])
{
for(int m = 0; m < 10; m++){
for(int n = 0; n < 10; n++){
                if(word2[m][n] == word[0])
                {
                for(int o = m, p = 0; p <= word.length(); p++, o++)
                {
                if(o < 0)
                {
                        break;
                }
                if(word2[o][n] != word[p])
                {
                        break;
                }
                if(word2[o][n] == word[word.length()-1])
                {
                cout << word << " starts at " << m << "," << n  << " and is going down\n";
                cout << "The memory address of " << word << " is at " << &word;
                }
}
}
}
}
}
//Declaring function prototype for left, pass by reference array
void searchleft1(int m, int n, int o, int p, string word, char (&word2)[10][10])
{
for(int m = 0; m < 10; m++){
for(int n = 0; n < 10; n++){
                if(word2[m][n] == word[0])
                {
                for(int o = n, p = 0; p <= word.length(); p++, o--)
                {
                if(o < 0)
                {
                        break;
                }
                if(word2[m][o] != word[p])
                {
                        break;
                }
                if(word2[m][o] == word[word.length()-1])
                {
                cout << word << " starts at " << m << "," << n  << " and is going left\n";
                cout << "The memory address of " << word << " is at " << &word;
                }
}
}
}
}
}
//Declaring function prototype for right, pass by reference array
void searchright1(int m, int n, int o, int p, string word, char (&word2)[10][10])
{
for(int m = 0; m < 10; m++){
for(int n = 0; n < 10; n++){
                if(word2[m][n] == word[0])
                {
                for(int o = n, p = 0; p <= word.length(); p++, o++)
                {
                if(o < 0)
                {
                        break;
                }
                if(word2[m][o] != word[p])
                {
                        break;
                }
                if(word2[m][o] == word[word.length()-1])
                {
                cout << word << " starts at " << m << "," << n  << " and is going right\n";
                cout << "The memory address of " << word << " is at " << &word;
                }
}
}
}
}
}
