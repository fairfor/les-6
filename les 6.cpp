#include <iostream>

using namespace std;

// =========================================

void task1() {
    cin.clear();
    cin.sync();
    int n;
    cout << "Please enter integer number: ";
    cin >> n;
    if (n || cin.get() != '\n') {
        if (n) cout << "Your number is " << n << "\n";
    }
    else {
        cout << "Sorry, but it's not correct. Try again!\n";
        task1();
    }
}

// =========================================

ostream& endll(ostream& en) {
    en.flush();
    return en << '\n' << '\n';
}

void task2() {
    cout << endll << "this is example" << endll << "text";
}

// =========================================

class GenericPlayer : card {
public:
    string PlayerName;
};

class Player : public GenericPlayer {
    bool choose;
public:
    virtual bool IsHitting() const {
        return choose;
    }

    void Win() const {
        cout << "The " << PlayerName << " won!!!\n Congratulations\n";
    }

    void Lose() const {
        cout << "The " << PlayerName << " lost!!!\n Nice try\n";
    }

    void Push() const {
        cout << "The " << PlayerName << " drew!!!\n Nice try\n";
    }
};

// =========================================

class card {
    enum suit {
        worms = 'w',
        baptize = 'b',
        peaks = 'p',
        tambourine = 't'
    };
    enum Number {
        two = '2',
        three = '3',
        four = '4',
        five = '5',
        six = '6',
        seven = '7',
        eight = '8',
        nine = '9',
        ten = '10',
        jack = '10',
        queen = '10',
        king = '10',
        ace = '11',
        ace_1 = '1'
    };

public:
    bool map_position{}; // вверх лицом - false, рубашкой - true

    void flip() {
        if (map_position) {
            map_position = false;
        }
        else if (map_position == false) {
            map_position = true;
        }
    }
    int getValue(Number n, int cursor) {
        if (cursor <= 21) {
            return n;
        }
        else {
            return -1;
        }
    }
};

class House : public card, public GenericPlayer {
public:
    virtual bool IsHitting() const;
    void FlipFirstCard() {
        card c;
        c.flip();
    }
};

// =========================================

int main()
{
    task1();
    task2();
}