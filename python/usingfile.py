#!/usr/bin/python
# Filename : using_file.py

pome = '''\
	   Programming is fun
	   When the work is done
	   if you wanna make your work
				use Python!
'''
fp = file('pome.txt', 'w')
fp.write(pome)
fp.close()

fp = file('pome.txt')
while True:
	line = fp.readline()
	if len(line) == 0:
		break
	print line,
fp.close()
