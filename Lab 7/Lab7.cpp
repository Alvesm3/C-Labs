#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//creates player struct
struct player{
    string first, last;
    int year[5];
    int numWin;
    player *next;
    player *prev;
};

//menu for user
char menu(){
    char choice;
    cout << "Menu\n";
    cout << "1. Display the players\n";
    cout << "2. Add a player\n";
    cout << "3. Search(name, year, # of wins)\n";
    cout << "4. Delete a player\n";
    cout << "5. Exit\n";
    cin >> choice;

    return choice;
}

char menu1(){
    char choice;
    cout << "Menu\n";
    cout << "1. Display the award winners\n";
    cout << "3. Search(name, year)\n";
    cout << "4. Delete an award winner\n";
    cout << "5. Exit\n";
    cin >> choice;

    return choice;
}

class people{
public:
        people()
        {      
                cout << "A blank list is being created. \n ";
                populate1();
                //populate2();
        }
        ~people()
        {
                cout << "A list is being deleted. \n ";
                deleteall();
        }
        void createplayer(string, string, int);
        void add();
        void populate1();
        //void populate2();
        void search();
        void deleteplayer();
        void deleteall();
        void display();
private:
        player *head = NULL;
        player *ptr = NULL;
        player *sort = NULL;
};

int main(){
   int decision;
   cout << "Please select 1 for Quarterback List" << endl;
   cout << "Please select 2 for Eckert-Mauchly List" << endl;
   cin >> decision;
   char choice;
   people list_qb, list_em;
   if(decision == 1){
    do{
    choice = menu();
    switch(choice){
        case '1':
        list_qb.display();
        break;
        case '2':
        list_qb.add();
        break;
        case '3':
        list_qb.search();
        break;
        case '4':
        list_qb.deleteplayer();
        break;
        default:
        return 0;
    }

        }while(choice != '5');
    }
   else{
   if(decision == 2){
    do{
    choice = menu1();
    switch(choice){
        case '1':
        list_em.display();
        break;
        case '2':
        list_em.add();
        break;
        case '3':
        list_em.search();
        break;
        case '4':
        list_em.deleteplayer();
        break;
        default:
        return 0;
    }

        }while(choice != '5');
    }
}
return 0;
}

void people::createplayer(string first, string last, int year){
//creating a new player entry
  player *nptr = new player;
//setting up variable types first name, last name, year, and number of wins
  nptr->first = first;
  nptr->last = last;
  nptr->year[0] = year;
  nptr->numWin = 1;
//Checking the first entry
  if(head == 0){
    head = nptr;
    nptr->next = nptr;
    nptr->prev = nptr;
  }else{
    //linking the doubly linked list
    nptr->prev = ptr;
    nptr->next = ptr->next;
    ptr->next->prev = nptr;
    ptr->next = nptr;
}
}

void people::populate1(){
 // static int option = 1;
  int element = 0;
  ifstream qb;
    qb.open("Lab6_QB_List.txt");
//function to get information from text file
  string last;
  string first;
  int year;
//this algorithm will popualte the list
  while(!qb.eof()) {
    element++;
    qb >> first >> last >> year;
   //if the first element
    if(element == 1){
      ptr = head;
      createplayer(first, last, year);
    }else{
    //if the next element
    //intialize counters and indexes
      int count = 0;
      int index = 0;
      sort = 0;// pointer value intialized to zero
      player *temp;
      temp = head;//set temp equal to the beginning of the list
      //loop till all the elements have been inserted
      while(!count){
        if(last[index] > temp->last[index]){
          if((temp->next == sort) || (temp->next == head)){
            ptr = temp;
            createplayer(first, last, year);
            count++; //ends loop once reaches limit
          }else{
            sort = temp;
            temp = temp->next;
            index = 0;
          }
        }else if(last[index] < temp->last[index]){
          if(temp->prev == sort){
            ptr = temp->prev;
            createplayer(first, last, year);
            count++;
          }else{
            sort = temp;
            temp = temp->prev;
            index = 0;
          }
        }else{
          index++;
        }
      if(last == temp->last){
        if(first == temp->first){
          (temp->numWin)++;
          temp->year[(temp->numWin)-1] = year;
          count++;
}
}
}if (temp->last[0] < head->last[0])
        head = temp;
}if(element == 19)
        break;
}
   //  option++;
}

/*void people::populate2(){
    int element = 0;
    ifstream qb;
        qb.open("Lab7_EM_List.txt");
//function to get information from text file
  string last;
  string first;
  int year;
//this algorithm will popualte the list
  while(!qb.eof()) {
    element++;
    qb >> first >> last >> year;
   //if the first element
    if(element == 1){
      ptr = head;
      createplayer(first, last, year);
    }else{
    //if the next element
    //intialize counters and indexes
      int count = 0;
      int index = 0;
      sort = 0;// pointer value intialized to zero
      player *temp;
      temp = head;//set temp equal to the beginning of the list
      //loop till all the elements have been inserted
      while(!count){
        if(last[index] > temp->last[index]){
          if((temp->next == sort) || (temp->next == head)){
            ptr = temp;
            createplayer(first, last, year);
            count++; //ends loop once reaches limit
          }else{
            sort = temp;
            temp = temp->next;
            index = 0;
          }
        }else if(last[index] < temp->last[index]){
          if(temp->prev == sort){
            ptr = temp->prev;
            createplayer(first, last, year);
            count++;
          }else{
            sort = temp;
            temp = temp->prev;
            index = 0;
          }
        }else{
          index++;
        }
        if(last == temp->last){
        if(first == temp->first){
          (temp->numWin)++;
          temp->year[(temp->numWin)-1] = year;
          count++;
}
}
 
}if (temp->last[0] < head->last[0])
        head = temp;
}if(element == 13)
        break;
}
   //  option++;
}  
*/

