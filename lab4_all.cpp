#include <iostream>

class Money {
private:
    unsigned int rubles;
    short int kopeks;

public:
    Money() {
        rubles = 0;
        kopeks = 0;
    }

    Money(unsigned int r, short int k) {
        rubles = r;
        kopeks = k;
    }
    friend std::ostream& operator<<(std::ostream& os, const Money& money) {
        os << money.rubles << "Рубли" << money.kopeks << "Копейки";
        return os;
    }
        Money& operator++() {
        if (kopeks == 99) {
            rubles++;
            kopeks = 0;
        } else {
            kopeks++;
        }
        return *this;
    }

    Money& operator--() {
        if (kopeks == 0) {
            if (rubles == 0) {
                std::cout << "Нельзя вычесть, ведь сумма уже ноль." << std::endl;
            } else {
                rubles--;
                kopeks = 99;
            }
        } else {
            kopeks--;
        }
        return *this;
    }

    operator unsigned int() const {
        return rubles;
    }

    explicit operator double() const {
        return static_cast<double>(kopeks) / 100;
    }

    Money operator-(const unsigned int& num) {
        Money result;
        if (rubles >= num) {
            result.rubles = rubles - num;
            result.kopeks = kopeks;
        } else {
            result.rubles = 0;
            result.kopeks = 0;
            std::cout << "Результат 0 или отрицательный, сумма сброшена до 0, попробуйте еще раз." << std::endl;
        }
        return result;
    }

    Money operator-(const Money& other) {
        Money result;
        int totalKopeks1 = rubles * 100 + kopeks;
        int totalKopeks2 = other.rubles * 100 + other.kopeks;

        if (totalKopeks1 >= totalKopeks2) {
            int diff = totalKopeks1 - totalKopeks2;
            result.rubles = diff / 100;
            result.kopeks = diff % 100;
        } else {
            result.rubles = 0;
            result.kopeks = 0;
            std::cout << "Результат 0 или отрицательный, сумма сброшена до 0, попробуйте еще раз." << std::endl;
        }

        return result;
    }
};

int main() {
    unsigned int rub1, rub2, rub3;
    short int kop1, kop2, kop3;

    std::cout << "Введите первую сумму денег:" << std::endl;
    std::cout << "Рубли: ";
    std::cin >> rub1;
    std::cout << "Копейки: ";
    std::cin >> kop1;

    std::cout << "Введите вторую сумму денег:" << std::endl;
    std::cout << "Рубли: ";
    std::cin >> rub2;
    std::cout << "Копейки: ";
    std::cin >> kop2;

    std::cout << "Введите вторую сумму денег:" << std::endl;
    std::cout << "Рубли: ";
    std::cin >> rub3;
    std::cout << "Копейки: ";
    std::cin >> kop3;

    Money money1(rub1, kop1);
    Money money2(rub2, kop2);
    Money money2(rub3, kop3);

    std::cout << "Сумма1: " << money1 << std::endl;
    std::cout << "Сумма2: " << money2 << std::endl;
    std::cout << "Сумма2: " << money3 << std::endl;

    Money result = money1 - money2 + money3;

    std::cout << "Результат вычитания двух сумм: " << result << std::endl;

    ++money1;
    --money2;
    ++money3;

    std::cout << "Сумма1 после увеличения: " << money1 << std::endl;
    std::cout << "Сумма2 после уменьшения: " << money2 << std::endl;
    std::cout << "Сумма3 после увеличения: " << money3 << std::endl;

    unsigned int rubles1 = money1;
    double kopeks2 = static_cast<double>(money2);
    double kopeks3 = static_cast<double>(money3);

    std::cout << "Сумма1 в рублях: " << rubles1 << std::endl;
    std::cout << "Сумма2 в копейках как десятичная дробь: " << kopeks2 << std::endl;
    std::cout << "Сумма3 в копейках как десятичная дробь: " << kopeks3 << std::endl;

return 0;

}
