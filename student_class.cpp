#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    private:
        int age;
        int standard;
        string first_name;
        string last_name;
        
    public:
        Student(){
            age = 0;
            standard = 0;
            first_name.clear();
            last_name.clear();
        }
        void set_age(int new_age){
            age = new_age;
        }
        void set_standard(int new_standard){
            standard = new_standard;
        }
        void set_first_name(string new_first_name){
            first_name = new_first_name;
        }
        void set_last_name(string new_last_name){
            last_name = new_last_name;
        }
        int get_age(){
            return age;
        }
        string get_first_name(){
            return first_name;
        }
        string get_last_name(){
            return last_name;
        } 
        
        int get_standard(){
            return standard;
        }
        string to_string(){
            stringstream ss;
            ss << age <<','<<first_name<<','<<last_name<<','<<standard;
            return ss.str();
        }
        
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}