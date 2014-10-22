Jotun
=====

A redux of a module-based framework that compiles on Linux ( tested on Ubuntu ), and MacOSX (tested on Mountain Lion), and probably Windows ( untested, but I'm a Windows programmer, so it's a good guess). Plans to support mobile aren't being developed, but isn't not on my mind.

Systems
====
The main driving agent of the modules is the systems. Each system is created for a specific Application class. Every application can only have one system per type of system.

Gfx
===
The Gfx system needs a `Device::Handle` to initialize. It's the window, effectively. Some work will need to go into making it less dependant on the physical window, and more on the graphics device. So if a designer wants a secondary window, it wouldn't need a whole new openGL context (and the resources could be shared).

The Gfx is simply an interface for Scenes which then in turn, create SceneNodes. These scene-nodes are filled up and maintained by the driver code - and managed by the SceneGraph. The drivers ask for their own Mesh::Handles and Material::Handles through the Mesh and Material interfaces. The sceneNodes take these and create MeshContext::Handles and MaterialContext::Handles - and these are what the graphics loop will manage and iterate over.


GUI
===
The GUI uses an attribute-based system that is even more loose than something that is checked at compile-time like other template-systems. This is so it is very flexible, debuggable, and scriptable. The goal here was to create a GUI interface that was robust and powerful, but could get something showing with little code.

Core
===
I've been working on this core library for some time. Most of the cooler stuff in there (like aligned, templatised strings) is hidden away basically without comments… but I hope to rectify that soon.


