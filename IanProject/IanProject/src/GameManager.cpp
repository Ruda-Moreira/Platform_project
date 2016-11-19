#include "GameManager.h"

GameManager::GameManager() {
}

void GameManager::clear() {
    for (GameObject* object : objects) {
        delete  object;
    }
    objects.clear();
}

void GameManager::add(GameObject* object)
{
    object->init();
    objects.push_back(object);
}

void GameManager::update(float secs)
{
    std::vector<GameObject*> alive;
    std::vector<GameObject*> toDelete;
    
    std::swap(toDelete, dead);
    
    //Para cada objeto object em objects
    for (GameObject* object : objects) {
        object->update(secs);
        if (!object->isAlive()) {
            dead.push_back(object);
        } else {
            alive.push_back(object);
        }
    }
    
    for (int i = 0; i < objects.size()-1; i++) {
        for (int j = i+1; j < objects.size(); j++) {
            if (objects[i]->bounds().intersects(objects[j]->bounds())) {
                objects[i]->collidedWith(objects[j]);
                objects[j]->collidedWith(objects[i]);
            }
        }
    }
    
    for (GameObject* object : toDelete) {
        delete object;
    }
    
    std::swap(alive, objects);
}

void GameManager::draw(const ofVec2f& camera)
{
    for (GameObject* object : objects) {
        object->draw(camera);
    }
}

GameManager& GameManager::instance() {
    static GameManager manager;
    return manager;
}

GameManager::~GameManager()
{
    clear();
}
