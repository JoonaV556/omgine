class Engine
{
public:
    Engine();

    /// @brief
    /// @return 0 while running without problems,
    /// 1 encountered error and ended,
    /// 2 engine ended normally
    void Run();
};