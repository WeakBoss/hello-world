#include<iostream>
#include<string>
using namespace std;
class Table {
public:
	Table();
	Table(int x, int y) :a(x), b(y) {
		memset(mark, 0, sizeof(mark));
	}
	void show();
	void addRow();
	void addColumn();
	void set(int i, int j, int k);
	void set(int i, int j, string c);
	void delRow(int i);
	void delColumn(int i);
private:
	int a, b;
	string ss[10][10];
	int mark[10][10];
};
Table::Table() {
	a = b = 2;
	memset(mark, 0, sizeof(mark));
}
void Table::show() {
	for (int i = 0;i < a;i++) {
		for (int j = 0;j < b;j++) {
			cout << "********";
		}
		cout << endl;
		for (int j = 0;j < b;j++) {
			cout << '*';
			if (mark[i][j]) {
				cout << ss[i][j];
			}
			cout << '\t';
		}
		cout << '*' << endl;
	}
	for (int j = 0;j < b;j++) {
		cout << "********";
	}
	cout << endl<<endl;
}
void Table::addRow() {
	a++;
}
void Table::addColumn(){
	b++;
}
void::Table::delRow(int i) {
	a-=i;
}
void Table::delColumn(int i) {
	b -= i;
}
void Table::set(int i, int j,int n) {
	mark[i - 1][j - 1] = 1;
	ss[i - 1][j - 1] = "30";
}
void Table::set(int i, int j, string c) {
	mark[i - 1][j - 1] = 1;
	ss[i - 1][j - 1] = c;
}
int main() {
	Table tb;
	tb.show();
	tb.addRow();
	tb.show();
	tb.addColumn();
	tb.show();
	Table tb1(5, 5);
	tb1.show();
	tb1.set(1, 1, 30);
	tb1.set(2, 2, "hello");
	tb1.show();
	tb1.delRow(1);
	tb1.show();
	tb1.delColumn(1);
	tb1.show();
	return 0;
}

