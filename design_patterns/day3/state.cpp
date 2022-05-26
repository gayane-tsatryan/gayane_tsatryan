#include <iostream>
using namespace std;
enum Mark {
    Two = 2,
    Five = 5
};
class State {
public:
    virtual void HandleMark(Father father, Mark mark)
    {
        ChangeState(father, mark);
    }

protected:
    virtual void ChangeState(Father father, Mark mark) = 0;
};
class AngerState : public State {
public:
    AngerState()
    {
        cout << "Отец в состоянии гнева:";
        Scold();
    }

protected:
    void ChangeState(Father father, Mark mark) override
    {
        switch (mark) {
        case Two: {
            father.state = new StrongAngerState(); // S2
            break;
        }
        case Five: {
            father.state = new NeutralState(); // S0
            break;
        }
        }
    }

    // y1
private:
    void Scold()
    {
        cout << "Ругает сына.";
    }
};
class StrongJoyState : public State {
public:
    StrongJoyState()
    {
        cout << "Отец в состоянии сильной радости:";
        Exult();
    }

protected:
    void ChangeState(Father father, Mark mark) override
    {
        switch (mark) {
        case Two: {
            father.state = new PityState(); // S1
            break;
        }
        case Five: {
            father.state = new StrongJoyState(); // S5
            break;
        }
        }
    }

    // y5
private:
    void Exult()
    {
        cout << "Ликует и гордится сыном.";
    }
};
class StrongAngerState : public State {
public:
    StrongAngerState()
    {
        cout << "Отец в состоянии сильного гнева:";
        BeatBelt();
    }

protected:
    void ChangeState(Father father, Mark mark) override
    {
        switch (mark) {
        case Two: {
            father.state = new StrongAngerState(); // S2
            break;
        }
        case Five: {
            father.state = new NeutralState(); // S0
            break;
        }
        }
    }

    // y0
private:
    void BeatBelt()
    {
        cout << "Бьет сына ремнем.";
    }
};
class PityState : public State {
public:
    PityState()
    {
        cout << "Отец в состоянии жалости:";
        Calm();
    }

protected:
    void ChangeState(Father father, Mark mark) override
    {
        switch (mark) {
        case Two: {
            father.state = new AngerState(); // S4
            break;
        }
        case Five: {
            father.state = new NeutralState(); // S0
            break;
        }
        }
    }

    // y2
private:
    void Calm()
    {
        cout << "Успокаивает сына.";
    }
};
class JoyState : public State {
public:
    JoyState()
    {
        cout << "Отец в состоянии радости:";
        Joy();
    }

protected:
    void ChangeState(Father father, Mark mark) override
    {
        switch (mark) {
        case Two: {
            father.state = new PityState(); // S1
            break;
        }
        case Five: {
            father.state = new StrongJoyState(); // S5
            break;
        }
        }
    }

    // y4
private:
    void Joy()
    {
        cout << "Радуется успехам сына.";
    }
};
class NeutralState : public State {
public:
    NeutralState()
    {
        cout << "Отец в нейтральном состоянии:";
        Hope();
    }

protected:
    void ChangeState(Father father, Mark mark) override
    {
        switch (mark) {
        case Two: {
            father.state = new PityState(); // S1
            break;
        }
        case Five: {
            father.state = new JoyState(); // S3
            break;
        }
        }
    }

    // y3
private:
    void Hope()
    {
        cout << "Надеется на хорошие оценки.";
    }
};
class Father {
public:
    State* state;

    Father()
    {
        state = new NeutralState();
    }
    // Father * state1 = state;
    void FindOut(Mark mark)
    {
        state->HandleMark(Father(), mark);
    }
};

int main()
{
    auto* father = new Father();

    while (true) {
        Mark mark;

        if (mark == Two || mark == Five) {
            father->FindOut(mark);
        }
    }
    return 0;
}
