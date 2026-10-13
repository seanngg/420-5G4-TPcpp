#include <sstream>

#include "book.h"

using namespace std;

//constructeur par defaut pour un livre vide qui est disponible
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId(""){}

//constructeur avec parametre : un nouveau livre est disponible
Book::Book(const string& title, const string& author, const string& isbn) {
    this -> title = title;
    this -> author = author;
    this -> isbn = isbn;
    this -> isAvailable = true;
    this -> borrowerId = "";
}

// GET
string Book::getTitle() const {return title;}
string Book::getAuthor() const {return author;}
string Book::getISBN() const {return isbn;}
bool Book::getAvailability() const {return isAvailable;}
string Book::getBorrowerId() const {return borrowerId;}

// set
void Book::setTitle(const string& title) {this->title = title;}
void Book::setAuthor(const string& author) {this->author = author;}
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(bool available) {isAvailable = available;}
void Book::setBorrowerId(const string& id) {borrowerId = id;}

// Emprunter un livre
void Book::checkOut(const string& borrowerId){
    isAvailable = false;
    this->borrowerId = borrowerId;
}


//Retour d'un livre
void Book::returnBook(){
    isAvailable = true;
    borrowerId.clear();
}

// Affichage lisible
string Book::toString() const {
    string result = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn +
                    "\nStatut: " + (isAvailable ? "Disponible" : "Emprunté");
    if (!isAvailable && !borrowerId.empty()) {
        result += " (par " + borrowerId + ")";
    }
    return result;
}

string Book::toFileFormat() const{
    return "";
}

void Book::fromFileFormat(const string& line){
    string lime = line;
}