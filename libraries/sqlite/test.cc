
#include <iod/sqlite/sqlite.hh>


using namespace iod::sqlite;

int main()
{
  auto db = sqlite_database("iod_sqlite_test.db");

  auto c = db.get_connection();

  c("DROP TABLE IF EXISTS person;")();
  c("CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR, age INTEGER);")();
  c("INSERT into person(name, age) VALUES (?, ?)")("John", 42);
  c("INSERT into person(name, age) VALUES (?, ?)")("Ella", 21);

  c("SELECT id, name, age from person") | [](int id, std::string name, int age) {
    std::cout << id << ", " << name << ", " << age << std::endl;
  };
}
