#include "Player.h"
#include "Input.h"
#include "Utils/Utils.h"

Player::Player(Vector2 position)
			: Actor("<-*->",Color::Red)
{
    this->position.x=position.x-2,
    this->position.y=position.y;

}

void Player::BeginPlay()
{
}

void Player::Tick(float deltaTime)
{

    if (Input::Get().GetKey(VK_LEFT))
    {
        Vector2 Afterposition = Position();
        Afterposition.x -= 1;
        if (Afterposition.x - 1 >= 0)
        {
            position.x=Afterposition.x;
            position.y = Afterposition.y;
        }
    }

    if (Input::Get().GetKey(VK_RIGHT))
    {
        Vector2 Afterposition = Position();
        Afterposition.x += 1;
        if (Afterposition.x + 2 <=86 )
        {
            position.x = Afterposition.x;
            position.y = Afterposition.y;
        }
    }

    if (Input::Get().GetKey(VK_UP))
    {
        Vector2 Afterposition = Position();
        Afterposition.y -= 1;
        if (Afterposition.y>=0)
        {
            position.x = Afterposition.x;
            position.y = Afterposition.y;
        }
    }

    if (Input::Get().GetKey(VK_DOWN))
    {
        Vector2 Afterposition = Position();
        Afterposition.y += 1;
        if (Afterposition.y <=15)
        {
            //position.x = Afterposition.x;
            //position.y = Afterposition.y;
            SetPosition(Afterposition);
        }
    }
}

void Player::Render()
{
    super::Render();
}
