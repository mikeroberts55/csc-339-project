//includes.
#include <cstring>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <iomanip>
#include <array>
#include <algorithm>

//usings.
using namespace std;
using std::setw;

//student creator.
class Student{

//protected variables.
protected:
    char name[21];
    char ssn[10];
    float gpa;
    int credits;

//constructor.
public:

    Student(){};
    virtual void print(){
    };
    virtual float tuition() = 0;
};

//undergrad creator.
class Undergrad: public Student{

//private variables.
private:
    float undergrad_rate = 380.0;
    char year[10];

//constructors.
public :
    Undergrad(){};
    Undergrad(const char* uname, const char* ussn, float ugpa,int ucredits, const char* uyear){
        strcpy(name,uname);
        strcpy(ssn,ussn);
        gpa = ugpa;
        credits = ucredits;
        strcpy(year,uyear);
    };

    //overloads the operator to compare undergrad gpa's.
    bool operator <(const Undergrad& second) const {

        return gpa > second.gpa;
    }

    //override the print function.
    void print()
    {
        cout<<"Student name: "<< name << endl;
        cout<<"Student SSN: "<< ssn << endl;
        cout<<"Student Classification: "<< get_year() << endl;
        cout<<"Credits: " << credits << endl;
        cout<<"Tuition: $" << tuition() << endl;
        cout<<"GPA: " << gpa << endl;
    };

    //prints in table form.
    void table(){

        cout<<setw(20)<<left<< name <<left<<setw(10)<< ssn <<left<<setw(10)<< get_year() <<left<<setw(10)<< credits<<"          $"<<
        setw(10)<< tuition() <<"      "<<setw(10)<< gpa <<endl;
        cout<<endl;
    };

    float tuition()
    {
        return 200.0 * undergrad_rate;
    }
    char* get_year(){
        return year;
    };
    float get_rate(){
        return undergrad_rate;
    };
    void set_year(char* a){
         strcpy(year,a);
    };
};

//grad student creator.
class Grad: public Student{

//private variables.
private:
    float grad_rate = 500.0;
    char* thesis;

//constructors.
public:
    Grad(){};
    Grad(const char* gname, const char* gssn, float ggpa,int gcredits, const char* gthesis){
        strcpy(name,gname);
        strcpy(ssn,gssn);
        gpa = ggpa;
        credits = gcredits;
        thesis = (char*)gthesis;
    };

    //overrides the print function.
     void print()
    {
        cout<<"Student name: "<< name << endl;
        cout<<"Student SSN: "<< ssn << endl;
        cout<<"Student Classification: Graduate Student" << endl;
        cout<<"Credits: " << credits << endl;
        cout<<"Tuition: $" << tuition() << endl;
        cout<<"GPA: " << gpa << endl;
        cout<<"Thesis: " << get_thesis() << endl;
    };
    float tuition()
    {
        return 200.0 * grad_rate;
    }
    char* get_thesis(){
        return thesis;
    };
    float get_rate(){
        return grad_rate;
    };
    void set_thesis(char* a){
        thesis = (char*) a;
    };
};

//grad assistant creator.
class GradAsst: public Grad{

//private variables.
private:
    float hourPay = 20.0;
    char* superviser;
    char* task;

//public constructors.
public:
    GradAsst(){};
    GradAsst(const char* aname, const char* assn, float agpa, int acredits, const char* athesis, const char* asupervisor, const char* atask){
        strcpy(name,aname);
        strcpy(ssn,assn);
        gpa = agpa;
        credits = acredits;
        set_thesis((char*)athesis);
        superviser = (char*)asupervisor;
        task = (char*)atask;
    };

    //method to override print function.
    void print(){
        cout<<"Student name: "<< name << endl;
        cout<<"Student SSN: "<< ssn << endl;
        cout<<"Student Classification: Graduate Assistant" << endl;
        cout<<"Credits: " << credits << endl;
        cout<<"Tuition: $" << tuition()<< endl;
        cout<<"GPA: " << gpa << endl;
        cout<<"Thesis: " << get_thesis()<< endl;
        cout<<"Hourly pay: $" << get_hourPay()<< endl;
        cout<<"Supervisor: " << get_supervisor() << endl;
        cout<<"Task: " << get_task() << endl;
    };
    char* get_supervisor(){
        return superviser;
    };
    float get_hourPay(){
        return hourPay;
    };
    void set_supervisor(char* a){
        superviser = a;
    };
    void set_hourPay(float a){
        hourPay = a;
    };
    char* get_task(){
        return task;
    };
    void set_task(char* a){
        task = a;
    };
};

//function to convert for printing.
bool Convert(std::string & a, std::string & b, std::string & c, std::string & d, std::string & e){

    //length variables.
    int n = a.length();
    int m = b.length();
    int p = e.length();

    //create variables.
    char name[n+1];
    char ssn[m+1];
    float gpa;
    int credits;
    char year[p+1];
    bool x = false;

    if(typeid((char*)name[n+1]).name() == typeid((char*)a.c_str()).name() &&
       typeid((char*)ssn[m+1]).name() == typeid((char*)b.c_str()).name() &&
       typeid(gpa).name() == typeid(::stof(d.c_str())).name() &&
       typeid(credits).name() == typeid(::stoi(c.c_str())).name() &&
       typeid((char*)year[p+1]).name() == typeid((char*)e.c_str()).name()){

            //create instance.
            a.pop_back();
            a.erase(0,1);
            strcpy(name,a.c_str());
            b.erase(0,2);
            b.pop_back();
            strcpy(ssn,b.c_str());
            gpa = ::stof(d.c_str());
            credits = ::stoi(c.c_str());
            e.pop_back();
            e.erase(0,2);
            strcpy(year,e.c_str());
            Undergrad s4(name,ssn,gpa,credits,year);
            s4.print();
            cout<<endl;
            x = true;

       }
    return x;
};

Undergrad Convert2(std::string & a, string  b, std::string & c, std::string & d, std::string & e){

     //lengths variables.
    int n = a.length();
    int m = b.length();
    int p = e.length();

    //variable declaration.
    char name[n+1];
    char ssn[m+1];
    float gpa;
    int credits;
    char year[p+1];

    //create instance.
    strcpy(name,a.c_str());
    b.erase(0,2);
    b.pop_back();
    strcpy(ssn,b.data());
    gpa = ::stof(d.c_str());
    credits = ::stoi(c.c_str());
    strcpy(year,e.c_str());
    Undergrad s(name,ssn,gpa,credits,year);
    return s;
}
