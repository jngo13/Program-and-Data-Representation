// Justin Ngo
// jmn4fms
// 4/21/20
// topological.cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
 An object that contains information on a course and connects to other courses
*/
/**
 \struct course
 */

struct course{
  /**
   The name of the course
   */
    string name;
  /**
   Pointer pointing to the next course
   */
    course *next;
};

/**
 Reads in list of courses and performs a topological sort, printing at the very end.
 */
/**
 Input takes in two vertex names, separated by a single space; the edge is directed from the first to the second listed vertex name on a given line.
 */

int main (int argc, char **argv) {
    // check number of parameters
    if(argc != 2) {
        cout << "Must supply the input file name as the only parameter." << endl;
        exit(1);
    }
    
    // opens and checks file
    ifstream file(argv[1], ifstream::binary);
    if (!file.is_open()) {
        //return the error message if unable to open and exit.
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    
    
    // vector of courses
    vector <course*> courses;
    // string read in
    string s1;
    
    // Loops through file and creating courses
    // Performs topological sort if possible
    while(true){
        file >> s1;
        if(s1 == "0") {
            break;
        }

        int n = 0;
        course* c = new course();
        while(n<courses.size()){
            if(courses.at(n)->name == s1){
                stack <course*> num;
                c = courses.at(n)->next;
                
                // first while
                while(c){
                    num.push(c);
                    c = c->next;
                }
       
                file >> s1;
                bool flag1 = false;
       
                // second while
                int j = 0;
                while(j < courses.size()){
                    if(courses.at(j)->name == s1){
                        flag1 = true;
                    }
                    j++;
                }
                
                if(flag1 == false){
                    course* cx = new course();
                    cx->name = s1;
                    courses.push_back(cx);
                }

                course* d = new course();
                d->name = s1;
                c = d;
                
                for(int k = num.size(); k > 0; k--){
                    num.top()->next = c;
                    c = num.top();
                    num.pop();
                }

                courses.at(n)->next = c;
                break;
            }
            n++;
        }
        
        string empty = "";
        if(c->name == empty){
            c->name = s1;
            file >> s1;
            
            course* d = new course();
            if(d->name == empty){
                d->name = s1;
                c->next = d;
                courses.push_back(c);
            }
      
            bool flag2 = false;
            int i = 0;
            while(i < courses.size()){
                if(courses.at(i)->name == s1){
                    flag2 = true;
                }
                i++;
            }
          
            if(flag2 == false){
                course* e = new course();
                e->name = s1;
                courses.push_back(e);
            }
        }
    }
    
    // close the file before exiting program
    file.close();
    
    int i = 0;
    course* cn;
    while(i<courses.size()){
        cn = courses.at(i)->next;
        while(cn){
            cn = cn->next;
        }
        i++;
    }
    
    int matrix[courses.size()][courses.size()];
    for(int j = 0; j < courses.size(); j++){
        for(int k = 0; k < courses.size(); k++){
            matrix[j][k]=0;
        }
    }
    
    i = 0;
    while(i < courses.size()){
        stack<course*> s;
        course* cy = courses.at(i)->next;
        while(cy){
            if(cy!=NULL){
            s.push(cy);
            cy = s.top()->next;
            }
        }
        
        while(s.size() != 0){
            
            int k = 0;
            while (k < courses.size()){
                if(i==k){
                    matrix[i][k] = 0;
                }
                if(s.top()->name == courses.at(k)->name){
                    matrix[i][k] = 1;
                }
                k++;
            }
            s.pop();
        }
        i++;
    }
        
    // iterating through matrix and printing courses
    int row = 0;
    int cnum = 0;
    
    for(int col = 0; col < courses.size(); col++){
        for(int row = 0; row < courses.size(); row++){
            if(matrix[row][col]==1){
                col++;
                row=0;
            }
            else{
                row++;
            }
            row--;
        }

        cout << courses.at(col)->name << " ";
        
        int i = 0;
        while(i < courses.size()){
            matrix[col][i] = 0;
            matrix[i][col] = 1;
            i++;
        }
        cnum++;
        if(cnum < courses.size()){
            col = 0;
        }
        else{
            break;
        }
        row = 0;
        col--;
    }
    cout << endl;
    return 0;
}
