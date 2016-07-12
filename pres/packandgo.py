from sys import argv
import os
from HTMLParser import HTMLParser
from shutil import copy, copytree

script, filename = argv

assets = []

# create a subclass and override the handler methods
class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
    	if (tag == 'section'):
    		for i in range(len(attrs)):
    			if (attrs[i][0] == "data-background-image"):
    				print attrs[i][1]
    				assets.append(attrs[i][1])
    			elif (attrs[i][0] == "data-background-video"):
    				print attrs[i][1]
    				assets.append(attrs[i][1])
    	if (tag == 'img'):
    		for i in range(len(attrs)):
    			if (attrs[i][0] == "src"):
    				print attrs[i][1]
    				assets.append(attrs[i][1])
    	if (tag == 'video'):
    		for i in range(len(attrs)):
    			if (attrs[i][0] == "src"):
    				print attrs[i][1]
    				assets.append(attrs[i][1])

def exists(array,value):
	for i in range(len(array)):
		if (array[i] == value):
			return True
	return False

txt = open(filename)

print "These are the assets for %r:" % filename
parser = MyHTMLParser()
parser.feed(txt.read())

directory = "%s_pack" % filename.split('.')[0]

print "COPYING FILES into %s" % directory
folders = []
for i in range(len(assets)):
	tmp = assets[i].split('/')
	# print tmp
	for j in range(len(tmp)-1):
		if not (exists(folders,tmp[j])):
			folder = "/".join(tmp[0:len(tmp)-1])
			if not os.path.exists("%s/%s" % (directory,folder)):
				# print "Making directory: '%s/%s'" % (directory, folder)
				os.makedirs("%s/%s" % (directory, folder))
	copy(assets[i],"%s/%s/" % (directory,folder))

copy(filename,directory)
if not os.path.exists("%s/css" % directory):
	copytree('css',"%s/css" % directory)
if not os.path.exists("%s/js" % directory):
	copytree('js',"%s/js" % directory)
if not os.path.exists("%s/lib" % directory):
	copytree('lib',"%s/lib" % directory)
if not os.path.exists("%s/plugin" % directory):
	copytree('plugin',"%s/plugin" % directory)

print "success!"