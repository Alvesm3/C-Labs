#include <string> 

using namespace std;
//create a struct so that a linked list for skills can be created
struct skills{
    string studentskill, internskill;//different skills, one from school one from job
    skills *next;//pointer will be used for iterating through list
};
//Two lists, one for for student and one for intern
skills *head = 0;
skills *head1 = 0;
//menu to be used in main
char menu(){
    char choice;
    cout << "Menu\n";
    cout << "1. Display all classes\n";
    cout << "2. Add a skill you learned in class\n";
    cout << "3. Display skills you have learned as a student\n";
    cout << "4. Add a skill you learned as an intern\n";
    cout << "5. Display skills you have learned as an intern\n";
    cout << "6. Exit\n";
    cin >> choice;
   
    return choice;
}
//Base Class
class person{
	protected://classes that inherit public person will have access to these variables 
		string name;
		int age;
		string city;
	public://make constructors, deconstructors, set, and get functions public so that main has access to them
		person(){ //blank constructor (Would need to be redefined with default values but is not necessary in this lab)
		    cout << "A blank person was created.\n";
		}//constructor with parameters allows for a more specific object
        person(string n, int a, string c):name(n),age(a),city(c){
			cout << name << ", age " << age << " from " << city << ", was created.\n";
		}//deletes instances of objects (called when program ends)
		virtual ~person(){ cout << name << " was deleted.\n";}
		//set and get functions 
		//Here member functions are being decalred so values can be passed and returned
		void setName(string aName){
		    name = aName;
		}
		void setAge(int aAge){
		    age = aAge;
		}
		void setCity(string aCity){
		    city = aCity;
		}
		string getName(){
		    return name;
		}
		int getAge(){
		    return age;
		}
		string getCity(){
		    return city;
		}//Instead of calling every get function, make a print function to be called in main
		//Make void print virtual so that it can be overwritten in other derived classes
		//Polymorphism!!!! (each print function has its own implementation)
		virtual void print(){
		    cout << "\n" << "Name: " << name << "\n" << "Age: " << age << "\n" << "City: " << city << endl;
		}
};
//class student derives from person
class student:public person{
    protected://classes that inherit public student will have access to these variables
        string school;
        int year;
        string date;
    public://main has access    
        student(){//blank constructors
            cout << "A student is being constructed" << endl;
        }//constructor with parameters
        student(string aSchool, int aYear, string aDate){
            school = aSchool;
            year = aYear;
            date = aDate;
        }//student deconstructor
        ~student(){
            cout << "deleted.\n";
        }//set and get functions
        void setSchool(string aSchool){
            school = aSchool;
        }
        void setYear(int aYear){
            year = aYear;
        }
        void setDate(string aDate){
            date = aDate;
        }
        string getSchool(){
            return school;
        }
        int getYear(){
            return year;
        }
        string getDate(){
            return date;
        }//called in main to print student variables
        void print(){
            cout << "School: " << school << "\n" << "Class Year: " << year << "\n" << "Graduation date: " << date << endl;
            }
        //creates a linked list for student skills 
        void addSkills(){
            string aSkills;
            cout << "Please add a skill you have learned as a student\n";
            /*since there is a \n in the previous statement I was getting 
            some weird error when trying to input a two worded answer 
            (i.e. debugging code) however cin.ignore managed to fix this*/
            cin.ignore();
            getline(cin, aSkills);
            skills *newpointer = new skills;
            //add the first skill
            if(head == 0){
            head = newpointer;
            head->studentskill = aSkills;
            head->next = 0;
                }else{//add more skills if there are already some added
                    skills *temp;
                    for(temp = head; temp->next != 0; temp = temp->next){}
                    temp->next = newpointer;
                    temp->next->studentskill = aSkills;
                    temp->next->next = 0;
                }
            }
        //print what skills the user has entered     
        void printSkills(){
            skills *temp;
            if(head == 0){
                cout << "No skills added\n";
            }else{
                for(temp = head; temp != 0; temp =  temp->next){
                    cout << "Skills: " << temp->studentskill << endl;
                }
            }
        }
};

class intern:public student{
    protected://protected variables 
        string company;
        int pay;
        string dateofcompletion;
    public://constructors and deconstructors
        intern(){
            cout << "An intern is being constructed\n";
        }
        intern(string aCompany, int aPay, string aDateofcompletion){
            company = aCompany;
            pay = aPay;
            dateofcompletion = aDateofcompletion;
        }
        ~intern(){
            cout << "An intern is being deconstructed\n";
        }//set and get functions
        void setCompany(string aCompany){
            company = aCompany;
        }
        void setPay(int aPay){
            pay = aPay;    
        }
        void setDateofcompletion(string aDateofcompletion){
            dateofcompletion = aDateofcompletion;
        }
        string getCompany(){
            return company;
        }
        int getPay(){
            return pay;
        }
        string getDateofcompletion(){
            return dateofcompletion;
        }//called in main to print intern variables
        void print(){
            cout << "Company: " << company << "\n" << "Weekly pay: " << pay << "\n" << "Date of Completion: " << dateofcompletion << endl;
            cout << endl;
        }//linked list for intern skills
        void addinternskills(){
            string aSkills;
            cout << "Please add a skill you have learned as an intern\n";
            cin.ignore();
            getline (cin, aSkills);
            skills *newpointer1 = new skills;
            if(head1 == 0){
                head1 = newpointer1;
                head1->internskill = aSkills;
                head1->next = 0;
            }else{
                skills *temp;
                for(temp = head1; temp->next != 0; temp = temp->next){}
                    temp->next = newpointer1;
                    temp->next->internskill = aSkills;
                    temp->next->next = 0;
            }
        }//print intern skills
        void printinternskills(){
            skills *temp;
            if(head1 == 0){
                cout << "No skills added\n";
            }else{
                for(temp = head1; temp != 0; temp = temp->next){
                    cout << "Skills: " << temp->internskill << endl;
                }
            }
        }
};

//end
