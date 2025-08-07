//#include <iostream>
//#include <Windows.h>
//#include <timeapi.h>
//
//#define GetName(Type) #Type
//
//    // 스테이트.
//class State
//{
//public:
//    State() = default;
//
//    virtual ~State()
//    {
//        if (name)
//        {
//            delete[] name;
//        }
//    }
//
//    virtual void OnStart()
//    {
//        std::cout << name << " OnStart\n";
//    }
//
//    virtual void OnUpdate(float deltaTime)
//    {
//        std::cout << name << " OnUpdate: " << deltaTime << "\n";
//    }
//
//    virtual void OnExit()
//    {
//        std::cout << name << " OnExit\n";
//    }
//
//protected:
//    char* name = nullptr;
//};
//
//class DialogueState : public State
//{
//public:
//    DialogueState()
//    {
//        auto length = strlen(GetName(DialogueState)) + 1;
//        name = new char[length];
//        strcpy_s(name, length, GetName(DialogueState));
//    }
//};
//
//class BattleState : public State
//{
//public:
//    BattleState()
//    {
//        auto length = strlen(GetName(BattleState)) + 1;
//        name = new char[length];
//        strcpy_s(name, length, GetName(BattleState));
//    }
//};
//
//class DefenceState : public State
//{
//public:
//    DefenceState()
//    {
//        auto length = strlen(GetName(DefenceState)) + 1;
//        name = new char[length];
//        strcpy_s(name, length, GetName(DefenceState));
//    }
//};
//
//class StateMachineManager
//{
//public:
//    StateMachineManager() = default;
//    ~StateMachineManager()
//    {
//        if (currentState)
//        {
//            delete currentState;
//        }
//    }
//
//    void ChangeState(State* newState)
//    {
//        if (currentState)
//        {
//            currentState->OnExit();
//        }
//
//        State* tempState = currentState;
//        currentState = newState;
//        currentState->OnStart();
//
//        if (tempState)
//        {
//            delete tempState;
//        }
//    }
//
//    void Run(float deltaTime)
//    {
//        if (currentState)
//        {
//            currentState->OnUpdate(deltaTime);
//        }
//    }
//
//    State* GetCurrentState() const
//    {
//        return currentState;
//    }
//
//private:
//    State* currentState = nullptr;
//};
//
//int main()
//{
//    StateMachineManager manager;
//
//    float currentTime = (float)timeGetTime();
//    float previouseTime = currentTime;
//    float frequency = 1000.0f;
//    float oneFrameTime = 1.0f / 60.0f;
//
//    bool isKeyDown = false;
//    bool previouseKeyDown = false;
//
//    while (true)
//    {
//        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
//        {
//            break;
//        }
//
//        isKeyDown = GetAsyncKeyState(VK_SPACE) & 0x8000;
//        currentTime = (float)timeGetTime();
//
//        float deltaTime = (currentTime - previouseTime) / frequency;
//        if (deltaTime >= oneFrameTime)
//        {
//            if (isKeyDown && !previouseKeyDown)
//            {
//                std::cout << "keydown\n";
//                previouseKeyDown = isKeyDown;
//
//                if (!manager.GetCurrentState())
//                {
//                    manager.ChangeState(new DialogueState());
//                    continue;
//                }
//
//                // Dialogue -> Battle -> Defence.
//                if (dynamic_cast<DialogueState*>(manager.GetCurrentState()))
//                {
//                    manager.ChangeState(new BattleState());
//                    continue;
//                }
//                if (dynamic_cast<BattleState*>(manager.GetCurrentState()))
//                {
//                    manager.ChangeState(new DefenceState());
//                    continue;
//                }
//                if (dynamic_cast<DefenceState*>(manager.GetCurrentState()))
//                {
//                    manager.ChangeState(new DialogueState());
//                    continue;
//                }
//            }
//
//            manager.Run(deltaTime);
//            previouseTime = currentTime;
//            previouseKeyDown = isKeyDown;
//        }
//    }
//
//    std::cin.get();
//}