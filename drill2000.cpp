#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

template<typename C>
void print(const C& c, char sep = '\n') {
	cout << "Container elements: \n";

	for (const auto elem : c) {
		cout << elem << sep;
	}
	cout << endl;
}

int main()
try {
	const string iname{ "asd.txt" };
	ifstream ifs{ iname };
	if (!ifs) throw runtime_error("Couldn't read from the file " + iname);

	vector<double> vd;
	for (double d; ifs >> d;) {
		vd.push_back(d);
	}
	print(vd);

	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());
	print(vi);
	
	for (int i = 0; i < vd.size(); i++) {
		cout << vd[i] << '\t' << vi[i] << endl;
	}

	double vd_sum = accumulate(vd.begin(), vd.end(), 0.0);

	double diff_sum = inner_product(vd.begin(), vd.end(), vi.begin(), 0.0, plus<double>(), minus<double>());
	cout << "Cumulative" << diff_sum << vd_sum << endl;

	reverse(vd.begin(), vd.end());
	print(vd);

	double vd_mean = vd_sum / vd.size();
	cout << vd_mean << endl;

	vector<double> v2;
	for (int i = 0; i < vd.size(); i++)
	{
		if (vd_mean > vd[i]) {
			v2.push_back(vd[i]);}
	}
	print(v2);

	sort(vd.begin(), vd.end());
	print(vd);


}catch (exception& e) {
	cerr << e.what() << endl;
	return 1;

}
catch (...) {
	cerr << "Unknown exception" << endl;
}

