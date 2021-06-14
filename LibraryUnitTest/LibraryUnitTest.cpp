#include "pch.h"
#include "CppUnitTest.h"
#include "../LibraryLib/src/LibraryLib.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LibraryUnitTest
{
	TEST_CLASS(LibraryUnitTest)
	{
	public:
		TEST_METHOD(library_set_name)
		{
			auto& library = Library::Get();
			std::string name = "My library";
			library.set_name(name);
			Assert::AreEqual(name, library.get_name());
		}
		TEST_METHOD(library_set_phone)
		{
			auto& library = Library::Get();
			std::string phone = "143725329";
			library.set_phone(phone);
			Assert::AreEqual(phone, library.get_phone());
		}
		TEST_METHOD(encyclopedia_create)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
		}
		TEST_METHOD(encyclopedia_get_name)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
			Assert::AreEqual(title, encyclopedia.get_name());
		}
		TEST_METHOD(encyclopedia_get_author)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
			Assert::AreEqual(author, encyclopedia.get_author());
		}
		TEST_METHOD(encyclopedia_get_year)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
			Assert::AreEqual(year, encyclopedia.get_year());
		}
		TEST_METHOD(encyclopedia_get_library)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
			Assert::IsTrue(&library == encyclopedia.get_library());
		}
		TEST_METHOD(encyclopedia_get_status)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
			Assert::IsTrue(encyclopedia.get_status());
		}
		TEST_METHOD(encyclopedia_set_name)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
			std::string new_title = "Human";
			encyclopedia.set_name(new_title);
			Assert::AreEqual(new_title, encyclopedia.get_name());
		}
		TEST_METHOD(encyclopedia_set_author)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
			std::string new_author = "Some1";
			encyclopedia.set_author(new_author);
			Assert::AreEqual(new_author, encyclopedia.get_author());
		}
		TEST_METHOD(encyclopedia_set_year)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
			std::string new_year = "2000";
			encyclopedia.set_year(new_year);
			Assert::AreEqual(new_year, encyclopedia.get_year());
		}
		TEST_METHOD(encyclopedia_info)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
			std::string expected = 
				"Title: Animals\nAuthor: Someone\nYear of issue: 1999\nTopic: Animals";
			Assert::AreEqual(expected, encyclopedia.info());
		}
		TEST_METHOD(encyclopedia_change_status)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia encyclopedia(title, author, year, &library, topic);
			encyclopedia.change_status();
			Assert::IsFalse(encyclopedia.get_status());
		}
		TEST_METHOD(fiction_create)
		{
			auto& library = Library::Get();
			std::string genre = "Romance";
			std::string title = "The Legend of King Arthur";
			std::string author = "Someone";
			std::string year = "1999";
			Fiction fiction(title, author, year, &library, genre);
		}
		TEST_METHOD(fiction_get_genre)
		{
			auto& library = Library::Get();
			std::string genre = "Romance";
			std::string title = "The Legend of King Arthur";
			std::string author = "Someone";
			std::string year = "1999";
			Fiction fiction(title, author, year, &library, genre);
			Assert::AreEqual(genre, fiction.get_genre());
		}
		TEST_METHOD(fiction_set_genre)
		{
			auto& library = Library::Get();
			std::string genre = "Romance";
			std::string title = "The Legend of King Arthur";
			std::string author = "Someone";
			std::string year = "1999";
			Fiction fiction(title, author, year, &library, genre);
			std::string new_genre = "Science fiction";
			fiction.set_genre(new_genre);
			Assert::AreEqual(new_genre, fiction.get_genre());
		}
		TEST_METHOD(fiction_info)
		{
			auto& library = Library::Get();
			std::string genre = "Romance";
			std::string title = "The Legend of King Arthur";
			std::string author = "Someone";
			std::string year = "1999";
			Fiction fiction(title, author, year, &library, genre);
			std::string expected = 
				"Genre: Romance\nTitle: The Legend of King Arthur\nAuthor: Someone\nYear of issue: 1999";
			Assert::AreEqual(expected, fiction.info());
		}
		TEST_METHOD(map_create)
		{
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			Map map(title, author, year, &library, area, type);
		}
		TEST_METHOD(map_get_area)
		{
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			Map map(title, author, year, &library, area, type);
			Assert::AreEqual(area, map.get_area());
		}
		TEST_METHOD(map_get_type)
		{
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			Map map(title, author, year, &library, area, type);
			Assert::AreEqual(type, map.get_type());
		}
		TEST_METHOD(map_set_area)
		{
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			Map map(title, author, year, &library, area, type);
			area = "Krakow";
			map.set_area(area);
			Assert::AreEqual(area, map.get_area());
		}
		TEST_METHOD(map_set_type)
		{
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			Map map(title, author, year, &library, area, type);
			type = "Road";
			map.set_type(type);
			Assert::AreEqual(type, map.get_type());
		}
		TEST_METHOD(library_add_encyclopedia)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia* encyclopedia = new Encyclopedia(title, author, year, &library, topic);
			library.add_book(encyclopedia);
			library.get_list_of_books().clear();
		}
		TEST_METHOD(library_get_list_of_encyclopedias)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia* encyclopedia = new Encyclopedia(title, author, year, &library, topic);
			library.add_book(encyclopedia);
			Assert::IsTrue(library.get_list_of_books()[0].get() == encyclopedia);
			library.get_list_of_books().clear();
		}
		TEST_METHOD(library_remove_encyclopedia)
		{
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia* encyclopedia = new Encyclopedia(title, author, year, &library, topic);
			library.add_book(encyclopedia);
			library.remove_book(encyclopedia);
		}
		TEST_METHOD(library_add_fiction)
		{
			auto& library = Library::Get();
			std::string genre = "Romance";
			std::string title = "The Legend of King Arthur";
			std::string author = "Someone";
			std::string year = "1999";
			library.add_book(new Fiction(title, author, year, &library, genre));
			library.get_list_of_books().clear();
		}
		TEST_METHOD(library_get_list_of_fictions)
		{
			auto& library = Library::Get();
			std::string genre = "Romance";
			std::string title = "The Legend of King Arthur";
			std::string author = "Someone";
			std::string year = "1999";
			Fiction* fiction = new Fiction(title, author, year, &library, genre);
			library.add_book(fiction);
			Assert::IsTrue(library.get_list_of_books()[0].get() == fiction);
			library.get_list_of_books().clear();
		}
		TEST_METHOD(library_remove_fiction)
		{
			auto& library = Library::Get();
			std::string genre = "Romance";
			std::string title = "The Legend of King Arthur";
			std::string author = "Someone";
			std::string year = "1999";
			Fiction* fiction = new Fiction(title, author, year, &library, genre);
			library.add_book(fiction);
			library.remove_book(fiction);
			Assert::IsTrue(library.get_list_of_books().empty());
		}
		TEST_METHOD(library_add_map)
		{
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			library.add_book(new Map(title, author, year, &library, area, type));
			library.get_list_of_books().clear();
		}
		TEST_METHOD(library_get_list_of_maps)
		{
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			Map* map = new Map(title, author, year, &library, area, type);
			library.add_book(map);
			Assert::IsTrue(library.get_list_of_books()[0].get() == map);
			library.get_list_of_books().clear();
		}
		TEST_METHOD(library_remove_map)
		{
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			Map* map = new Map(title, author, year, &library, area, type);
			library.add_book(map);
			library.remove_book(map);
			Assert::IsTrue(library.get_list_of_books().empty());
		}
		TEST_METHOD(library_info)
		{
			auto& library = Library::Get();
			library.set_name("Library name");
			library.set_phone("1234567");
			std::string exp = "Name: Library name\nPhone number: 1234567";
			Assert::AreEqual(exp, info(&library));
		}
		TEST_METHOD(user_create)
		{
			User user("Jack", "426158281");
		}
		TEST_METHOD(user_get_name)
		{
			std::string name = "Jack";
			std::string phone = "426158281";
			User user(name, phone);
			Assert::AreEqual(name, user.get_name());
		}
		TEST_METHOD(user_get_phone)
		{
			std::string name = "Jack";
			std::string phone = "426158281";
			User user(name, phone);
			Assert::AreEqual(phone, user.get_phone());
		}
		TEST_METHOD(user_set_name)
		{
			std::string name = "Jack";
			std::string phone = "426158281";
			User user(name, phone);
			name = "Adam";
			user.set_name(name);
			Assert::AreEqual(name, user.get_name());
		}
		TEST_METHOD(user_set_phone)
		{
			std::string name = "Jack";
			std::string phone = "426158281";
			User user(name, phone);
			phone = "1241251532";
			user.set_phone(phone);
			Assert::AreEqual(phone, user.get_phone());
		}
		TEST_METHOD(user_issue_encyclopedia)
		{
			User user("Jack", "12532152");
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia* encyclopedia = new Encyclopedia(title, author, year, &library, topic);
			library.add_book(encyclopedia);
			Assert::IsTrue(encyclopedia->get_status());
			user.issue_book(encyclopedia);
			Assert::IsFalse(encyclopedia->get_status());
		}
		TEST_METHOD(user_get_issued_encyclopedias)
		{
			User user("Jack", "12532152");
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia* encyclopedia = new Encyclopedia(title, author, year, &library, topic);
			library.add_book(encyclopedia);
			user.issue_book(encyclopedia);
			Assert::IsTrue(encyclopedia == user.get_issued_books()[0].get());
		}
		TEST_METHOD(user_return_encyclopedia)
		{
			User user("Jack", "12532152");
			auto& library = Library::Get();
			std::string title = "Animals";
			std::string author = "Someone";
			std::string year = "1999";
			std::string topic = "Animals";
			Encyclopedia* encyclopedia = new Encyclopedia(title, author, year, &library, topic);
			library.add_book(encyclopedia);
			Assert::IsTrue(encyclopedia->get_status());
			user.issue_book(encyclopedia);
			Assert::IsFalse(encyclopedia->get_status());
			user.return_book(encyclopedia);
			Assert::IsTrue(user.get_issued_books().empty());
			Assert::IsTrue(encyclopedia->get_status());
		}
		TEST_METHOD(user_issue_fiction)
		{
			User user("Jack", "12532152");
			auto& library = Library::Get();
			std::string genre = "Romance";
			std::string title = "The Legend of King Arthur";
			std::string author = "Someone";
			std::string year = "1999";
			Fiction* fiction = new Fiction(title, author, year, &library, genre);
			library.add_book(fiction);
			Assert::IsTrue(fiction->get_status());
			user.issue_book(fiction);
			Assert::IsFalse(fiction->get_status());
		}
		TEST_METHOD(user_get_issued_fiction)
		{
			User user("Jack", "12532152");
			auto& library = Library::Get();
			std::string genre = "Romance";
			std::string title = "The Legend of King Arthur";
			std::string author = "Someone";
			std::string year = "1999";
			Fiction* fiction = new Fiction(title, author, year, &library, genre);
			library.add_book(fiction);
			user.issue_book(fiction);
			Assert::IsTrue(fiction == user.get_issued_books()[0].get());
		}
		TEST_METHOD(user_return_fiction)
		{
			User user("Jack", "12532152");
			auto& library = Library::Get();
			std::string genre = "Romance";
			std::string title = "The Legend of King Arthur";
			std::string author = "Someone";
			std::string year = "1999";
			Fiction* fiction = new Fiction(title, author, year, &library, genre);
			library.add_book(fiction);
			Assert::IsTrue(fiction->get_status());
			user.issue_book(fiction);
			Assert::IsFalse(fiction->get_status());
			user.return_book(fiction);
			Assert::IsTrue(user.get_issued_books().empty());
			Assert::IsTrue(fiction->get_status());
		}
		TEST_METHOD(user_issue_map)
		{
			User user("Jack", "12532152");
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			Map* map = new Map(title, author, year, &library, area, type);
			library.add_book(map);
			Assert::IsTrue(map->get_status());
			user.issue_book(map);
			Assert::IsFalse(map->get_status());
		}
		TEST_METHOD(user_get_issued_map)
		{
			User user("Jack", "12532152");
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			Map* map = new Map(title, author, year, &library, area, type);
			library.add_book(map);
			user.issue_book(map);
			Assert::IsTrue(map == user.get_issued_books()[0].get());
		}
		TEST_METHOD(user_return_map)
		{
			User user("Jack", "12532152");
			auto& library = Library::Get();
			std::string title = "Warsaw Map";
			std::string author = "City";
			std::string year = "2019";
			std::string area = "Warsaw";
			std::string type = "Road";
			Map* map = new Map(title, author, year, &library, area, type);
			library.add_book(map);
			Assert::IsTrue(map->get_status());
			user.issue_book(map);
			Assert::IsFalse(map->get_status());
			user.return_book(map);
			Assert::IsTrue(user.get_issued_books().empty());
			Assert::IsTrue(map->get_status());
		}
		TEST_METHOD(user_info)
		{
			User user("Adam", "1234567");
			std::string exp = "Name: Adam\nPhone number: 1234567";
			Assert::AreEqual(exp, info(&user));
		}
	};
}
