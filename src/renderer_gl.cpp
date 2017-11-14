#include <iostream>

#include "renderer_gl.h"

Renderer_GL* Renderer_GL::instance = nullptr;

Renderer_GL & Renderer_GL::getInstance(){
	if (!instance) {
		instance = new Renderer_GL();
	}

	return *instance;
}

void Renderer_GL::setClearColor(float r, float g, float b, float a){
	glClearColor(r, g, b, a);
}

void Renderer_GL::clear(int bit){
	glClear(bit);
}

void Renderer_GL::shutdown(){
	if (instance) {
		delete instance;
		instance = nullptr;
	}
}

void Renderer_GL::bindVAO(unsigned int vao){
	glBindVertexArray(vao);
}

void Renderer_GL::bindVBO(unsigned int vbo, int type){
	glBindBuffer(type, vbo);
}


void Renderer_GL::updateVAO(VAO_GL& vao, unsigned int vertexCount, unsigned int elementCount, void * vertexData, void * elementData){
	GLuint newBuffer;
	glGenBuffers(1, &newBuffer);
	glBindBuffer(GL_COPY_READ_BUFFER, vao.vertexBuffer);
	glBindBuffer(GL_COPY_WRITE_BUFFER, newBuffer);
	glBufferData(GL_COPY_WRITE_BUFFER, sizeof(GLfloat) * (vao.totalVertices + vertexCount), NULL, GL_STATIC_DRAW);
	glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, sizeof(GLfloat) * vao.totalVertices);
	glDeleteBuffers(1, &vao.vertexBuffer);
	vao.vertexBuffer = newBuffer;
	glBindBuffer(GL_ARRAY_BUFFER, vao.vertexBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vao.totalVertices, sizeof(GLfloat) * vertexCount, (GLvoid*)vertexData);

	switch (vao.vertexLayout) {
	case Renderer_GL::VAO_GL::V2: {
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		break;
	}
	case Renderer_GL::VAO_GL::V2_V2: {
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		break;
	}
	case Renderer_GL::VAO_GL::V2_V2_V2: {
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(4 * sizeof(GLfloat)));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		break;
	}
	case Renderer_GL::VAO_GL::V3: {
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		break;
	}
	case Renderer_GL::VAO_GL::V3_V2: {
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		break;
	}
	case Renderer_GL::VAO_GL::V3_V3: {
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		break;
	}
	case Renderer_GL::VAO_GL::V3_V3_V2: {
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		break;
	}
	}

	glGenBuffers(1, &newBuffer);
	glBindBuffer(GL_COPY_WRITE_BUFFER, newBuffer);
	glBindBuffer(GL_COPY_READ_BUFFER, vao.elementBuffer);
	glBufferData(GL_COPY_WRITE_BUFFER, sizeof(GLushort) * (vao.totalElements + elementCount), NULL, GL_STATIC_DRAW);
	glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, sizeof(GLushort) * vao.totalElements);
	glDeleteBuffers(1, &vao.elementBuffer);
	vao.elementBuffer = newBuffer;

	switch (vao.elementDataSize) {
	case GL_UNSIGNED_BYTE: {
		GLubyte* elm = (GLubyte*)elementData;
		for (int i = 0; i < elementCount; i++) {
			elm[i] += vao.totalVertices;
		}
	}
	case GL_UNSIGNED_SHORT: {
		GLushort* elm = (GLushort*)elementData;
		for (int i = 0; i < elementCount; i++) {
			elm[i] += vao.totalVertices;
		}
	}
	case GL_UNSIGNED_INT: {
		GLuint* elm = (GLuint*)elementData;
		for (int i = 0; i < elementCount; i++) {
			elm[i] += vao.totalVertices;
		}
	}
	}
	GLushort* elm = (GLushort*)elementData;
	for (int i = 0; i < elementCount; i++) {
		elm[i] += vao.totalVertices;
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vao.elementBuffer);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * vao.totalElements, sizeof(GLushort) * elementCount, (GLvoid*)elementData);

	vao.totalVertices += vertexCount;
	vao.totalElements += elementCount;
}

void Renderer_GL::deleteVAO(VAO_GL& vao){
	glDeleteBuffers(1, &vao.vertexBuffer);
	glDeleteBuffers(1, &vao.elementBuffer);
	glDeleteVertexArrays(1, &vao.id);
	
}

Renderer_GL::VAO_GL Renderer_GL::createVAO(unsigned int vertexLayout, unsigned int elementDataSize)
{
	VAO_GL vao;
	glGenVertexArrays(1, &vao.id);
	glGenBuffers(1, &vao.vertexBuffer);
	glGenBuffers(1, &vao.elementBuffer);
	vao.elementDataSize = elementDataSize;
	vao.vertexLayout = vertexLayout;
	
	return vao;
}

void Renderer_GL::initialize() {
	const GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		cout << "GLEW Error: " << glewGetErrorString(err) << endl;
		exit(1);
	}
}

Renderer_GL::Renderer_GL() {
	initialize();
	
}