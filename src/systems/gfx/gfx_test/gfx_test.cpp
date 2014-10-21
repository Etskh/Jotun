
#include "../Gfx.h"




int main( int argc, char* argv[] )
{
	printf(" -|- Kangaroo -|-\n");

	std::string vertexProg = "\
		#version 140\
		uniform Transformation {\
			mat4 projection_matrix;\
			mat4 modelview_matrix;\
		};\
		in vec3 vertex;\
		void main(void) {\
			gl_Position = projection_matrix * modelview_matrix * vec4(vertex, 1.0);\
		}";

	std::string fragmentProg = "\
		#version 120\
		void main(void) {\
			gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\
		}";

	//
	// Variable decl
	//
	Mesh::Handle defaultMesh;
	Shader::Handle defaultVertexShader;
	Shader::Handle defaultFragmentShader;
	Texture::Handle defaultDiffuseTexture1;
	Texture::Handle defaultDiffuseTexture2;
	Material::Handle defaultMaterial;
	StaticMeshNode::Handle sceneNode;
	CameraNode::Handle camera;
	
	//
	// Create some default stuff
	//
	defaultMesh = Mesh::CreateEmpty("default mesh");
	defaultVertexShader = Shader::CreateFromData("default vertex", vertexProg.c_str(), vertexProg.size() );
	defaultVertexShader->setProjectionMatrix("projection_matrix" );
	defaultVertexShader->setWorldViewMatrix("modelview_matrix" );
	
	defaultFragmentShader = Shader::CreateFromData("default fragment", fragmentProg.c_str(), fragmentProg.size() );
	defaultDiffuseTexture1 = Texture::CreateEmpty("default diffuse 1");
	defaultDiffuseTexture2 = Texture::CreateEmpty("default diffuse 2");
	defaultMaterial = Material::Create( "default material", defaultVertexShader, defaultFragmentShader );

	//
	// Create our scene
	//
	Scene::Handle scene = Scene::CreateBasicScene();
	
	//
	// Create a camera, and two static meshes
	//
	camera = scene->CreateCamera("main_camera");
	
	sceneNode = scene->CreateStaticMeshNode( "myFirstNode", defaultMesh, defaultMaterial );
	sceneNode->materialContext()->SetValue( "diffuse", defaultDiffuseTexture1 );
	
	sceneNode = scene->CreateStaticMeshNode( "clonedNode", defaultMesh, defaultMaterial );
	sceneNode->materialContext()->SetValue( "diffuse", defaultDiffuseTexture2 );
	
	//
	// Now "render" everything
	//
	uint times = 1;
	while( times-- ) {

		printf("Rendering...\n");
		
		scene->Render();
		
	}
	
	return 0;
}