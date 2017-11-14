#pragma once

#include <vector>

#include <GL/glew.h>

using namespace std;

class Renderer_GL {
public:
	struct VAO_GL {
		enum {
			V2,
			V2_V2,
			V2_V2_V2,
			V3,
			V3_V2,
			V3_V3,
			V3_V3_V2
		};

		GLuint id;
		GLuint vertexBuffer;
		GLuint elementBuffer;
		GLbitfield elementDataSize;
		unsigned int vertexLayout;
		unsigned int totalVertices = 0;
		unsigned int totalElements = 0;
	};

	static Renderer_GL& getInstance();

	void setClearColor(float r, float g, float b, float a);
	void clear(int bit);
	void shutdown();
	void bindVAO(unsigned int vao);
	void bindVBO(unsigned int vbo, int type);
	void updateVAO(VAO_GL& vao, unsigned int vertexCount, unsigned int elementCount, void* vertexData, void* elementData);
	void deleteVAO(VAO_GL& vao);

	VAO_GL createVAO(unsigned int vertexLayout, unsigned int elementSize);


private:
	static Renderer_GL* instance;

	vector<GLuint> shaders;

	Renderer_GL();
	void initialize();
};