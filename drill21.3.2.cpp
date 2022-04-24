#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> vd;
    const string iname{ "asd.txt" };
    ifstream ifs{ iname };

    double number;
    while (!ifs.eof()) {
        ifs >> number;
        vd.push_back(number);
    }

    cout << "VD's elements:\n";
    for (double& a : vd) {
        cout << a << '\n';
    }

    vector<int> vi(vd.size());
    cout << "\n\nVI's elements:\n";
    copy(vd.begin(), vd.end(), vi.begin());
    for (int& a : vi) {
        cout << a << '\n';
    }

    cout << "\nVD" << '\t' << "VI" << endl;
    for (int i = 0; i < vd.size(); i++) {
        cout << vd[i] << "\t" << vi[i] << endl;
    }

    double sumvd = 0;
    int sumvi = 0;
    for (double& a : vd) {
        sumvd = sumvd + a;
    }
    for (int& a : vi) {
        sumvi = sumvi + a;
    }

    cout << "\nSum of VD: " << sumvd << "\nSum of VI: " << sumvi << endl;
    cout << "Difference between sumvd and sumvi: " << sumvd - sumvi << endl;

    reverse(vd.begin(), vd.end());

    cout << "\nVD's elements after reverse:\n";
    for (double& a : vd) {
        cout << a << '\n';
    }

    double mean = sumvd / vi.size();
    cout <<"\nMean value of the elements in VD: " << mean << endl;

    vector<double> vd2;
    for (int i = 0; i < vd.size(); i++) {
        if (vd[i] < mean) {
            vd2.push_back(vd[i]);
        }
    }

    cout << "\nVD2's elements:\n";
    for (double& a : vd2) {
        cout << a << '\n';
    }

    sort(vd.begin(), vd.end());
    cout << "\nVD's elements after sort:\n";
    for (double& a : vd) {
        cout << a << '\n';
    }
}
