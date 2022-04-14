#include "date.h"

enum Gender { male, female };
enum Food {fruits, sweet,vegetable};
enum Drink {water, milk, juice, alcohol};
enum EyeColor {green, blue, black, grey, brown};
enum HairColor {black,brown};

class Human {
private:
    Date _birthDay = "";
    EyeColor _eyeColor = green;
    HairColor _hairColor = brown;
    Gender _gender = male;
    Human _father;
    Human _mother;
    int _healthLevel = 100;
    int _mentalHealth = 100;
    int _badHealth = 0;
    int _hungry = 0;
    int _thirsty = 0;
    void Think();
    void Digest();

public:
    Date* getBirthDay() const;
    void setBirthDay(Date* birthDay);

    EyeColor getEyeColor() const;
    void setEyeColor(EyeColor eyeColor);

    HairColor getHairColor() const;
    void setHairColor(HairColor hairColor);

    Gender getGender() const;
    void setGender(Gender gender);
    
    Human getFather() const;
    Human getMother() const;
    
    int getHealthLevel() const;
    void setHealthLevel(int healthLevel);   
    
    int getMentalHealth() const;
    void setMentalHealth(int mentalHealth); 
    
    int getBadHealth() const;
    void setBadHealth(int badHealth); 
    
    int getHungry() const;
    void setHungry(int hungry);
    
    int getThirsty() const;
    void setThirsty(int thirsty);
    
    void Wolk();
    void Bearth();
    void Eat(Food _food);
    void Drink(Drink _drink);
    Human(Date birthDay, int eyeColor, int hairColor, Gender gender, Human father, Human mother);
    Human(Date birthDay, int eyeColor, int hairColor, Gender gender, Human mother);
    Human(Date birthDay, int eyeColor, int hairColor, Gender gender, Human father);
    Human(Date birthDay, int eyeColor, int hairColor, Gender gender);
    Human(const Human & human);
    Human();
    ~Human();
    
};
