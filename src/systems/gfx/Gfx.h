#pragma once


// NOTHING IN PARTICULAR
//
#include <stdio.h> // for printf
#include <memory> // for shared_ptr
#include <string> // for std::string
#include <vector> // for std::vector

#include "core/Assert.h"
#include "core/math/Vector.h"
#include "core/math/Matrix.h"

/*
// BASE CORE LIB
//
#include <assert.h> // for assert
#define ASSERT assert
#define NOT_IMPLEMENTED false
#define OUT
typedef unsigned int uint;
namespace math {
	struct Vector2 {
		float m[2];
	};
	struct Vector3 {
		float m[3];
	};
	struct Matrix4 {
		float m[16];
	};
} // namespace math
namespace core {
	struct Colour {
		float d[4];
	};
} // namespace core
*/




#include "Texture.h"
#include "Parameter.h"
#include "Shader.h"
#include "Material.h"
#include "Mesh.h"
#include "MaterialContext.h"
#include "MeshContext.h"

#include "scene/SceneNode.h"
#include "scene/CameraNode.h"
#include "scene/StaticMeshNode.h"

#include "scene/Scene.h"


