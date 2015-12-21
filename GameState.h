#ifndef __GameState__
#define __GameState__

#include <string>

class GameState
{
public:

	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual bool getIsValid() const { return m_isValid; }
	virtual void setIsValid(bool isValid) { m_isValid = isValid; }

	virtual std::string getStateID() const = 0;

protected:
	GameState() : m_isValid(true) {}

private:
	bool m_isValid;
};

#endif /* defined(_GameState_) */