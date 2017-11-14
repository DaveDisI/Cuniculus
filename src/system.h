#pragma once

#include "io_manager.h"
#include "renderer_gl.h"

class System {
private:
	static System* instance;
	void initialize();

protected:
	System();

public:
	static System& getInstance();
	IOManager* iomgr;
	Renderer_GL* rndr;
	
	void update();
	void shutdown();
};