#include <iostream>
using std::string;



class AbstractEmployee {  //this is abstraction 1.0

	virtual void AskForPromotion()=0; 
    

};





class Employee:AbstractEmployee{

private: //public// protected// this is private by default
	
	string Company;
	int Age;

protected:

	string Name;
	

public:
	//THis is Encapsulation means only the public method in the class can access the private the only way to access those properties at the top is by these public methods
	
	void setName(string name) { //setter
		Name = name;
	
	}
	string getName() { //getter
		return Name;
	}
	void setCompany(string company) { //setter
		Company = company;

	}
	string getCompany() { //getter
		return Name;
	}
	void setAge(int age) { //setter
		Age = age;

	}
	int getAge() { //getter
		return Age;
	}


	void IntroduceYourself() {   //method

		std::cout << "Name -" << Name << std::endl;
		std::cout << "Company -" << Company << std::endl;
		std::cout << "Age -" << Age << std::endl;

	}


	//create a constructor 
	Employee(string name, string company, int age ) {
		Name = name;
		Company = company;
		Age = age;
	}

	void AskForPromotion() { //this is Abstraction 2.0
		if (Age > 30)
			std::cout << Name << " got promoted! " << std::endl;
		else
			std::cout << Name << ", sorry no promotion for you " << std::endl;
	}

	virtual void Work() { //virtual function when this is used it checks the same name function on baby class and executes it if theres any and if not it executes the parent

		std::cout << Name << "  is checking email, task backlog, performing tasks..." << std::endl;

	}

};

class Developer:public Employee {    //this is inheritance

public: 
	string FavProgrammingLanguage;

	Developer(string name, string company, int age, string favProgrammingLanguage) //this should be called not the Employee constructor
	:Employee(name, company, age) //this already inherits from Employee and can only handle the three data.
	{
		FavProgrammingLanguage = favProgrammingLanguage; // because this is specific only for this developer class, create the variable to complete the Developer constructor

	}

	void FixBug() {
		std::cout << Name << " fixed bug using "<< FavProgrammingLanguage << std::endl;
	}

	void Work() {

		std::cout << Name << "Developer is busy coding" << std::endl;

	}
};



class Teacher:public Employee { //inherits Employee this is exampale of inheritance also just like Developer:EMployee
public:
	string Subject;
	void PrepareLesson() {

		std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
	
	}
	Teacher(string name, string company, int age, string subject) :Employee(name, company, age)
	{
		Subject = subject;

	}


	void Work() {

		std::cout << Name << "  Teachder is teaching students" << std::endl;

	}




};



int main() 
{


	//Employee employee1 = Employee("Germain", "MyCompany", 32); //use constructor
	//employee1.IntroduceYourself(); //use the object and call the method

	//employee1.setAge(32);
	//std::cout << employee1.getName() << " is " << employee1.getAge() << " years old " << std::endl;

	//employee1.AskForPromotion(); //this is abstraction 3.0

	Developer d = Developer("Germain Wisdom", "MY Channel", 31, "C++"); //inheritance
	//d.FixBug();

	//d.AskForPromotion(); //inheritance//
	
	Teacher t = Teacher("Kelly", "GWSM", 35, "History"); // inheritance

	//t.PrepareLesson();    // inheritance

	//d.Work();

	Employee* e1 = &d;  //these are pointers
	Employee* e2 = &t;


	e1->Work(); //.symbol replaces by arrow if using a pointer
	e2->Work();

}   