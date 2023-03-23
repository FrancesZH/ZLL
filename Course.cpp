#include <iostream>
#include "Course.h"

Course::Course() {
	course = "";
	student = "";
}

Course::Course(const std::string &c, const std::string &s) 
{
	course = c;
	student = s;
}

bool Course::operator==(const Course &other) const {
	return ((course == other.course) &&
		(student == other.student));
}

bool isZany(const Course &c) {
	return (c.course == "CS240");
}

std::ostream &operator<<(std::ostream &out, const Course &c) {
	out << c.course << " [" << c.student << "]";
	return out;
}