#include <iostream>
#include <regex>
using namespace std;
//datus ievadiet 76. rindā, CheckData() funkcijas izsaukšanā
bool CheckData(string name, string surname, string birthday, string pk, string email, string phoneNum, string password){
    cout<<"Checking: "<<name<<" " << surname<<" "<< birthday<<" "<<pk<< " "<< email<<" "<<phoneNum<< " "<< password<< " "<<endl;
    regex namePattern(R"([a-zA-Z -]{2,40})");
    regex surnamePattern(R"([a-zA-Z -]{2,40})");
    regex bdayPattern(R"(\d{2}\.\d{2}\.\d{4})");
    regex pkPatternLV(R"((0[1-9]|[12][0-9]|3[01])(0[1-9]|1[0-2])\d{2}-\d{5})");//pirmie 4 cipari nedriikst buut tikai nulles
    regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    regex phoneNumPattern(R"(\d{8})");
    regex passwordPattern(R"((?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])(?=.*[^A-Za-z0-9]).{8,})"); //a password has to contain at least one uppercase letter, a lowercase letter, a digit and a special symbol
    bool ERR = false;
    if(name.empty()) {
        cout<<"Ievadiet vārdu"<<endl;
        ERR = true;
    }
    else if(!(regex_match(name, namePattern))) {
        cout<<"Minimālais vārda simbolu skaits ir 2, maksimālais ir 40, vārdā nevar būt simboli, kas nav burti. Lūdzu mēģiniet vēlreiz!"<<endl;
        ERR = true;
    }
    if(surname.empty()) {
        cout<<"Ievadiet uzvārdu"<<endl;
        ERR = true;
    }
    else if(!(regex_match(surname, surnamePattern))) {
        cout<<"Minimālais uzvārda simbolu skaits ir 2, maksimālais ir 40, uzvārdā nevar būt simboli, kas nav burti. Lūdzu mēģiniet vēlreiz!"<<endl;
        ERR = true;
    }
    if(birthday.empty()) {
        cout<<"Ievadiet dzimšanas dienu"<<endl;
        ERR = true;
    }
    else if(!(regex_match(birthday, bdayPattern))) {
        cout<<"Ievadiet datumu formātā dd.mm.yyyy"<<endl;
        ERR = true;
    }
    if(pk.empty()) {
        cout<<"Ievadiet personas kodu"<<endl;
        ERR = true;
    }
    else if(!(regex_match(pk, pkPatternLV))) {
        cout<<"Tas nav derīgs personas kods. Lūdzu mēģiniet vēlreiz!"<<endl;
        ERR = true;
    }
    if(email.empty()) {
        cout<<"Ievadiet e-pastu"<<endl;
        ERR = true;
    }
    else if(!(regex_match(email, emailPattern)) || email.length() > 255) {
        cout<<"Ievadiet e-pastu pareizā formātā un ne garāko par 255 simboliem!"<<endl;
        ERR = true;
    }
    if(phoneNum.empty()) {
        cout<<"Ievadiet telefona numuru"<<endl;
        ERR = true;
    }
    else if(!(regex_match(phoneNum, phoneNumPattern))) {
        cout<<"Simbolu skaits ir jābūt 8. Lūdzu mēģiniet vēlreiz!"<<endl;
        ERR = true;
    }
    if(password.empty()) {
        cout<<"Ievadiet paroli"<<endl;
        ERR = true;
    }
    else if(!(regex_match(password, passwordPattern))) {
        cout<<"Minimālais simbolu skaits ir 8, nedroša parole. Lūdzu mēģiniet vēlreiz!"<<endl;
        ERR = true;
    }
    if(ERR) return false;
    else return true;
}

int main(){
    if(CheckData("Vards", "Uzvards", "26.08.1999", "260205-20960", "email@gmail.com", "27337874", "Greatpassword1!"))
        cout<<"OK"<<endl;
}