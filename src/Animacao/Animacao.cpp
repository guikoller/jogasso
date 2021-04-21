#include "Animacao.h"

Animation::Animation()
	{
		currentFrame = 0;
		isPlaying = true;
		flip = false;
		loop = true;
	}

void Animation::tick(float time)
	{
		if (!isPlaying) return;

		currentFrame += speed * time;

		if (currentFrame >= frames.size()) {
			currentFrame -= frames.size();
			if (!loop) { isPlaying = false; return; }
		}

		int i = currentFrame;
		sprite.setTextureRect(frames[i]);
		if (flip) sprite.setTextureRect(frames_flip[i]);
	}


AnimationManager::AnimationManager(){}

AnimationManager::~AnimationManager()
	{
		animList.clear();
	}

void AnimationManager::loadFromXML(std::string fileName, Texture &t)
	{
		
	}

void AnimationManager::set(std::string name)
	{
		currentAnim = name;
		animList[currentAnim].flip = 0;
	}

void AnimationManager::draw(RenderWindow &window, int x = 0, int y = 0)
	{
		animList[currentAnim].sprite.setPosition(x, y);
		window.draw(animList[currentAnim].sprite);
	}

void AnimationManager::flip(bool b = 1) 
{ animList[currentAnim].flip = b; }

void AnimationManager::tick(float time) 
{ animList[currentAnim].tick(time); }

void AnimationManager::pause() 
{ animList[currentAnim].isPlaying = false; }

void AnimationManager::play() 
{ animList[currentAnim].isPlaying = true; }

void AnimationManager::play(std::string name) 
{ animList[name].isPlaying = true; }

bool AnimationManager::isPlaying() 
{ return animList[currentAnim].isPlaying; }

float AnimationManager::getH() 
{ return animList[currentAnim].frames[0].height; }

float AnimationManager::getW() 
{ return animList[currentAnim].frames[0].width; }
