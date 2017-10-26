#include "Texture2D.h"
#include "GameObject.h"
#include "Player.h"
#include "GameLevel.h"
#include "Enemy.h"

const int GameLevel::ENEMY_COUNT = 40;

int GameLevel::score = 0;
bool GameLevel::canPlay = true;
bool GameLevel::gameOver = false;
Player* GameLevel::player = NULL;
std::map<int, GameObject*> GameLevel::gameObjects = std::map<int, GameObject*>();

GameLevel::GameLevel()
{
    score = 0;
    canPlay = true;
    gameOver = false;

    player = new Player(new QString("Player"), new QVector2D(32, 32));

    for (int i = 0; i < ENEMY_COUNT; i++)
    {
        Enemy *enemy = new Enemy(new QString("Enemy"), new QVector2D(17 + 17 * (i % 10), 100 + 20 * (i / 10)), i);
        gameObjects.insert(std::pair<int, GameObject *>(i, enemy));
    }
}

GameLevel::~GameLevel()
{

    for(std::map<int, GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
    {
        delete it->second;
    }

    delete(player);
    gameObjects.clear();
}

void GameLevel::paint()
{
    for(std::map<int, GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
    {
        it->second->render();
    }

    player->render();
}

void GameLevel::update()
{

    if (canPlay)
    {
        player->update();

        for (std::map<int, GameObject *>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
        {
            it->second->update();
        }

        for (std::map<int, GameObject *>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
        {
            if (it->second->shouldBeKilled)
            {
                gameObjects.erase(it->second->getId());
            }
        }
    }
}

void GameLevel::keyPressEvent(QKeyEvent *event)
{
    player->keyPressEvent(event);
}

Player *GameLevel::getPlayer()
{
    return player;
}

int GameLevel::getScore()
{
    return score;
}

void GameLevel::addScore(int score)
{
    GameLevel::score += score;
}

bool GameLevel::isCanPlay()
{
    return canPlay;
}

void GameLevel::setCanPlay(bool canPlay)
{
    GameLevel::canPlay = canPlay;
}
