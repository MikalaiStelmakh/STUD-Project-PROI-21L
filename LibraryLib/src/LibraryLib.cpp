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

std::string Encyclopedia::info()
{
	return ("Title: " + title + "\nAuthor: " + author + "\nYear of issue: " + year +
		"\nTopic: " + topic);
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

std::string Fiction::info()
{
	return ("Genre: " + genre + "\nTitle: " + title + "\nAuthor: " + author + "\nYear of issue: " + year);
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

std::string Map::info()
{
	return ("Title: " + title + "\nAuthor: " + author + "\nYear of issue: " + year +
		"\Area: " + area + "\nType: " + type);
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

std::vector<std::unique_ptr<Encyclopedia>>& Library::get_list_of_encyclopedias()
{
	return list_of_encyclopedias;
}

std::vector<std::unique_ptr<Fiction>>& Library::get_list_of_fictions()
{
	return list_of_fictions;
}

std::vector<std::unique_ptr<Map>>& Library::get_list_of_maps()
{
	return list_of_maps;
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
	list_of_encyclopedias.clear();
	list_of_fictions.clear();
	list_of_maps.clear();
}

bool Library::operator==(Library other)
{
	return
		name == other.name && list_of_encyclopedias == other.list_of_encyclopedias
		&& list_of_fictions == other.list_of_fictions && list_of_maps == other.list_of_maps
		&& phone == other.phone;
}

void Library::add_book(Encyclopedia* encyclopedia)
{
	list_of_encyclopedias.emplace_back(encyclopedia);
}

void Library::add_book(Fiction* fiction)
{
	list_of_fictions.emplace_back(fiction);
}

void Library::add_book(Map* map)
{
	list_of_maps.emplace_back(map);
}

void Library::remove_book(Encyclopedia* encyclopedia)
{

	for (int i = 0; i < list_of_encyclopedias.size(); ++i) {
		if (list_of_encyclopedias[i].get() == encyclopedia)
		{
			list_of_encyclopedias[i].release();
			list_of_encyclopedias.erase(list_of_encyclopedias.begin() + i);
		}
	}
}

void Library::remove_book(Fiction* fiction)
{
	for (int i = 0; i < list_of_fictions.size(); ++i) {
		if (list_of_fictions[i].get() == fiction)
		{
			list_of_fictions[i].release();
			list_of_fictions.erase(list_of_fictions.begin() + i);
		}
	}
}

void Library::remove_book(Map* map)
{
	for (int i = 0; i < list_of_maps.size(); ++i) {
		if (list_of_maps[i].get() == map)
		{
			list_of_maps[i].release();
			list_of_maps.erase(list_of_maps.begin() + i);
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

std::vector<std::unique_ptr<Encyclopedia>>& User::get_issued_encyclopedias()
{
	return issued_encyclopedias;
}

std::vector<std::unique_ptr<Fiction>>& User::get_issued_fictions()
{
	return issued_fictions;
}

std::vector<std::unique_ptr<Map>>& User::get_issued_maps()
{
	return issued_maps;
}

void User::issue_book(Encyclopedia* encyclopedia)
{
	encyclopedia->change_status();
	encyclopedia->set_user(this);
	issued_encyclopedias.emplace_back(encyclopedia);
}

void User::issue_book(Fiction* fiction)
{
	fiction->change_status();
	fiction->set_user(this);
	issued_fictions.emplace_back(fiction);
}

void User::issue_book(Map* map)
{
	map->change_status();
	map->set_user(this);
	issued_maps.emplace_back(map);
}

void User::return_book(Encyclopedia* encyclopedia)
{
	for (int i = 0; i < issued_encyclopedias.size(); ++i) {
		if (issued_encyclopedias[i].get() == encyclopedia)
		{
			issued_encyclopedias[i].release();
			issued_encyclopedias.erase(issued_encyclopedias.begin() + i);
		}
	}
	encyclopedia->change_status();
	encyclopedia->set_user(nullptr);
}

void User::return_book(Fiction* fiction)
{
	for (int i = 0; i < issued_fictions.size(); ++i) {
		if (issued_fictions[i].get() == fiction)
		{
			issued_fictions[i].release();
			issued_fictions.erase(issued_fictions.begin() + i);
		}
	}
	fiction->change_status();
	fiction->set_user(nullptr);
}

void User::return_book(Map* map)
{
	for (int i = 0; i < issued_maps.size(); ++i) {
		if (issued_maps[i].get() == map)
		{
			issued_maps[i].release();
			issued_maps.erase(issued_maps.begin() + i);
		}
	}
	map->change_status();
	map->set_user(nullptr);
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


