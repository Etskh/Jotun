#!/usr/bin/python
import os
import platform
import fnmatch





class JotunBuild:

	def __init__(self, name):
		self.name = name
		self.env = Environment(CC='clang', CXX='clang', LINK='clang')
		self.env.Append(CPPFLAGS=['-std=c++0x','-Werror','-Wall'])
		self.env.Append(LIBS=['stdc++'])
		# SDL
		# self.env.Append(LIBS=['SDL2'])
		self.objs = []
		
	def getBuildPath(self):
		return './build/'+platform.system()+'/'+self.name+'/'
		
	def getTempPath(self):
		return self.getBuildPath()+'tmp/'

	def getSrcPath(self):
		return './src/'

	def getSources(self):
		size = 0
		matches = []
		for root, dirnames, filenames in os.walk( self.getSrcPath() ):
			for filename in fnmatch.filter(filenames, '*.cpp'):
				matches.append(os.path.join(root, filename))
				size = size + os.path.getsize(os.path.join(root, filename))

		return matches

	def build(self):
		VariantDir(self.getBuildPath(), self.getSrcPath())
		for source in self.getSources():
			obj_filename = os.path.splitext(source)[0]
			self.objs.append( self.env.Object(self.getTempPath() +
				obj_filename, source=source) )

		self.env.Program( target=self.getBuildPath()+'jotun', source=self.objs)
		

class DebugBuild(JotunBuild):
	def __init__(self):
		JotunBuild.__init__(self,'debug')
		self.env.Append(CPPFLAGS=['-g','-O0'])
		self.env.Append(CPPDEFINES=['DEBUG'])
		
class ProfileBuild(JotunBuild):
	def __init__(self):
		JotunBuild.__init__(self,'profile')
		self.env.Append(CPPFLAGS=['-g'])
		self.env.Append(CPPFLAGS=['-O3'])

class ReleaseBuild(JotunBuild):
	def __init__(self):
		JotunBuild.__init__(self,'release')
		self.env.Append(CPPFLAGS=['-O3'])

	
#
# Create the build objects
#
builds = []


if( 'all' == ARGUMENTS.get('target', 'all') ):
	builds += [
		DebugBuild(),
		ProfileBuild(),
		ReleaseBuild()
	]
elif( 'debug' == ARGUMENTS.get('target', 'all') ):
	builds.append( DebugBuild() )
elif( 'profile' == ARGUMENTS.get('target', 'all') ):
	builds.append( ProfileBuild() )
elif( 'release' == ARGUMENTS.get('target', 'all') ):
	builds.append( ReleaseBuild() )
	
	
for build in builds:
	build.build()

	
