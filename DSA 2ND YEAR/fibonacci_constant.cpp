#include <iostream>

using namespace std;
class Student{
    private:
    int age;
    string first_name;
    string last_name;
    int standard;
    public:
    void set_age(int age1){
        age=age1;
    }
    void set_standard(int standard1){
        standard=standard1;
    }
    void set_first_name(string first_name1){
        first_name=first_name1;
    }
    void set_last_name(string last_name1){
        last_name=last_name1;
    }
      int  get_age(){
        return age;
    }
   int get_standard(){
       return standard;
    }
    string get_first_name(){
       return  first_name;
    }
    string get_last_name){
        return last_name;
    }
    char* to_string()
        {
        return strcat(""+age+","+first_name+",");
    }
    
};