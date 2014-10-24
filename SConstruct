#!/usr/bin/python
import os
import platform
import fnmatch
import atexit	# for running build.run on exit
import subprocess # for actually running the build



class JotunBuild:

	program_name = 'jotun'
	libs = [
		'stdc++'
	]

	def __init__(self, name):
		self.name = name
		self.env = Environment(CC='clang', CXX='clang', LINK='clang')
		self.env.Append(CPPFLAGS=['-std=c++0x','-Werror','-Wall','-ferror-limit=2'])
		self.env.Append(CPPPATH=[ self.getSrcPath() ])
		self.env.Append(LIBS=self.libs)
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
		
		if	( platform.system() == "Darwin"):
			self.env.Append(LINKFLAGS='-framework SDL2 -F/Library/Frameworks/SDL2.framework/')
		else:
			self.libs.append('SDL2')
		
		self.env.Program( target=self.getBuildPath()+self.program_name, source=self.objs)
		
	def run(self):
		os.chdir( self.getBuildPath() )
		if( os.path.isfile( self.program_name )):
			subprocess.call ([ './'+self.program_name ])
		else:
			print("Something went wrong.")
				

class DebugBuild(JotunBuild):
	def __init__(self):
		JotunBuild.__init__(self,'debug')
		self.env.Append(CPPFLAGS=['-g','-O0'])
		self.env.Append(CPPDEFINES=['DEBUG'])
		
		
class ProfileBuild(JotunBuild):
	def __init__(self):
		JotunBuild.__init__(self,'profile')
		self.env.Append(CPPFLAGS=['-g', '-O3'])
		self.env.Append(CPPDEFINES=['DEBUG'])

class ReleaseBuild(JotunBuild):
	def __init__(self):
		JotunBuild.__init__(self,'release')
		self.env.Append(CPPFLAGS=['-O3'])

	
#
# Create the build objects
#
builds = []

target = ARGUMENTS.get('target', 'all')
if( 'all' == target ):
	builds += [
		DebugBuild(),
		ProfileBuild(),
		ReleaseBuild()
	]
elif( 'debug' == target ):
	builds.append( DebugBuild() )
elif( 'profile' == target ):
	builds.append( ProfileBuild() )
elif( 'release' == target ):
	builds.append( ReleaseBuild() )
else:
	print("warning: Unknown target '"+ target + "'")

runme = ARGUMENTS.get('run', 'false')
if( 'true' == runme ):
	if( len(builds)==1 ):
		atexit.register( builds[0].run )
	else:
		print("warning: Cannot run - target not specific")
	


for build in builds:
	build.build()

