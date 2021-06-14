#include "LibraryLib.h"


Book::Book(std::string Title, std::string Author, std::string Year, Library* _library)
	: title(Title), author(Author), year(Year), library(_library), available(true) {};

std::string Book::get_name()
{
	return title;
}

std::string Book::get_author()
{
	return author;
}

std::string Book::get_year()
{
	return year;
}

bool Book::get_status()
{
	return available;
}

Library* Book::get_library()
{
	return library;
}

User* Book::get_user()
{
	return user;
}

void Book::set_name(std::string new_name)
{
	title = new_name;
}

void Book::set_author(std::string new_author)
{
	author = new_author;
}

void Book::set_year(std::string new_year)
{
	year = new_year;
}

void Book::set_user(User* _user)
{
	user = _user;
}

bool Book::operator==(Book& other)
{
	return title == other.title && author == other.author
		&& year == other.year && library == other.library && available == other.available;
}

void Book::change_status()
{
	available = !available;
}

std::string Book::info()
{
	return ("Title: " + title + "\nAuthor: " + author + "\nYear of issue: " + year);
}




Encyclopedia::Encyclopedia(std::string Title, std::string Author, std::string Year, Library* _library, std::string Topic)
	:Book(Title, Author, Year, _library), topic(Topic) {};


std::string Encyclopedia::get_topic()
{
	return topic;
}

void Encyclopedia::set_topic(std::string new_topic)
{
	topic = new_topic;
}

std::string Encyclopedia::book_type()
{
	return "Encyclopedia";
}

std::string Encyclopedia::info()
{
	return ("Title: " + title + "\nAuthor: " + author + "\nYear of issue: " + year +
		"\nTopic: " + topic);
}

std::string Encyclopedia::info_to_write()
{
	return (title + "\t" + author + "\t" + year + "\t"
		+ topic + "\t" + (user? user->get_name():"None"));
}



Fiction::Fiction(std::string Title, std::string Author, std::string Year, Library* _library, std::string Genre)
	: Book(Title, Author, Year, _library), genre(Genre) {};

std::string Fiction::get_genre()
{
	return genre;
}

void Fiction::set_genre(std::string new_genre)
{
	genre = new_genre;
}

std::string Fiction::book_type()
{
	return "Fiction";
}

std::string Fiction::info()
{
	return ("Genre: " + genre + "\nTitle: " + title + "\nAuthor: " + author + "\nYear of issue: " + year);
}

std::string Fiction::info_to_write()
{
	return (title + "\t" + author + "\t" + year + "\t"
		+ genre + "\t" + (user ? user->get_name() : "None"));
}



Map::Map(std::string Title, std::string Author, std::string Year, Library* _library, std::string Area, std::string Type)
	: Book(Title, Author, Year, _library), area(Area), type(Type) {};

std::string Map::get_area()
{
	return area;
}

std::string Map::get_type()
{
	return type;
}

void Map::set_area(std::string new_area)
{
	area = new_area;
}

void Map::set_type(std::string new_type)
{
	type = new_type;
}

std::string Map::book_type()
{
	return "Map";
}

std::string Map::info()
{
	return ("Title: " + title + "\nAuthor: " + author + "\nYear of issue: " + year +
		"\nArea: " + area + "\nType: " + type);
}

std::string Map::info_to_write()
{
	return (title + "\t" + author + "\t" + year + "\t" 
		+ area + "\t" + type + "\t" + (user ? user->get_name() : "None"));
}




Library& Library::Get()
{
	static Library instance;
	return instance;
}

std::string Library::get_name()
{
	return name;
}

std::vector<std::unique_ptr<Book>>& Library::get_list_of_books()
{
	return list_of_books;
}

std::string Library::get_phone()
{
	return phone;
}

void Library::set_name(std::string new_name)
{
	name = new_name;
}

void Library::set_phone(std::string new_phone)
{
	phone = new_phone;
}

Library::~Library() {
	list_of_books.clear();
}

bool Library::operator==(Library other)
{
	return
		name == other.name && list_of_books == other.list_of_books
		&& phone == other.phone;
}

void Library::add_book(Book* book)
{
	list_of_books.emplace_back(book);
}



void Library::remove_book(Book* book)
{

	for (int i = 0; i < list_of_books.size(); ++i) {
		if (list_of_books[i].get() == book)
		{
			list_of_books[i].release();
			list_of_books.erase(list_of_books.begin() + i);
		}
	}
}


User::User(std::string Name, std::string Phone) : name(Name), phone(Phone) {};

std::string User::get_name()
{
	return name;
}

std::string User::get_phone()
{
	return phone;
}

void User::set_name(std::string new_name)
{
	name = new_name;
}

void User::set_phone(std::string new_phone)
{
	phone = new_phone;
}

std::vector<std::unique_ptr<Book>>& User::get_issued_books()
{
	return issued_books;
}

void User::issue_book(Book* book)
{
	book->change_status();
	book->set_user(this);
	issued_books.emplace_back(book);
}

void User::return_book(Book* book)
{
	for (int i = 0; i < issued_books.size(); ++i) {
		if (issued_books[i].get() == book)
		{
			issued_books[i].release();
			issued_books.erase(issued_books.begin() + i);
		}
	}
	book->change_status();
	book->set_user(nullptr);
}


std::string info(Library* library)
{
	return ("Name: " + library->name + "\nPhone number: " + library->phone);
}

std::string info(User* user)
{
	return ("Name: " + user->name + "\nPhone number: " + user->phone);
}

std::string info(Encyclopedia* encyclopedia)
{
	return ("Title: " + encyclopedia->title + "\nAuthor: " + encyclopedia->author 
		+ "\nYear of issue: " + encyclopedia->year + "\nTopic: " + encyclopedia->topic);
}

std::string info(Fiction* fiction)
{
	return ("Genre: " + fiction->genre + "\nTitle: " + fiction->title 
		+ "\nAuthor: " + fiction->author + "\nYear of issue: " + fiction->year);
}

std::string info(Map* map)
{
	return ("Title: " + map->title + "\nAuthor: " + map->author 
		+ "\nYear of issue: " + map->year + "\nArea: " + map->area + "\nType: " + map->type);
}


