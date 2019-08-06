#include <iostream>
//we want the code from people.h to be included in this program
#include "people.h"
/*After 8 labs I am still using "using namespace std;"
Will I ever stop using it? Eventually yea...*/
using namespace std;

int main(){
    //create a series of pointers for each class and create a new object where values are passed in 
    //one instantiation for each class
    person *pPerson = new person("Matthew Alves",20,"Boston");
    student *pStudent = new student("Seekonk High",2016,"June 25th");
    intern *pIntern = new intern("Wentworth", 500, "December 12th");
    
    /*You could use get functions to print everthing but it is rather tedious and creating a print function is much easier
    cout << pPerson->getName() << ", " << pPerson->getAge() << ", " << pPerson->getCity() << endl;
    cout << pStudent->getSchool() << ", " << pStudent->getYear() << ", " << pStudent->getDate() << endl;
    cout << pIntern->getCompany() << ", " << pIntern->getPay() << ", " << pIntern->getDateofcompletion() << endl;
    */
    
    //pointer is used to traverse through the array and two of each type is created
    person *array[6] = {
        //new array elements
        new person("Ethan Santos", 17, "Seekonk"),
        new student("Seekonk High", 2019, "June 20th"),
        new intern("Boeing", 500, "December 31st"),
        new person("John Solari", 20, "Farmington"),
        new student("Farmington High", 2016, "June 19th"),
        new intern("MKS Instruments", 500, "May 8th") 
    };
    //print the array
    for(int i = 0; i < 6; i++){
        array[i]->print();
    }
    //menu pops up and asks the user what they want to do
    char choice;
    //enter 6 to exit
    while(choice != 6){
    choice = menu();
    switch(choice){
    case '1':
    //person wants to access print function 
        pPerson->print();
        pStudent->print();
        pIntern->print();
        break;
    case '2':
    //student wants to access addskills function
        pStudent->addSkills();
        break;
    case '3':
    //student wants to access printskills function
        pStudent->printSkills();
        break;
    case '4':
    //intern wants to access addinternskills function
        pIntern->addinternskills();
        break;
    case '5':
    //intern wants to access printinternskills function
        pIntern->printinternskills();
        break;
    default:
    //if the user decides to go rogue and press anything other than 1-6 then exit
        return 0;
    }
}    
    //code ran successfully!
    return 0;
}
