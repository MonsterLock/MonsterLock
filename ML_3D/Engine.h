#pragma once
#include "MainWindow.h"
#include "RendererOGL.h"
#include "RendererD3D.h"

class Engine
{
	int mRet;
	std::unique_ptr<MainWindow> mMainWindow;
	Renderer* mRenderer;
	HACCEL mHAccel;

public:
	Engine() noexcept;
	void Initialize();
	void Update();
	void Terminate();
	int Run();
};