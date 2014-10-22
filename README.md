Jotun (0.0.x)
=====

A redux of a module-based framework that compiles on Linux ( tested on Ubuntu ), and MacOSX (tested on Mountain Lion), and probably Windows ( untested, but I'm a Windows programmer, so it's a good guess). Plans to support mobile aren't being developed, but isn't not on my mind.

##Building
For just testing the framework, I've not bothered to make the executable a different project (yet) so everything just builds into an executable in one step. It uses the SCons build tool - but just one file, and to compensate for not having SConscript files scattered through the source, there is a lot of python (relatively) in the SConstruct file. A simple build can obviouly be invoked by:
```
scons
```
...but that will build everything. Terrible. I've made three types of builds: `debug` which has debug symbols, the DEBUG define, and no optimisation; `profile` which is a more lean version of the debug build; and `release` which does heavy code optimisation and strips unneeded symbols. Each build can be invoked by adding `target=[build]` to the end of the scons command, where build is one of: debug, profile, or release. We can also add all the scons flags we want.
```
scons -Q -j4 target=debug
```
That will build it lightening fast - and only the debug. To run it, right now, you need to invoke the run manually. Hopefully it won't be the case for <a target="_blank" href="https://github.com/Etskh/Jotun/issues/2">the future</a>.


##Systems
The main driving agent of the modules is the systems. Each system is created for a specific Application class. Every application can only have one system per type of system.

###Gfx
The Gfx system needs a `Device::Handle` to initialize. It's the window, effectively. Some work will need to go into making it less dependant on the physical window, and more on the graphics device. So if a designer wants a secondary window, it wouldn't need a whole new openGL context (and the resources could be shared).

The Gfx is simply an interface for Scenes which then in turn, create SceneNodes. These scene-nodes are filled up and maintained by the driver code - and managed by the SceneGraph. The drivers ask for their own `Mesh::Handle`s and `Material::Handle`s through the Mesh and Material interfaces. The sceneNodes take these and create `MeshContext::Handle`s and `MaterialContext::Handle`s - and these are what the graphics loop will manage and iterate over.


###GUI
The GUI uses an attribute-based system that is even more loose than something that is checked at compile-time like other template-systems. This is so it is very flexible, debuggable, and scriptable. The goal here was to create a GUI interface that was robust and powerful, but could get something showing with little code.

##Core
I've been working on this core library for some time. Most of the cooler stuff in there (like aligned, templatised strings) is hidden away basically without comments… but I hope to rectify that soon.


