enum Gender { male, female };
enum Food {apple, sweet};
enum Drink {wother, milk};
class Human {
private:
    //Date _birthDay;
    int _eyeColor;
    int _hairColor;
    Gender _gender;
    Human _father;
    Human _mother;
    int _healthLevel;
    int _mentalHealth;
    void Think();
    void Digestion();

public:
    void Wolk();
    void Breath();
    void Eat(Food _food);
    void Drink(Drink _drink);
    Human(Date _birthDay, int _eyeColor, int _hairColor, Gender _gender, Human _father, Human _mother);
};
