#include <iostream>
#include <fstream>

using namespace std;

struct Figure_1 {
	Figure_1(string fill1) {
		m_fill1 = fill1;
	}
	string m_fill1 = "#321411";
};

struct Figure_2 {
	Figure_2(string fill2) {
		m_fill2 = fill2;
	}
	string m_fill2 = "red";
};

struct Figure_3 {
	Figure_3(string fill3) {
		m_fill3 = fill3;
	}
	string m_fill3 = "blue";
};

struct Figure_4 {
	Figure_4(string fill4) {
		m_fill4 = fill4;
	}
	string m_fill4 = "green";
};

struct Brown_rect : Figure_1 {
	Brown_rect(double x, double y, double width, double height, string fill1) : m_x(x), m_y(y), m_width(width), m_height(height), Figure_1(fill1)
	{}
	double m_x = 0;
	double m_y = 0;
	double m_width = 0;
	double m_height = 0;
};

struct Red_line : Figure_2 {
	Red_line(double x, double y, double width, double height, const string& transform, string fill2) : m_x(x), m_y(y), m_width(width), m_height(height), transform(transform), Figure_2(fill2)
	{}
	double m_x = 0;
	double m_y = 0;
	double m_width = 0;
	double m_height = 0;
	string transform;
};

struct Blue_rect : Figure_3 {
	Blue_rect(double x, double y, double width, double height, const string& transform, string fill3) : m_x(x), m_y(y), m_width(width), m_height(height), transform(transform), Figure_3(fill3)
	{}
	double m_x = 0;
	double m_y = 0;
	double m_width = 0;
	double m_height = 0;
	string transform;
};

struct Green_rect : Figure_4 {
	Green_rect(double x, double y, double width, double height, const string& transform, string fill4) : m_x(x), m_y(y), m_width(width), m_height(height), transform(transform), Figure_4(fill4)
	{}
	double m_x = 0;
	double m_y = 0;
	double m_width = 0;
	double m_height = 0;
	string transform;
};

//output1 "<rect x = "5" y = "70" width = "90" height = "13" fill = "#321411"/>"
ostream& operator<<(ostream& os, const Brown_rect& br_r)
{
	return os << "<Brown_rect x=\"" << br_r.m_x << "\" y=\"" << br_r.m_y << "\" width=\"" << br_r.m_width << "\" height=\"" << br_r.m_height
		<< "\" fill1=\"" << br_r.m_fill1 << "\"/>";
}

//output2 "<rect x="-68" y= "64"  transform="rotate(-63 0 0)"  width="100" height="1.5" fill = "red"/>"
ostream& operator<<(ostream& os, const Red_line& r_l)
{
	return os << "<Red_line x=\"" << r_l.m_x << "\" y=\"" << r_l.m_y << "\" width=\"" << r_l.m_width << "\" height=\"" << r_l.m_height
		<< "\" transform=\"" << r_l.transform << "\" fill2=\"" << r_l.m_fill2 << "\"/>";
}

//output3 "<rect x="-46" y= "57"  transform="rotate(-63 0 0)"  width="45" height="45" fill = "blue"/>"
ostream& operator<<(ostream& os, const Blue_rect& bl_r)
{
	return os << "<Blue_rect x=\"" << bl_r.m_x << "\" y=\"" << bl_r.m_y << "\" width=\"" << bl_r.m_width << "\" height=\"" << bl_r.m_height
		<< "\" transform=\"" << bl_r.transform << "\" fill3=\"" << bl_r.m_fill3 << "\"/>";
}

//output4 "<rect x = "-55" y = "27" transform="rotate(-70 0 0)" width = "60" height = "13" fill = "green"/>"
ostream& operator<<(ostream& os, const Green_rect& gr_r)
{
	return os << "<Green_rect x=\"" << gr_r.m_x << "\" y=\"" << gr_r.m_y << "\" width=\"" << gr_r.m_width << "\" height=\"" << gr_r.m_height
		<< "\" transform=\"" << gr_r.transform << "\" fill4=\"" << gr_r.m_fill4 << "\"/>";
}

int main()
{
	Brown_rect br_r(5, 70, 90, 13, "#321411");
	cout << br_r;
	
	Red_line r_l(-68, 64, 100, 1.5, "rotate(-63 0 0)", "red");
	cout << r_l;

	Blue_rect bl_r(-46, 57, 45, 45, "rotate(-63 0 0)", "blue");
	cout << bl_r;

	Green_rect gr_r(-55, 27, 60, 13, "rotate(-70 0 0)", "green");
	cout << gr_r;

	ofstream svg("output.svg");
	if (svg.is_open()) {
		svg << "<svg xmlns = \"http://www.w3.org/2000/svg\"  width=\"600\" height=\"600\" viewBox=\"0 0 100 100\">" << endl;
		svg << br_r;
		svg << r_l;
		svg << bl_r;
		svg << gr_r;

		svg << "<\svg>" << endl;
		svg.close();
	}

	return 0;
}
