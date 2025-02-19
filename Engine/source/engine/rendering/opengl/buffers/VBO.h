#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>

namespace Engine {
	class VBO {
	public:
		unsigned int  ID;
		VBO(float* vertices, size_t size);
		void Bind();
		void Unbind();
		void Delete();

	private:
	};
}

#endif // !VBO_CLASS_H