void people::add(){

  int found = 0; //check to see is player is in list already
  cout << "Please enter in a name and year\n";
  string first, last;
  int year;
  cin >> first >> last >> year;
 //loop through entire list
for(player *temp = head->next ; temp != head ; temp = temp->next){
    if((first == temp->first) && (last == temp->last)){//if the name entered equals a name in the list
      (temp->numWin)++; //incremenet wins
      temp->year[(temp->numWin)-1] = year; //add year to player
      found++;//increment found
    }
  }if(!found){//if player is not found in list, then add him
    ptr = head->prev;
    createplayer(first, last, year);
  }
}

void people::search(){
  cout << "1. search by name\n";
  cout << "2. search by year\n";
  cout << "3. search by number of wins\n";
  cout << "4. exit\n";
  char choice;
  cin >>choice;
//exit
  if(choice == '4')
    return; //Searching for name
else if(choice == '1'){
    cout << "Enter the player's name" << endl;
    string first, last;
    cin >> first >> last;
//if name entererd equals first and last (first entry)
if(head->first == first){
    if(head->last == last){
        cout << head->first <<" "<< head->last << " ";//print name

for(int i = 0; i < head->numWin; i++){
          cout << head->year[i] << " ";//print year that player won superbowl
}
cout << endl;
}
}else{
      int found = 0;//if element is found
      player *temp;
      for(temp = head->next; temp != head; temp = temp->next){//iterate through list
      //if name entered equals first and last (all other case)
        if(temp->first == first){
          if(temp->last == last)
           cout << "Player: " << temp->first <<" "<< temp->last << " ";//print name
           for(int i = 0; i < temp->numWin; i++){
              cout << temp->year[i] << " ";//print year they won superbowl
           }cout << endl;
            found++;
        }

    }
    if(!found)
        cout << "Player not found" << endl;
    }
    return; //search for year
}else if(choice == '2'){
    cout << "Enter a year between 2000 and 2018" << endl;
    int year;
    cin >> year;
    int found = 0;
    for(int i = 0; i < head->numWin; i++){//loops through years
    //checks to see if year entered equals year in list
        if(head->year[i] == year){
        cout << "Player: " << head->first <<" "<< head->last << " " << endl;//print name
        found++;
      }
    }
    if(!found){
      player *temp;
      //other cases
      for(temp = head->next; temp != head; temp = temp->next){//loops through list
        for(int i = 0; i < temp->numWin; i++){
          if(temp->year[i] == year){//if year is found
            cout << "Player: " << temp->first <<" "<< temp->last << " " << endl;//print out name
            found++;
          }
        }
}
if(!found)
        cout << "The player was not found" << endl;
    }
    return;
  }
//search for number of wins else
if(choice == '3'){
    cout << "Enter players number of wins (Max is 5)" << endl;
    int numWin;
    cin >> numWin; //for first element
    if(head->numWin == numWin){//checks to see number entered equals number of wins in list
      cout << "Player: " << head->first <<" "<< head->last << " " << endl;//print name
}else{
      int found = 0; //all other cases
      player *temp;
      for(temp = head->next; temp != head; temp = temp->next){//loop through list
        if(temp->numWin == numWin){ //check to see if number entered equals numver of wins in list
          cout << "Player: " << temp->first <<" "<< temp->last << " " << endl;//print name
          found++;
          }
      }
        if(!found)
        cout << "The player was not found" << endl;

    return;
  }
}
}

void people::deleteplayer(){
  cout << "Please enter a name\n" << endl;
  string first, last;
  cin >> first >> last;
  player *del_ptr;//pointer that selects which element will be deleted
  int found = 0; //if name entered equals name in list
  if(head->first == first){
        if(head->last == last){
            del_ptr = head;//pointer to be deleted equal to head
            head = head->next; //set head equal to head next
            found++;
}
}
else{
    player *temp;
    for(temp = head->next; temp != head; temp = temp->next){ //loop through the rest of the list
       //if the name entered equals name in list
        if(temp->first == first){
            if(temp->last == last){
                del_ptr = temp;//pointer to temp
                found++;
}
}
}
}
if(found){
    //link the list
    del_ptr->prev->next = del_ptr->next;
    del_ptr->next->prev = del_ptr->prev;
    delete del_ptr;//delete specific element

    cout << "Player was removed" << endl;
}
else{
    cout << "Player not found" << endl;
  }
}

void people::deleteall(){
  player *deleted = head;//initalize deleted pointer to beginning of list
  head->prev->next = 0;//head = 0
//loop through list
  while(deleted){
    head = head->next;//set head equal to head next to create room to delete
    delete deleted;//delete the all the pointer values that is iterating through the list
    deleted = head;//reinitalize deleted pointer to head
    }
}

void people::display(){ 
player *current; 
for(current = head->next; current != head; current = current->next){//loop through entire list
if(current == head->next){//print first element Tom Brady
    cout << head->first << " " << head->last << " ";
    //print the years for each player
    for(int i = 0; i < head->numWin; i++){
    cout << head->year[i] << " ";
    }
cout << endl;
}//print the remaining players and years
cout << current->first << " " << current->last << " "; for(int i = 0; i < current->numWin; i++){
    cout << current->year[i] << " ";
}
cout << endl;
}
}
