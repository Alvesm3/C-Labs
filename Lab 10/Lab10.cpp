#include <iostream>
//has the necessary functions that is needed
#include <list>
#include <string>
//will be used for travesring through list 
#include <iterator>
//Input text file
#include <fstream>

using namespace std;
//Global Struct 
struct QB{
  string fname, lname;//i.e. Tom Brady
  int year;//i.e. 2017
};
//simple menu for user
char menu(){
    char choice;
    cout << "Menu\n";
    cout << "1. Add a player\n";
    cout << "2. Display the players\n";
    cout << "3. Search by name\n";
    cout << "4. Delete a player\n";
    cout << "5. Delete the whole list\n";
    cout << "6. Exit\n";
    cin >> choice;
    
    return choice;
} 
//prototype functions
void printlist(list<QB> qblist);
void search(list<QB> qblist);
/*I wanted to make functions for deleting a specific player
and deleting the entire list however when I tried passing in
the qblist it was not working. The solution was to put the 
functions in main. I'm still not sure why it didn't work
void deleteplayer(list<QB> qblist);
void deletall(list<QB> qblist);
*/

int main(){
    
    ifstream infile("Lab10_QB_List.txt");
    string afirst, alast;
    int years = 0;
    //instantiate a doubly linked list called qblist
    //Three parameters taken first name, last name, year
    list<QB> qblist;
    //Populate the list and add another entry to the end of the list
    while(infile >> afirst >> alast >> years){
        QB localEntry;
        localEntry.fname = afirst;
        localEntry.lname = alast;
        localEntry.year = years;
        qblist.push_back(localEntry);
    }
    
    char choice;
    while(choice != 6){
        //calling menu
        choice = menu();
        switch(choice){
            case '1':{
                cout << "Please add in a player\n";
                cin >> afirst >> alast >> years;
                
                QB localEntry;
                //set user inputs eqaul to parameters in struct
                localEntry.fname = afirst;
                localEntry.lname = alast;
                localEntry.year = years;
                //add the user input to the end of the list
                qblist.push_back(localEntry);
                }
                break;
            case '2':
            //calling print function
                printlist(qblist);
                break;
            case '3':
            //calling search function(user inputs name, function outputs year)
                search(qblist);
                break;
            case '4':{
                /*function call was not working so I put the function inside main
                and it worked (still puzzled on why that is)*/
                string afirst, alast;
                cout << "Enter the players name you wish to delete\n";
                 cin >> afirst >> alast;
                //need to iterate through entire list
                list<QB>::iterator it, tempit;
                int found = 0;
               //for beginning of list till the end
                for(it = qblist.begin(); it != qblist.end(); it++){
                //if the user inputted name equals a name in the list 
                if((it->fname == afirst) && (it->lname == alast)){
                    found = 1;
                    tempit = it;//set the iterated value (name entered) to a temporary value
                    qblist.erase(tempit);//erase that temporary value
                    it--; //decrement iterator 
                    }
                }
                //if the user enters an invalid input 
                if(!found){
                cout << "Invalid input\n";
                    }else{
                cout << afirst << " " << alast << " was deleted\n";
                    }
                }
                break;
            case '5':{
                /*Again function call did not work so I had to put the code
                in main*/
                list<QB>::iterator it, tempit;
                //iterate thorugh list
                for(it = qblist.begin(); it != qblist.end(); it++){
                   /*All the values are set to equal to temp iterator because 
                   there is no if statement to check if a specific word has been
                   entered*/
                    tempit = it;
                    qblist.erase(tempit);//delete all
                    it--;//decrement iterator
                    }cout << "List was deleted\n";
                }
                break;
            case '6':
                return 0;//exit
                break;
            default:
                cout << "Try Again\n";
        }
    }
    return 0;
}

void printlist(list<QB> qblist){
    list<QB>::iterator it;
    //iterate through the list
    for(it = qblist.begin(); it != qblist.end(); it++){
        //print out values in struct
        cout << it->fname << " " << it->lname << " " << it->year;
        cout << endl;
    }
}

void search(list<QB> qblist){
    string afirst, alast;
    list<QB>::iterator it;
    cout << "Enter in a players name to see the year they won\n";
    cin >> afirst >> alast;
    int found = 0;
    //iterate thorugh enitre list 
    for(it = qblist.begin(); it != qblist.end(); it++ ){
        //if the name entered equals a name found in the list
        if((it->fname == afirst) && (it->lname == alast)){
            found = 1;
            //print out the year of that player 
            cout << "Won in year: " << it->year << endl;
        }
    }
    if(!found){
        cout << "Invalid input\n";
    }
}

//did not use
/*void deleteplayer(list<QB> qblist){
    string afirst, alast;
    cout << "Enter the players name you wish to delete\n";
    cin >> afirst >> alast;
    
    list<QB>::iterator it, tempit;
    int found = 0;
    for(it = qblist.begin(); it != qblist.end(); it++){
        if((it->fname == afirst) && (it->lname == alast)){
            found = 1;
            tempit = it;
            qblist.erase(tempit);
            it--;
        }
    }
    if(!found){
        cout << "Invalid input\n";
    }else{
    cout << afirst << " " << alast << " was deleted\n";
}
}*/

/*void deletall(list<QB> qblist){
    list<QB>::iterator it, tempit;
    for(it = qblist.begin(); it != qblist.end(); it++){
        tempit = it;
        qblist.erase(tempit);
        it--;
    }
    cout << "The list was deleted\n";
}*/
