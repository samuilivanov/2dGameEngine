#include <sfge.h>

class Sandbox : public SFGE::Application
{
public:
    Sandbox()
    {

    }
    ~Sandbox()
    {

    }
};

SFGE::Application *SFGE::createApplication()
{
    return new Sandbox();
}
