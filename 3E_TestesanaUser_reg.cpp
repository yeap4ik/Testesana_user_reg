//Testesana 3.uzdevums
//Funkcija Lietotāja registrēšana
//Datu ievade notiek main() sadaļa, kur notiek funckiju checkData izsaukšana
#include <iostream>
#include <ctime>
#include <regex>
using namespace std;

bool CheckData(string name, string surname, string birthday, string pk, string email, string phoneNum, string password){
    cout<<"Checking: "<<name<<" " << surname<<" "<< birthday<<" "<<pk<< " "<< email<<" "<<phoneNum<< " "<< password<< " "<<endl;
    regex namePattern(R"([a-zA-Z]{2,40})");
    regex surnamePattern(R"([a-zA-Z]{2,40})");
    regex bdayPattern(R"(\d{2}\.\d{2}\.\d{4})");
    regex pkPatternLV(R"((0[1-9]|[12][0-9]|3[01])(0[1-9]|1[0-2])\d{2}-\d{5})");
    regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    regex phoneNumPattern(R"(\d{8})");
    regex passwordPattern(R"((?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])(?=.*[^A-Za-z0-9]).{8,})");
    time_t t = time(0); //Sistemas datums priekš datuma pārbaudes
    tm* now = localtime(&t);
    bool ERR = false;
    if(name.empty()) {
        cout<<"Ievadiet vārdu"<<endl;
        ERR = true;
    }
    else if(!(regex_match(name, namePattern))) {
        cout<<"Minimālais vārda simbolu skaits ir 2, maksimālais ir 40, vārdā nevar būt simboli, kas nav burti. Lūdzu mēģiniet vēlreiz!"<<endl;
        ERR = true;
    }

    else if (name[0] != toupper(name[0])) {
        cout<<"Vārda pirmajam burtam ir jābūt lielajam. Lūdzu mēģiniet vēlreiz!"<<endl;
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
    else if (surname[0] != toupper(surname[0])) {
        cout<<"Uzvārda pirmajam burtam ir jābūt lielajam. Lūdzu mēģiniet vēlreiz!"<<endl;
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

    if (stoi(birthday.substr(6, 4)) > now->tm_year + 1900 || (stoi(birthday.substr(6, 4)) == now->tm_year + 1900 && stoi(birthday.substr(3, 2)) > now->tm_mon + 1) || (stoi(birthday.substr(6, 4)) == now->tm_year + 1900 && stoi(birthday.substr(3, 2)) == now->tm_mon + 1 && stoi(birthday.substr(0, 2)) > now->tm_mday)) { //Vai dzimšanas datums nav nākotnē
        cout << "Dzimšanas datums nevar būt nākotnē" << endl;
        ERR = true;
    }

    if (stoi(birthday.substr(3, 2)) > 12) // Menesa neeksistences parbaude
    {
        cout << "Mēnesis nevar būt lielāks par 12" << endl;
        ERR = true;
    }

    else if (stoi(birthday.substr(0, 2)) > 31) //Dienas neeksistences parbaude
    {
        cout << "Diena nevar būt lielāka par 31" << endl;
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
    string bday = birthday.substr(0,2) + birthday.substr(3,2) + birthday.substr(8,2); //Personas kodam pirmiem 6 cipariem ir jabut tadiem pašiem ka dzimšanas dienai formātā ddmmyy
    if(pk.substr(0,6) != bday) {
        cout<<"Personas koda pirmie 6 cipari neatbilst dzimšanas datumam"<<endl;
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
        cout<<"Ciparu skaitam ir jābūt 8. Lūdzu mēģiniet vēlreiz!"<<endl;
        ERR = true;
    }
    else if(phoneNum[0] != '2' && phoneNum[0] != '6' && phoneNum[0] != '8') {
        cout<<"Pirmajam ciparam ir jābūt 2, 6 vai 8. Lūdzu mēģiniet vēlreiz!"<<endl;
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
    if(CheckData("vans", "asdkl", "35.14.2025", "110322-20960", "asdads@gasdad.com", "12345678", "Greatpassword1!"))
        cout<<"OK"<<endl;
}
