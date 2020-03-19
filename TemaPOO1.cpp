#include <iostream>
using namespace std;

bool exist(const int v[], const int n, const int x) {
	for (int i = 0; i < n; i++)
		if (v[i] == x) return true;
	return false;
}

class Multime {
	int v[100]; // lucram cu un vector static
	int n;


public:

	// constructor default
	Multime() {
		n = 0;
	}
	// copy constructor
	Multime(const Multime& ot) {
		n = ot.n;
		for (int i = 0; i < n; i++) {
			v[i] = ot.v[i];
		}
	}
	// destructor
	~Multime() {
		n = 0;
	}
	// constructor pe array (static), nr_elemente al arrayului
	Multime(const int x[], int nr) {
		n = 0;
		for (int i = 0; i < nr; i++) {
			int j = 0;
			for (j = 0; j < i; j++)
				if (x[i] == x[j]) break;
			if (i == j) {
				v[n] = x[i];
				n++;
			}
		}


	}
	// get addres
	int getAddress() {
		return *v;
	}
	// get n
	int getNr() {
		return n;
	}

	int operator[](const int index) {
		return v[index];

	}

	//overload pe operator=
	void operator=(const Multime& ot) {
		n = ot.n;
		for (int i = 0; i < n; i++)
			v[i] = ot.v[i];
	}

	// overload pe operator+ (reuniune)
	Multime operator+(const Multime& ot) {
		int v1[200];
		for (int i = 0; i < n; i++) {
			v1[i] = v[i];
		}
		for (int i = 0; i < ot.n; i++) {
			v1[i + n] = ot.v[i];
		}
		int nr = n + ot.n;
		Multime rez(v1, nr);
		return rez;
	}

	// overload pe operator* (intersectie)
	Multime operator*(const Multime& ot) {
		int v1[100];
		int nr = 0;
		for (int i = 0; i < ot.n; i++) {
			if (exist(v, n, ot.v[i])) {
				v1[nr] = ot.v[i];
				nr++;
			}
		}
		Multime rez(v1, nr);
		return rez;
	}

	//overload pe operator- (diferenta)
	Multime operator-(const Multime& ot) {
		int v1[100];
		int nr = 0;
		for (int i = 0; i < n; i++) {
			if (!exist(ot.v, ot.n, v[i])) {
				v1[nr] = v[i];
				nr++;
			}
		}
		for (int i = 0; i < ot.n; i++) {
			if (!exist(v, n, ot.v[i])) {
				v1[nr] = ot.v[i];
				nr++;
			}
		}

		Multime rez(v1, nr);
		return rez;
	}

	// metoda de direct print Multime
	void printMultime() {
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
	}

};
int main()
{

}