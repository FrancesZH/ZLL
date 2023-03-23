#include <iostream>
class Course {
	private:
		std::string course = "";
		std::string student = "";
	public:
		Course();
		Course(const std::string &c, const std::string &s);
		bool operator==(const Course &other) const;
		friend bool isZany(const Course &c);
		friend std::ostream &operator<<(std::ostream &out, const Course &c);
		void print();
};
