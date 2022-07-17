//#include <iostream> 
//using namespace std;
//class Foo {
//	char ch;
//public:
//	Foo(int c) {
//		ch=c;
//	}
//	void show(char ch) {
//		cout << this->ch << ch;
//		ch = this->ch;
//	}
//	~Foo() {
//		cout << ch;
//	}
//};
//int main() {
//	Foo a('B');
//	a.show('C');
//	return 0;
//}
//#include <iostream> 
//using namespace std;
//int main() {
//	cout << 'X';
//	cout.fill('$');
//	cout.width(3);
//	cout.setf(ios::fixed);
//	cout.precision(0);
//	cout << 2.7 << 'X';
//	return 0;
//}
//#include <iostream> 
//using namespace std;
//int main() {
//	int a[]{ 1,0,2,0,3,0,2,7,0,3,0,0,7,-1 };
//	int f = 0;
//	for (int i = 0; a[i] != -1; i++) {
//		f += !a[i];
//	}
//	cout << f;
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Player {
    char m_name[21];
public:
    std::ostream& display(std::ostream& ostr) const {
        return ostr << m_name;
    }
    Player(const char* name = nullptr) {
        strcpy(m_name, name);
    }
}
std::ostream& Player::operator<<(std::ostream& ostr, const Player& P) {
    return P.display(ostr);
}
class Team {
    int m_num{};
    Player* m_players{};
public:
    Player& operator[](int index)const {
        return m_players[index % m_num];
    }
    Team& operator<<(Player& P) {
        Player* temp{};
        temp = new Player[m_num + 1];
        temp[m_num] = P;
        for (int i = 0; i < m_num; i++)
            temp[i] = m_players[i];
        delete[] m_players;
        m_players = temp;
        m_num++;
        return *this;
    }
    operator int() const{
        return m_num;
    }
    operator bool()const {
        return m_num != 0;
    }
};
std::ostream& operator<<(std::ostream& ostr, const Team& L) {
    for (int i = 0; i < L; i++) {
        ostr << i + 1 << ":" << L[i] << " ";
    }
    return ostr;
}
void displayTeam(const Team& L, const char* title) {
    cout << title;
    if (!L)
        cout << " is empty!";
    else
        cout << endl << L;
    cout << endl << "--------------" << endl;
}
int main() {
    Player P;
    cout << "Empty: " << P << endl;
    P = "Ronaldinho";
    cout << "Not Empty: " << P << endl;
    Team L;
    displayTeam(L, "Empty Team");
    L << "Ronaldo" << "Lionel" << "Pele";
    displayTeam(L, "Global Team");
    return 0;
}

/*
* Intended Output
Empty:
Not Empty: Ronaldinho
Empty Team is empty!
--------------
Global Team
1:Ronaldo 2:Lionel 3:Pele
--------------
*/

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//const short max_value = 100;
//class Short {
//    short int m_value;
//public:
//    Short() {
//        m_value = 0;
//    }
//    Short(short value=0) {
//        if (value >= 0 && value<=max_value) {
//            m_value = value;
//        }
//        else {
//            m_value = -1;
//        }
//    }
//
//    Short& operator=(const Short& ro) {
//        if (ro.m_value >= 0 && ro.m_value <= max_value) {
//            m_value = ro.m_value;
//        }
//        else {
//            m_value = -1;
//        }
//        return *this;
//    }
//    
//    operator int() const {
//        return this->m_value;
//    }
//
//    std::istream& read(std::istream& istr) {
//        short tempShort;
//        istr >> tempShort;
//        bool done = true;
//        do {
//            done = true;
//            istr >> m_value;
//            if (istr.fail()) {
//                istr.clear();
//                cout << "Bad Short, re-enter: " << endl;
//                done = false;
//            }
//            else {
//                if (m_value < 0 || m_value > max_value) {
//                    cout << "Invalid Value, re-enter: " << endl;
//                }
//            }
//        } while (!done);
//        return istr;
//    }
//
//};
//// operator<< overaload (cout << ...)
//std::ostream& operator<<(std::ostream& ostr, const Short& ro) {
//    ostr << ro.operator int();
//    return ostr;
//}
//
//std::istream& operator>>(std::istream& istr, Short& ro) {
//    return ro.read(istr);
//}
//
//// foolproof operator>> overlaod ( cin >> ...)
//class ShortArray {
//    Short* m_shorts{};
//    int m_num_of_shorts{};
//
//public:
//    // one argument constructor
//    ShortArray(int size = 1) {
//        if (size >= 0) {
//            m_num_of_shorts = size;
//        }
//        else {
//            m_num_of_shorts = 1;
//        }
//    }
//
//    // modifier index operator
//    Short& operator[](int index) const {
//        if (index < m_num_of_shorts) {
//            return m_shorts[index % m_num_of_shorts];
//
//        }
//        else {
//            ShortArray* temp{};
//            temp = new ShortArray[index + 1];
//            for (int i = 0; i < m_num_of_shorts; i++) {
//                temp[i] = m_shorts[i];
//            }
//        }
//    }
//
//    // qurey index operator
//    Short& operator[](int index) const {
//        if (index < m_num_of_shorts) {
//            return m_shorts[index % m_num_of_shorts];
//        }
//    }
//
//    // integer cast overlaod
//    operator int short() const {
//        return this->m_num_of_shorts;
//    }
//
//    // memory cleanup
//    void deallocate() {
//        delete[] m_shorts;
//        m_shorts = nullptr;
//    }
//};
//void prnShortArray(const ShortArray & S) {
//    int i = 0;
//    // looping 3 times (size of S) 
//    cout << "S has " << int(S) << " elements: ";
//    while (i < S) {  // S will be casted to an integer by compiler
//        cout << "S[" << i << "]= " << S[i++] << ", ";
//    }
//    // goin out of bound but since S is const the operator[] should loop back instead of resizing
//    cout << "S[" << i << "]: " << S[i++] << endl;
//}
//int main() {
//    Short A = 300, B = 55;
//    cout << "Invalid A has the value " << A << endl;
//    cout << "Valid B has the value " << B << endl;
//    ShortArray D(2);
//    prnShortArray(D);
//    D[0] = 10;
//    D[1] = 20;
//    D[2] = 300;  // going out of bound to resize and also set to invalid
//    prnShortArray(D);
//    cout << "Enter a Short: ";
//    cin >> D[2];
//    prnShortArray(D);
//    return 0;
//}