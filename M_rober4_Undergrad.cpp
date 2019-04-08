//includes.
#include "M_rober4_Undergrad.h"

//main function.
int main()
{
    //creates a divider line.
    cout << string(100, '-') << endl;

    cout<<"Beginning instances: "<<endl;

    //creates a divider line.
    cout << string(100, '-') << endl;

    //create instances as indicated from directions.
    Undergrad s1("Mary","000111222", 4.0, 12, "Junior");
    s1.print();
    cout<<endl;
    Grad s2("David", "111222333", 3.7, 9, "How to learn data structures using C++/STL?");
    s2.print();
    cout<<endl;
    GradAsst s3("Jason", "222333444", 3.9, 9, "Design of efficient algorithms", "Dr. Fu",
                "Grading 330 projects and implementing a data mining algorithm");
    s3.print();
    cout<<endl;

    //creates a divider line.
    cout << string(100, '-') << endl;

    //import text file.
    string line;
    ifstream file("nt.txt");

    //first list creation to print the table.
    std::list<Undergrad> sList;
    std::list<Undergrad>::iterator iter;

    //second list creation for sorting
    std::list<Undergrad> sList2;
    std::list<Undergrad>::iterator iter2;

    cout<<"Printing undergrad students from the file: "<<endl;

    //creates a divider line.
    cout << string(100, '-') << endl;

    //loop to go through the file line by line.
    while (getline(file, line))
    {
        //variables and streams to be used.
        string word;
        std::stringstream stream(line);
        int pos = 0;
        string arr[5];

        //loop to split by commas.
        while( getline(stream, word, ',')|| pos < 5){

            //place string in array.
            arr[pos] = word;

            //when the 4th element comes in then send it to the converter and see if the data entered is a undergrad.
            if(pos == 4){

                //if the instance can be made then push it to the list.
                if(Convert(arr[0],arr[1],arr[3],arr[4],arr[2]) == true){
                    sList2.push_back(Convert2(arr[0],arr[1],arr[3],arr[4],arr[2]));
                    ++pos;
                    break;
                }

                //if it can not make one then print the error and move on.
                if(Convert(arr[0],arr[1],arr[3],arr[4],arr[2]) == false){
                    cout<<"The input: "<<"("<<arr[0]<<", "<<arr[1]<<", "<<arr[2]<<", "<<arr[3]<<", "<<
                            arr[4]<<")"<<" is not able to create an instance of an Undergrad."<<endl;

                    ++pos;
                    break;
                }
            };
            ++pos;
        }
    };

    //close the file.
    file.close();

    //creates a divider line.
    cout << string(100, '-') << endl;

    cout<<"Output table as read in from the file: "<<endl;

    //creates a divider line.
    cout << string(100, '-') << endl;

    //loop through the vector.
    for (auto v : sList2){

        //print header for the table output.
        cout<<setw(20)<<left<<"Name"<<left<<setw(10)<<"SSN"<<left<<setw(10)<<"Year"<<left<<setw(20)<<
            "Credits"<<setw(10)<<"Tuition"<<setw(10)<<right<<"  GPA"<<endl;

        //print table.
        v.table();
    };

    cout<<endl;

    //take the last undergrad of the file and put it at the front of the vector.
    Undergrad del = sList2.back();
    sList2.pop_back();
    sList2.push_front(del);

    //creates a divider line.
    cout << string(100, '-') << endl;

    cout<<"Manipulated list output table: "<<endl;

    //creates a divider line.
    cout << string(100, '-') << endl;

    //loop to go through the vector.
    for (auto v : sList2){

        //print header for the table output.
        cout<<setw(20)<<left<<"Name"<<left<<setw(10)<<"SSN"<<left<<setw(10)<<"Year"<<left<<setw(20)<<
            "Credits"<<setw(10)<<"Tuition"<<setw(10)<<right<<"  GPA"<<endl;

         //print table.
         v.table();
    };

    cout<<endl;

    //sort the vector by overloading the "operator <".
    sList2.sort();

    cout<< endl;

     //creates a divider line.
    cout << string(100, '-') << endl;

    cout<<"New Table with GPA'S sorted:"<<endl;

    //creates a divider line.
    cout << string(100, '-') << endl;

    //loop through the vector.
    for(auto v: sList2){

        //header for table2.
        cout<<setw(20)<<left<<"Name"<<left<<setw(10)<<"SSN"<<left<<setw(10)<<"Year"<<
        left<<setw(20)<<"Credits"<<setw(10)<<"Tuition"<<setw(10)<<right<<"  GPA"<<endl;

        //print table.
        v.table();
    }

    return 0;
}

