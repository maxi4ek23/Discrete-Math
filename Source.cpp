#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

int main() {

    setlocale(LC_CTYPE, "ukr");

    vector<int> myvector1{ 2,3,4,5 };
    vector<int> myvector2{ 4,5,6,7 };
    vector<int> lol;
    vector<int> lol1;
    vector<int> result;
    vector<pair<int, int>> x3;
    sort(myvector1.begin(), myvector1.end());
    sort(myvector2.begin(), myvector2.end());


    for (int i = 0; i < myvector1.size(); i++) {
        for (int j = 0; j < myvector2.size(); j++) {
            x3.push_back(make_pair(myvector1[i], myvector2[j]));
        }
    }

    cout << "���������� �������:";
    for (int i = 0; i < x3.size(); i++)
    {
        cout << "(" << x3[i].first << "," << x3[i].second << ")" << " ";
    }
    cout << endl;

    //������� ������� �� ������ ������� �� ������� ��� ������, ��� ��� �������� �� ������ ������� �� �������� ��� ���������.

    cout << "����� �������� �������(������� ������� �� ���� ������� ��� ������ ������):";
    set_union(myvector1.begin(), myvector1.end(), myvector2.begin(), myvector2.end(), std::back_inserter(lol));

    for (const int& i : lol) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    cout << "����� �������� �������(������� ������� �� ���� ������� ��� ������ ������):";
    set_union(myvector1.begin(), myvector1.end(), myvector2.begin(), myvector2.end(), std::back_inserter(lol1));

    for (const int& i : lol1) {
        std::cout << i << ' ';
    }
    cout << endl;
    std::cout << '\n';

    //������� ����� �������� ������� �� ������ ������� ��� �������� � ����� �������� ��� ������ �������, ��� �������� ����� ��������

    cout << "г����� �� �������� �������� �� ������ ������� ��������:";
    for (int i = 0; i < lol.size(); i++) {
        for (int j = 0; j < myvector1.size(); j++) {

            if (lol[i] == myvector1[j]) {
                auto result3 = remove(lol.begin(), lol.end(), lol[i]);
                lol.erase(result3, lol.end());
            }
        }
    }

    for (int i = 0; i < lol.size(); i++) {
        cout << lol[i];
    }
    cout << endl;
    std::cout << '\n';

    //������� ����� �������� ������� �� ������ ������� ��� �������� � ����� �������� ��� ������ �������, ��� �������� ����� ��������

    cout << "г����� �� �������� �������� �� ������ ������� ��������:";
    for (int i = 0; i < lol1.size(); i++) {
        for (int j = 0; j < myvector2.size(); j++) {
            if (lol1[i] == myvector2[j]) {
                auto result2 = remove(lol1.begin(), lol1.end(), lol1[i]);
                lol1.erase(result2, lol1.end());

            }
        }
    }

    for (int i = 0; i < lol1.size(); i++) {
        cout << lol1[i];
    }
    cout << endl;
    std::cout << '\n';

    //������ ����� �������� � ���� ������� ��� �������� ���������� ������ ���� ������� ��� ������

    cout << "���������� ������ ���� ������:";
    set_union(lol.begin(), lol.end(), lol1.begin(), lol1.end(), std::back_inserter(result));

    for (const int& i : result) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}