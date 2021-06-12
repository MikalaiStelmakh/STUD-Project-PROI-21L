#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<class T>
class Stack
{
private:
	std::vector<std::unique_ptr<T>> content;
public:
	Stack() {};
	void push(T* t)
	{
		content.emplace_back(t);
	}
	void pop()
	{
		content[content.size() - 1].release();
		content.erase(content.begin() + content.size() - 1);
	}
	std::vector<std::unique_ptr<T>>& read()
	{
		std::vector<std::unique_ptr<T>> static copy;
		for (auto it = content.begin(); it != content.end(); ++it)
		{
			copy.emplace_back((*it).get());
		}
		for (int i = 0; i < content.size(); ++i)
		{
			content[i].release();
		}
		content.clear();
		return copy;
	}
};


class Library;
class User;
class Book
{
protected:
	std::string title;
	std::string author;
	std::string year;
	Library* library;
	bool available;
	User* user = nullptr;
public:
	Book();
	Book(std::string Title, std::string Author, std::string Year, Library* _library);

	std::string get_name();
	std::string get_author();
	std::string get_year();
	Library* get_library();
	User* get_user();
	bool get_status();

	void set_name(std::string new_name);
	void set_author(std::string new_author);
	void set_year(std::string new_year);
	void set_user(User* _user);

	virtual std::string info() = 0;
	bool operator==(Book& other);
	void change_status();
};

class Encyclopedia : public Book
{
private:
	std::string topic;
public:
	Encyclopedia() {};
	Encyclopedia(std::string Title, std::string Author, std::string Year, Library* _library, std::string Topic);
	std::string get_topic();
	void set_topic(std::string new_topic);
	friend std::string info(Encyclopedia* encyclopedia);

	std::string info();
};

class Fiction : public Book
{
private:
	std::string genre;
public:
	Fiction() {};
	Fiction(std::string Title, std::string Author, std::string Year, Library* _library, std::string Genre);

	std::string get_genre();
	void set_genre(std::string new_genre);

	friend std::string info(Fiction* fiction);
	std::string info();
};

class Map : public Book
{
private:
	std::string area;
	std::string type;
public:
	Map(std::string Title, std::string Author, std::string Year, Library* _library, std::string Area, std::string Type);

	std::string get_area();
	std::string get_type();

	void set_area(std::string new_area);
	void set_type(std::string new_type);

	friend std::string info(Map* map);
	std::string info();
};

class Library
{
private:
	std::string name;
	std::vector<std::unique_ptr<Encyclopedia>> list_of_encyclopedias;
	std::vector<std::unique_ptr<Fiction>> list_of_fictions;
	std::vector<std::unique_ptr<Map>> list_of_maps;
	std::string phone;
	Library() {};
public:
	Library(const Library&) = delete;
	static Library& Get();
	friend std::string info(Library* library);
	~Library();

	std::string get_name();
	std::vector<std::unique_ptr<Encyclopedia>>& get_list_of_encyclopedias();
	std::vector<std::unique_ptr<Fiction>>& get_list_of_fictions();
	std::vector<std::unique_ptr<Map>>& get_list_of_maps();
	std::string get_phone();

	void set_name(std::string new_name);
	void set_phone(std::string new_phone);

	void add_book(Encyclopedia* encyclopedia);
	void add_book(Fiction* fiction);
	void add_book(Map* map);

	bool operator==(Library other);
	void remove_book(Encyclopedia* encyclopedia);
	void remove_book(Fiction* fiction);
	void remove_book(Map* map);
};

class User
{
private:
	std::string name;
	std::string phone;
	std::vector<std::unique_ptr<Encyclopedia>> issued_encyclopedias;
	std::vector<std::unique_ptr<Fiction>> issued_fictions;
	std::vector<std::unique_ptr<Map>> issued_maps;
public:
	User() {};
	User(std::string Name, std::string Phone);
	friend std::string info(User* user);
	~User() {
		issued_encyclopedias.clear();
		issued_fictions.clear();
		issued_maps.clear();
	};

	std::string get_name();
	std::string get_phone();

	std::vector<std::unique_ptr<Encyclopedia>>& get_issued_encyclopedias();
	std::vector<std::unique_ptr<Fiction>>& get_issued_fictions();
	std::vector<std::unique_ptr<Map>>& get_issued_maps();
	
	void set_name(std::string new_name);
	void set_phone(std::string new_phone);

	void issue_book(Encyclopedia* encyclopedia);
	void issue_book(Fiction* fiction);
	void issue_book(Map* map);
	
	void return_book(Encyclopedia* encyclopedia);
	void return_book(Fiction* fiction);
	void return_book(Map* map);

};

std::string info(Library* library);
std::string info(User* user);
std::string info(Encyclopedia* encyclopedia);
std::string info(Fiction* fiction);
std::string info(Map* map);