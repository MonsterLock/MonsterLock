#pragma once
#include "WindowEditor.h"
#include "Mode.h"

class Editor : public Mode
{
	friend class Engine;
	std::unique_ptr<WindowEditor> mWindowEditor;
	HACCEL mHAccel;

public:
	Editor() noexcept;
	void Initialize();
	int Update( std::shared_ptr<Renderer> );
	void Terminate();
};
