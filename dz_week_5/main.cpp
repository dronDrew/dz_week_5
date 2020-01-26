#include"dependies.h"
#include"Stack_list.h"
#include"Line.h"
#include"Array_tamplate_2.h"
#include"Police_DB.h"

using namespace std;

int main() {
	Array<int>a;
	a.Add(5);
	a.Add(9);
	Array<int>b;
	b.Add(500);
	b.Add(900);
	a = b;
	cout << a[0] << a[1] << endl;
	a.Insert_at(500, 2);
	cout << a[0] << a[1]<<a[2] << endl;
	a.Remove_at(1);
	cout << a[0] << a[1] << endl;
	cout << a.GetData() << endl;
	return 0;
}